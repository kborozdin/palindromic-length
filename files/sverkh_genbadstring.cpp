#include <cstdio>
#include <cstdlib>
#include "rand.h"

char res[100500];


int main(int argc,char*argv[])
{
	if(argc>1)
		z_srand(atoi(argv[1]));
	int n = 24999;
	for(int i = 0; i < n; i++)
	{
		int k = rand(1, 25);
		res[i] = k + 'a';
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