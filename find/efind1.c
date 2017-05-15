#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "findtest.h"

size_t efind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len<=0||data[0]>=key)
		return 0;
	else if(data[len-1]<key)
		return len;

	size_t mid, dir;

	mid=midcalc(data, key, len-1, 0);

	if(data[mid]<key)
		dir=1;
	else
		dir=-1;

	while(!(data[mid]>=key&&data[mid-1]<key))
		mid+=dir;

	return mid;
}
