#include <stdlib.h>
#include <stdint.h>

size_t bfind(uint32_t key, uint32_t* data, size_t len)
{
	size_t low, high, mid;
	low=0;
	high=len-1;
	mid=(low+high)/2;

	if(len<=0)
		return 0;

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
