#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>

#include "nal.h"

char* nalread(char* in, size_t* len, FILE* input)
{
	char c=0;
	int handle=fileno(input);
	size_t count=0;

	read(handle, &c, sizeof(char));

	while(c!=0&&c!=-1)
	{
		if(count>=*(len)-3)
		{
			in=(char*)reallocarray(in, sizeof(char)*(*len*2), sizeof(*in));
			if(in==NULL)
				return in;
			(*len)*=2;
		}
		in[count++]=c;
		if(c=='\n')
			break;
		read(handle, &c, sizeof(char));
	}

	in[count]='\0';

	return (c!=0&&c!=-1)?in:NULL;
}
