#include <stdio.h>
#include <string.h>

#include "nal.h"

char* nalread(char* in, size_t* len, FILE* input)
{
	size_t readlen=(*len-1)/2;
	char* readpos=in;

	while(1)
	{
		if(fgets(readpos, readlen, input)==NULL)
			break;
		if(readpos[strnlen(readpos, *len)-1]=='\n')
			break;
		in=(char*)resize(in, sizeof(char)*(*len), sizeof(char)*((*len)*2));
		(*len)*=2;
		readlen=(*len)-strnlen(in, *len)-1;
		readpos=in+strnlen(in, *len);
	}

	return feof(input)?NULL:in;
}