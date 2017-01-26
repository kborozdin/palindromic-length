#include "rand.h"
#include <cstdio>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc != 3)
        throw "you have to pass exactly 3 params";
    int seed = atoi(argv[1]);
    int n = atoi(argv[2]);
	if (n < 25 || n > 100000)
        throw "param has to satisfy the following requirement 25 <= N <= 100000";
    z_srand(seed);

	int charArr[2];
	charArr[0] = 'a' + rand(0, 25);
	charArr[1] = 'a' + rand(0, 25);
	
	char lstChr = charArr[rand(0, 1)];
    for (int i = 0; i < 5; i++)
	{
		int len = rand(5, n - 5 * (4 - i));
		n -= len;
		int beg = (lstChr == charArr[0] ? 0 : 1);
		for (int j = 0; j < len; j++)
		{
			char chr = charArr[(beg + j % 2) % 2];
			lstChr = chr;
			putchar(chr);
		}
	}
	putchar('\n');

    return 0;
}
