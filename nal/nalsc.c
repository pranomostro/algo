#include <stdio.h>

#include "nal.h"

char* nalread(char* in, size_t* len, FILE* input)
{
	char c;
	size_t count=0;

	c=getc(input);

	while(c!='\n'&&!feof(input))
	{
		if(count>=*(len)-3)
		{
			in=(char*)reallocarray(in, sizeof(char)*(*len*2), sizeof(*in));
			if(in==NULL)
				return in;
			(*len)*=2;
		}
		in[count++]=c;
		c=getc(input);
	}

	in[count++]='\n';
	in[count]='\0';

	return feof(input)?NULL:in;
}
