#include "testlib.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[])
{
    if (argc < 4)
    {
        printf("usage: len prob_of_other seed\n");
        return 0;
    }

    int len = atoi(argv[1]);
    int prob = atoi(argv[2]);
    rnd.setSeed(atoi(argv[3]));

    char x = -1, y = -1;
    do
    {
        x = 'a' + rnd.next(26);
        y = 'a' + rnd.next(26);
    }
    while (x == y);

    for (int i = 0; i < len; i++)
    {
        if (prob < rnd.next(100))
            putchar(y);
        else
            putchar(x);
    }
    putchar('\n');

    return 0;
}
