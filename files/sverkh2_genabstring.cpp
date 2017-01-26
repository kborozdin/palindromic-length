#include <cstdio>
#include <cstdlib>
#include "rand.h"



int main(int argc, char*argv[])
{
	if(argc > 1)
		z_srand(atoi(argv[1]) );
	int n = 0, p = 0;
	if (argc > 2)
		n = atoi(argv[2] );
	if (argc > 3)
		p = atoi(argv[3] );
	char a = 'a', b = 'b'; 
	for (int i = 0; i < n; i++)
	{
		if (rand(1, 100) <= p)
			printf("%c", b);
		else
			printf("%c", a);
	}


	printf("\n");
	return 0;
}