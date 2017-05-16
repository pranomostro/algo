#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

#define MIDCALC ((float)key-data[low])/((float)data[high]-data[low])*(double)(high-low)+low

size_t ifind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len<=0||key<=data[0])
		return 0;
	else if(key>data[len-1])
		return len;

	size_t low, high, mid;
	low=0;
	high=len-1;
	mid=midcalc(data, key, high, low);

	while(low<=high&&data[mid]!=key)
	{
		if(data[low]>key)
		{
			mid=low-1;
			break;
		}
		else if(data[high]<key)
		{
			mid=high+1;
			break;
		}

		mid=midcalc(data, key, high, low);
		if(data[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	return data[mid]<key?mid+1:mid;
}
