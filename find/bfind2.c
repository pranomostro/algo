#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

size_t bfind2(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0)
		return 0;

	int low=0, high=len-1, mid;
	mid=low;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(data[mid]<key)
			low=mid+1;
		else if(data[mid]==key)
			return mid;
		else
			high=mid-1;
	}
	return (data[mid]<key)?mid+1:mid;
}
