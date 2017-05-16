#include <stdlib.h>
#include <stdint.h>

size_t midcalc(uint32_t key, uint32_t* data, size_t high, size_t low)
{
	if(data[high]==data[low])
		return low;
	float kld=key-data[low], hld=data[high]-data[low];
	double hl=high-low;
	return (kld/hld)*hl+low;
}
