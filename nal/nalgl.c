#include <stdlib.h>
#include <stdio.h>

char* nalread(char* in, size_t* len, FILE* input)
{
	ssize_t read;

	read=getline(&in, len, input);
	if(read<=0)
	{
		free(in);
		return NULL;
	}
	return in;
}
