// abab..aba
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  char c=argv[1][0];
  char d=argv[2][0];
  int n;
  sscanf(argv[3],"%d",&n);
  for(;n>1;--n)
    printf("%c%c",c,d);
  printf("%c\n",c);
  return 0;
}
