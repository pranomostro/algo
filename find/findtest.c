#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "findtest.h"

#define LEN(x) (sizeof (x) / sizeof *(x))
#define ROUNDS 4096

void measure_runtime(uint32_t* data, size_t len, size_t inc, size_t funcpos);
void check_result(uint32_t* data, uint32_t key, size_t len, size_t res);

typedef struct
{
	size_t len, maxinc;
} Findtest;

typedef struct
{
	size_t (*find)(uint32_t key, uint32_t* data, size_t len);
	const char* name, * desc;
} Findfunc;

Findtest tests[]=
{
	{ .len=1,	.maxinc=1<<28	},
	{ .len=2,	.maxinc=1<<28	},
	{ .len=3,	.maxinc=1<<28	},
	{ .len=4,	.maxinc=1<<28	},
	{ .len=1<<4,	.maxinc=1<<28	},
	{ .len=1<<8,	.maxinc=1<<24	},
	{ .len=1<<12,	.maxinc=1<<20	},
	{ .len=1<<16,	.maxinc=1<<16	},
	{ .len=1<<20,	.maxinc=1<<12	},
	{ .len=1<<24,	.maxinc=1<<8	},
	{ .len=1<<28,	.maxinc=1<<4	}
};

Findfunc funcs[]=
{
	{ .find=bfind,	.name="bfind",	.desc="binary find"		},
	{ .find=efind1,	.name="efind1",	.desc="estimating find 1"	},
	{ .find=ifind1,	.name="ifind1",	.desc="interpolating find 1"	},
	{ .find=lfind,	.name="lfind",	.desc="linear find"		}
};

int measuretime(uint32_t* data, size_t len, size_t inc, size_t funcpos)
{
	int acc, i;
	size_t res;
	clock_t c1, c2;
	uint32_t key;

	acc=0;

	printf("%s (len: %lu, inc: %lu): ", funcs[funcpos].name, len, inc);

	for(i=0; i<ROUNDS; i++)
	{
		key=rand()%(len*inc);
		c1=clock();
		res=funcs[funcpos].find(key, data, len);
		c2=clock();
		acc+=c2-c1;

		check_result(data, key, len, res);
	}
	printf("%d clocks for %d rounds (%f clocks per round)\n",
		acc, ROUNDS, (float)acc/(float)ROUNDS);
	return acc;
}

void check_result(uint32_t* data, uint32_t key, size_t len, size_t res)
{
	/* check if the result is correct */
	if(len<=2)
	{
		if((res==0&&data[res]<key)||
		   (res==len&&data[len-1]>key)||
		   (len>1&&(res<len&&(data[res]<key||data[res-1]>key))))
		{
			fprintf(stderr, "key: %d, res: %lu, len: %lu, data[0]: %d",
				key, res, len, data[0]);
			if(len>1)
				fprintf(stderr, " data[1]: %d", data[1]);
			fprintf(stderr, ", exiting\n");
			exit(1);
		}
	}
	else
	{
		if(res==0&&data[res]<key)
		{
			fprintf(stderr, "key: %d, res: %lu, len: %lu, data[0]: %d, data[1]: %d, exiting\n",
				key, res, len, data[0], data[1]);
			exit(2);
		}
		else if((res==len&&data[len-1]>key)||
			(res==len-1&&data[len-2]>key))
		{
			fprintf(stderr, "key: %d, res: %lu, len: %lu, data[%lu]: %d, data[%lu]: %d, exiting\n",
				key, res, len, len-1, data[len-1], len-2, data[len-2]);
			exit(3);
		}
		else if((res>0&&res<len-1)&&
			(data[res]<key||data[res-1]>key))
		{
			fprintf(stderr, "key: %d, res: %lu, len: %lu, data[%lu]: %d, data[%lu]: %d, data[%lu]: %d, exiting\n",
				key, res, len, res-1, data[res-1], res, data[res], res+1, data[res+1]);
			exit(4);
		}
	}
}

int main(void)
{
	int total;
	size_t i, j, k, n, inc;
	uint32_t* data=calloc(tests[LEN(tests)-1].len+1, sizeof(uint32_t));

	srand((unsigned)time(NULL));

	for(i=0; i<LEN(funcs); i++)
	{
		total=0;
		for(j=0; j<LEN(tests); j++)
			for(inc=tests[j].maxinc; inc>1; inc>>=4)
			{
				for(n=rand()%inc, k=0; k<tests[j].len; k++, n+=rand()%inc)
					data[k]=n;
				total+=measuretime(data, tests[j].len, inc, i);
			}
		printf("%s needed %d rounds total\n", funcs[i].name, total);
	}
	free(data);

	return 0;
}
