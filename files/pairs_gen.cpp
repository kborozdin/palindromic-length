#include "rand.h"
#include <cstdio>
#include <algorithm>

void checkVariable(int n)
{
    if (n < 6 || n > 300000)
        throw "param has to satisfy the following requirement 6 <= N <= 300000";
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        throw "you have to pass exactly 4 params";
    int seed = atoi(argv[1]);
    int l = atoi(argv[2]);
    checkVariable(l);
    int r = atoi(argv[3]);                    
    checkVariable(r);

    z_srand(seed);
    int n = rand(l, r);

    printf("sp");
    for (int i = 0; i < n - 5; i++)
        putchar('a');
    printf("rta\n");

    return 0;
}
