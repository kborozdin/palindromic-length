#include <cstdio>
#include <cstdlib>
#include "rand.h"


int main(int argc, char*argv[])
{
	if(argc > 1)
		z_srand(atoi(argv[1]) );
	int n = 0;
	if (argc > 2)
		n = atoi(argv[2] );
	char a = rand(0, 'z' - 'a') + 'a', b = a;
	while (b == a)
	{
		b = rand(0, 'z' - 'a') + 'a';
	}

	int cur = 0;

	int x = 0;
	while (true)
	{
		if (cur == n)
			break;
		for (int i = 31; i >= 0; i--)
		{
			if (cur == n)
				break;
			if ( (1 << i) > x)
				continue;
			if ( (1 << i) & x)
				printf("%c", a);
			else
				printf("%c", b);
			cur++;
		}
		x++;
	}

	printf("\n");
	return 0;
}







