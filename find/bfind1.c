#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

size_t bfind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0)
		return 0;

	signed int low=0, high=len-1, mid;
	mid=(low+high)/2;

	while(low<=high&&data[mid]!=key)
	{
		mid=(low+high)/2;
		if(data[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	return data[mid]<key?mid+1:mid;
}
