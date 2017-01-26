#include "testlib.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
        printf("mode len seed\n");
        return 0;
	}
    int mode = atoi(argv[1]);
    int len = atoi(argv[2]);
    rnd.setSeed(atoi(argv[3]));

    if (mode == 1)
    {
        char c = 'a' + rnd.next(26);
        for (int i = 0; i < len; i++)
            putchar(c);
        putchar('\n');
    }
    else if (mode == 2 || mode == 3)
    {
        char x = -1, y = -1;
        do
        {
            x = 'a' + rnd.next(26);
            y = 'a' + rnd.next(26);
        }
        while (x == y);
        int pos = rnd.next(len);
        if (mode == 3)
            pos = 0;
        for (int i = 0; i < len; i++)
        {
            if (i == pos)
                putchar(y);
            else
                putchar(x);
        }
        putchar('\n');
    }
    else
        throw;

	return 0;
}
