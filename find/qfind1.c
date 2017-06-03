#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "findtest.h"

size_t qfind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0||data[0]>=key)
		return 0;
	else if(data[len-1]<=key)
		return len;

	size_t step=sqrt(len), low, high;

	for(low=0, high=step; high<len&&data[high]<key; low=high, high+=step);
	high=high<len?high:len-1;
	return low+ifind1(key, data+low, high-low);
}
