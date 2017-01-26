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

    string s = "a";
    while ((int)s.length() < n)
    {
        int len = (int)s.length();
        for (int i = 0; i < len; i++)
            s += s[i] == 'a' ? 'b' : 'a';
    }

    cout << s.substr(0, n) << endl;

	return 0;
}
