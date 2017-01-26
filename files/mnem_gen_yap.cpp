// Yet another pattern
#include <stdio.h>
#include <string.h>
#include "rand.h"

int seed;

#define MAX 101000

char str[MAX];

int main(int argc,char *argv[]) {
  int n,l,i,j;
  sscanf(argv[1],"%d",&n);
  sscanf(argv[2],"%d",&seed);
  z_srand(seed);
  str[0]='a';
  l=1;
  for(j=0;j<n;j++) {
    do {
      str[l]='a'+rand31()%26;
      str[l+1]='a'+rand31()%26;
    }
    while(str[l]==str[l+1]);
    for(i=0;i<l;++i) {
      str[l+2+i]=str[l-1-i];
    }
    l=l+l+2;
  }
  printf("%s\n",str);
  return 0;
}
