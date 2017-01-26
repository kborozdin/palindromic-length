#define _CRT_SECURE_NO_WARNINGS
#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);

	string a = "a", b = "b";
	while (b.length() < n)
	{
		string c = a + b;
		a = b;
		b = c;
	}

	b = b.substr(0, n);
	cout << b << endl;

	return 0;
}