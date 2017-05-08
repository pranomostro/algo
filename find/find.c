#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "find.h"

#define LEN(x) (sizeof (x) / sizeof *(x))
#define ROUNDS 2

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
	{ .find=ifind1,	.name="ifind1",	.desc="interpolating find 1"	}
};

int main(void)
{
	size_t i, j, k, l, n, inc, res, acc;
	clock_t t1, t2;
	uint32_t key;
	uint32_t* data=calloc(tests[LEN(tests)-1].len, sizeof(uint32_t));

	srand((unsigned)time(NULL));

	for(i=0; i<LEN(funcs); i++)
		for(j=0; j<LEN(tests); j++)
			for(inc=tests[j].maxinc; inc>1; inc>>=4)
			{
				for(n=rand()%inc, k=0; k<tests[j].len; k++, n+=rand()%inc)
					data[k]=n;
				acc=0;
				for(l=0; l<ROUNDS; l++)
				{
					key=rand()%(tests[j].len*inc);
					t1=clock();
					res=funcs[i].find(key, data, tests[j].len);
					t2=clock();
					acc+=t2-t1;

					if(res==0&&data[0]<key)
					{
						fprintf(stderr, "key: %d, res: 0, data[0]: %d, data[1]: %d\n", key, data[0], data[1]);
						exit(1);
					}
					else if((res==tests[j].len||res==tests[j].len-1)&&data[tests[j].len-1]>key)
					{
						fprintf(stderr, "key: %d, res: %lu, data[%lu]: %d, data[%lu]: %d\n",
						key, res, tests[j].len-2, data[tests[j].len-2], tests[j].len-1,
						data[tests[j].len-1]);
						exit(2);
					}
					else if(data[res]<key||data[res-1]>key)
					{
						fprintf(stderr, "key: %d, res: %lu, data[%lu]: %d, data[%lu]: %d, data[%lu]: %d\n",
						key, res, res-1, data[res-1], res, data[res], res+1, data[res+1]);
						exit(3);
					}
				}
				printf("%s (len: %lu, inc: %lu) needed %lu clocks for %d rounds\n",
					funcs[i].name, tests[j].len, inc, acc, ROUNDS);

			}
	free(data);

	return 0;
}
