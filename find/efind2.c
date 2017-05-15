#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "findtest.h"

size_t efind2(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0||data[0]>=key)
		return 0;
	else if(data[len-1]<key)
		return len;
	size_t d, mid=midcalc(data, key, len-1, 01);
	for(d=(data[mid]<key?1:-1); !(data[mid]>=key&&data[mid-1]<key); mid+=d);
	return mid;
}
