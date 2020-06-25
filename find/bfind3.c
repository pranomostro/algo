#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

static int cmpint32(const void* v1, const void* v2)
{
	uint32_t val1=*((uint32_t*) v1), val2=*((uint32_t*) v2);
	if(val1<val2)
		return -1;
	else if(val2>val1)
		return 1;
	return 0;
}

size_t bfind3(uint32_t key, uint32_t* data, size_t len)
{
	uint32_t* location=bsearch(&key, data, len, sizeof(uint32_t), cmpint32);
	if(location)
		return (size_t)(location-data)/sizeof(uint32_t);
	if(len==0||data[0]>=key)
		return 0;
	return len;
}
