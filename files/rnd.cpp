#include "rand.h"
#include <cstdio>
#include <algorithm>


int main(int argc, char *argv[])
{
	int n = rand(1, 1000);
	for(int i = 0; i < n; i++)
	{
		printf("%c", 'a' + rand(0, 25));
	}
	printf("\n");
    return 0;
}
