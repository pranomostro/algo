#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "findtest.h"

size_t ifind2(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0||data[0]>=key)
		return 0;
	else if(data[len-1]<=key)
		return len;

	size_t low=0, mid, high=len-1;

	while(low<high)
	{
		mid=ceil(((double)key-data[low])/((double)data[high]-data[low])*((double)high-low))+low;

		if(data[mid]>=key&&data[mid-1]<=key)
			return mid;
		else if(data[mid]<key)
			low=mid;
		else
			high=mid-1;
	}

	return high;
}
