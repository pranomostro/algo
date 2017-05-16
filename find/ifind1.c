#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

size_t ifind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0||data[0]>=key)
		return 0;
	else if(data[len-1]<=key)
		return len;

	size_t low=0, high=len-1, mid=midcalc(key, data, len-1, 0);

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

		mid=midcalc(key, data, high, low);
		if(data[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	return data[mid]<key?mid+1:mid;
}
