#include <stdlib.h>
#include <stdio.h>

#include "nal.h"

const size_t INITLEN=8192;

int main(void)
{
	size_t len=INITLEN;
	char* s=calloc(len, sizeof(char));

	while((s=nalread(s, &len, stdin))!=NULL)
		printf(s);
	free(s);
	return 0;
}
