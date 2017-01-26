#include <cstdio>
#include <cstdlib>
#include "rand.h"

char res[100500];

int main(int argc,char*argv[])
{
	if(argc>1)
		z_srand(atoi(argv[1]));
	int n = 100000;
	for(int i = 0; i < n; i++)
	{
		int k = rand(0, 25);
		res[i] = k + 'a';
	}
	printf("%s\n", res);
	return 0;
}