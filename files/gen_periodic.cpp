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

    string s;
    while (true)
    {
        int len = rnd.next(min(21, (int)s.length() + 1));
        int cnt = rnd.next(10) + 1;
        if ((int)s.length() + len * cnt > n)
            break;
        if (len == 0)
        {
            char c = 'a' + rnd.next(3);
            for (int i = 0; i < cnt; i++)
                s += c;
        }
        else
        {
            for (int i = 0; i < cnt; i++)
                s += s.substr((int)s.length() - len);
        }
    }

    cout << s << endl;

	return 0;
}
