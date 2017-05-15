#include <stdlib.h>
#include <stdint.h>

size_t midcalc(uint32_t* data, uint32_t key, size_t high, size_t low)
{
	return ((float)key-data[low])/((float)data[high]-data[low])*(double)(high-low)+low;
}
