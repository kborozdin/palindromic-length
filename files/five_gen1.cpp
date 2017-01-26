#include "rand.h"
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

char s[100500];

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int flag = atoi(argv[2]);
	int seed = atoi(argv[3]);

	z_srand(seed);

	int prv = 0;
	for (int i = 4; i >= 0; --i)
	{
		int n1 = rand(prv + 1, n - i);
//		cerr << n1 << endl;
//		return 0;
		if (i == 0)
			n1 = n;
		for (int j = prv; j < (prv + n1 + 1)/2; ++j)
			s[j] = s[n1 - (j - prv) - 1] = j%26 + 'a';
		prv = n1;
	}
	if (flag == 1)
		reverse(s, s + n);
	s[n] = 0;
	printf("%s\n", s);

    return 0;
}
