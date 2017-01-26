#include <cstdio>
#include <cstdlib>
#include "rand.h"

const int N = 1000000;

char res[N];


int main(int argc,char*argv[])
{
	if(argc>1)
		z_srand(atoi(argv[1]));
	int n = 1250000 / 5 - 1;
	for(int i = 0; i < n; i++)
	{
		res[i] = 'b';
	}
	for(int i = n - 1; i >= 0; i--)
	{
		res[n++] = res[i];
	}
	for(int i = 0; i < n; i++)
	{
		printf("a%c", res[i]);
	}
	printf("a\n");
}