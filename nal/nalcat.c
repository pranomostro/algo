#include <stdlib.h>
#include <stdio.h>

#include "nal.h"

const size_t INITLEN=8192;

int main(void)
{
	size_t len=INITLEN;
	char* s=calloc(len, sizeof(char)), * rp;

	while((rp=nalread(s, &len, stdin))!=NULL)
	{
		s=rp;
		fputs(s, stdout);
	}
	free(s);
	return 0;
}
