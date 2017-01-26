#include "testlib.h"
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> getDivisors(int n)
{
	vector <int> divisors;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			divisors.push_back(i);
			if (n / i != i)
				divisors.push_back(n / i);
		}
	}
	return divisors;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
        printf("len seed\n");
		printf("Generate strings matched pattern 'aaa..acaaa..adaaa..ax....'\n");
        return 0;
	}
    int len = atoi(argv[1]);
    rnd.setSeed(atoi(argv[2]));

	vector <int> divisors = getDivisors(len + 1);
	if (divisors.size() == 0)
	{
		printf("(len + 1) must be composite number =)");
		return 0;
	}

	int d = divisors[rnd.next((int)divisors.size())];
	for (int i = 0; i < len; i++)
	{
		if (i % d == d - 1)
			putchar(rnd.next(1, 25) + 'a');
		else
			putchar('a');
	}
	puts("");
	return 0;
}
