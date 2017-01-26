// Random string
#include <stdio.h>
#include <string.h>
#include "rand.h"

int seed;

int main(int argc,char *argv[]) {
  int n,k;
  sscanf(argv[1],"%d",&k);
  sscanf(argv[2],"%d",&n);
  sscanf(argv[3],"%d",&seed);
  z_srand(seed);
  for(;n;--n) {
    printf("%c",'a'+rand31()%k);
  }
  printf("\n");
  return 0;
}
