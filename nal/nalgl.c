#include <stdlib.h>
#include <stdio.h>

size_t nalread(char** in, size_t* len, FILE* input)
{
	ssize_t read;

	read=getline(in, len, input);
	return read;
}
