#include <stdlib.h>
#include <stdint.h>

#include "findtest.h"

size_t ffind1(uint32_t key, uint32_t* data, size_t len)
{
	if(len==0||data[0]>=key)
		return 0;
	else if(data[len-1]<=key)
		return len;

	size_t low=0, high=len-1, mid, est, up, down;

	while(1)
	{
		if(low>0&&data[low]>=key&&data[low-1]<=key)
			return low;
		mid=(low+high)/2;
		if(mid>0&&data[mid]>=key&&data[mid-1]<=key)
			return mid;
		est=midcalc(key, data, high, low);
		if(est>0&&data[est]>=key&&data[est-1]<=key)
			return est;

		if(mid>=est)
			up=mid, down=est;
		else
			up=est, down=mid;

		if(data[down]>key)
			high=down-1;
		else if(data[up]<key)
			low=up+1;
		else
			low=down+1, high=up-1;
	}
}
