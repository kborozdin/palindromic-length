#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char s[100500];

int __builtin_popcount(int n)
{
	int res = 0;
	for(int i = n; i > 0; i >>= 1)
	{
		res += (i & 1);
	}
	return res;
}

char a='a';
char b=1;

int main(int argc,char*argv[])
{
	if(argc>1){
		a=argv[1][0];
		if(argv[1][1])
			b=argv[1][1]-a;
	}
	int N = 100000;
	for (int i = 0; i < N; i++)
	{
		s[i] = a + (__builtin_popcount(i) % 2) * b; 
	}
	printf("%s\n", s);
	return 0;
}