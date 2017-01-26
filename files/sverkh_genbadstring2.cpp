#include <cstdio>
#include <cstdlib>
#include "rand.h"

char res[100500];

int main(int argc,char*argv[])
{
	if(argc>1)
		z_srand(atoi(argv[1]));
	int B = 223;
	for(int i = 0; i < B; i++)
	{
		int k = rand(1, 25);
		for(int _ = 0; _ < 2; _++)
		{
			printf("%c", 'a' + k);
			for(int i = 0; i < B; i++)
			{
				printf("a");
			}
		}
	}
	puts("");
	return 0;
}