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
    while ((int)s.length() < n + 1)
    {
        int len = (int)s.length();
        for (int i = 0; i < len; i++)
            s += s[i] == 'a' ? 'b' : 'a';
    }
    s = s.substr(0, n + 1);

    string res;
    for (int i = 1; i < (int)s.length(); i++)
        res += (char)('b' + s[i] - s[i - 1]);
    cout << res << endl;

	return 0;
}
