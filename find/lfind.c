#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "findtest.h"

size_t lfind(uint32_t key, uint32_t* data, size_t len)
{
	size_t i;
	for(i=0; i<len&&data[i]<key; i++)
		;
	return i;
}
