// Random palindrome
#include <stdio.h>
#include <string.h>
#include "rand.h"

int seed;

#define MAX 4100

char str[MAX];

int main(int argc,char *argv[]) {
  int n,k,i;
  sscanf(argv[1],"%d",&k);
  sscanf(argv[2],"%d",&n);
  sscanf(argv[3],"%d",&seed);
  z_srand(seed);
  for(i=0;i<=n-1-i;++i) {
    str[i]=str[n-1-i]='a'+rand31()%k;
  }
  printf("%s\n",str);
  return 0;
}
