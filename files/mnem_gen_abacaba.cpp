// abacaba
#include <stdio.h>
#include <string.h>

#define MAX 100000

char str[MAX];

int main(int argc,char *argv[]) {
  int n,k,i;
  sscanf(argv[1],"%d",&n);
  str[0]='a';
  k=1;
  char c='a';
  for(;n>1;--n) {
    str[k]=++c;
    for(i=0;i<k;++i)
      str[k+1+i]=str[i];
    k=k+k+1;
  }
  printf("%s\n",str);
  return 0;
}
