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

    string s = "bb";
    while ((int)s.length() < n)
    {
        string ns;
        for (int i = 0; i < (int)s.length(); i += 2)
        {
            if (s[i] == 'a' && s[i + 1] == 'a')
                ns += "baaa";
            else if (s[i] == 'a' && s[i + 1] == 'b')
                ns += "baab";
            else if (s[i] == 'b' && s[i + 1] == 'a')
                ns += "bbaa";
            else
                ns += "bbab";
        }
        s = ns;
    }

    cout << s.substr(0, n) << endl;

	return 0;
}
