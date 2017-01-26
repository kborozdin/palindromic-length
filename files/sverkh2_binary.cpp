#include <iostream>
#include <algorithm>
using namespace std;

bool bit(int a, int b)
{
 	return (a & (1 << b)) != 0;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	for (int i = 0; i < 4; i++)
	{
		if (bit(n, i)) putchar('b');
		else putchar('a');
	}

	putchar('\n');

	return 0;
}