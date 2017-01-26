#include "rand.h"
#include <cstdio>
#include <algorithm>

void abacaba(char c)
{
	if (c > 'a')
		abacaba(c - 1);
	printf("%c", c);
	if (c > 'a')
		abacaba(c - 1);
}

int main(int argc, char *argv[])
{
	abacaba('p');
	printf("\n");
    return 0;
}
