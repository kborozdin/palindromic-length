#include <cstdio>
#include <cstdlib>
#include "rand.h"

const int N = 1000000;

char res[N + 1];

int main(int argc,char*argv[])
{
	if(argc>1)
		z_srand(atoi(argv[1]));
	int n = N;
	for(int i = 0; i < n; i++)
	{
		int k = rand(0, 1);
		res[i] = k + 'a';
	}
	printf("%s\n", res);
	return 0;
}