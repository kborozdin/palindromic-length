#include "testlib.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int PROB = 8;
string str;

void putPalindrom(int len, int &pos)
{
    for (int i = 0; i < len; i++)
        str[i + pos] = str[pos - i - 1];
    pos += len;
}

int A;

char get_rnd_char(char * argv[])
{
	return rnd.next(A) + 'a';
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Initialize random with seed argv1\n");
        printf("Generate beauty string with length equal argv2 using first argv3 letters\n");
        return 0;
    }
    rnd.setSeed(atoi(argv[1]));
    int len = atoi(argv[2]);
    A = atoi(argv[3]);
    if (A > 26)
    {
        printf("argv2 must be positive and no more than 26\n");
        return 0;
    }
    str.resize(len);

    for (int i = 0; i < len; )
    {
        int prb = rnd.next(PROB);
        if (prb <= 1 && i != 0)
            putPalindrom(min(len - i, rnd.next(i) + 1), i);
        else if (prb != PROB - 1 || len - i < 5)
            str[i++] = get_rnd_char(argv);
        else
        {
            char x = get_rnd_char(argv);
            char y = get_rnd_char(argv);
            char z = get_rnd_char(argv);
            str[i++] = x;
            str[i++] = y;
            str[i++] = x;
            str[i++] = z;
            str[i++] = x;
        }
    }
    cout << str << endl;

    return 0;
}
