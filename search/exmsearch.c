#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

const size_t LEN=16777216;
const int NOS=1048576;

size_t search(uint32_t key, uint32_t* data, size_t len);

int main(void)
{
	size_t i, pos;
	uint32_t acc;
	uint32_t* data=calloc(LEN, sizeof(uint32_t));

	srand((unsigned)time(NULL));

	for(i=0, acc=16; i<LEN; i++, acc+=rand()%4+1)
		data[i]=acc;

	for(i=0; i<NOS; i++)
	{
		acc=rand()%data[LEN-1];
		pos=search(acc, data, LEN);
		printf("%i %i %i %i %i\n", acc, data[pos-1], data[pos], data[pos+1], pos);
	}

	free(data);

	return 0;
}
