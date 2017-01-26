#include "rand.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

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
	
	int n = atoi(argv[1]);
	int seed = atoi(argv[2]);

	z_srand(seed);
	int sq = sqrt(n + 0.);
	vector<int> res;
	int S = 0;
	while(S < n - 3 * sq)
	{
		int x = sq + rand(-100, 100);
		res.push_back(x);
		S += x;
	}
	if(S > n) throw;
	res.push_back(n - S);
	int z = 0;
	for(int i = 0; i < res.size(); i++)
	{
		z += res[i];
		char c = 'a' + rand(0, 25);
		for(int j = 0; j < res[i]; j++)
		{
//			if(rand(0, 20) == 0)
//				printf("%c", rand(0, 25) + 'a');
//			else
				printf("%c", c);
		}
	}
	printf("\n");
	if(z != n) throw;
	return 0;
}
