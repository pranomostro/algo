#include <stdlib.h>
#include <stdio.h>

#include "nal.h"

const size_t INITLEN=5;

int main(void)
{
	size_t len=INITLEN;
	char* s=calloc(len, sizeof(char));

	while(nalread(&s, &len, stdin)>0&&!feof(stdin))
		fputs(s, stdout);

	free(s);
	return 0;
}
