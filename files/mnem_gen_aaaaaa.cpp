// aaaaaaaa...aaa
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  char c=argv[1][0];
  int n;
  sscanf(argv[2],"%d",&n);
  for(;n;--n)
    printf("%c",c);
  printf("\n");
  return 0;
}
