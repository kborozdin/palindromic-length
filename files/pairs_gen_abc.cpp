#include "rand.h"
#include <cstdio>
#include <algorithm>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	for(int i = 0; i < n; i++)
	{
		printf("%c", i % 3 + 'a');
	}
	printf("\n");
	return 0;
}
