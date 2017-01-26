// Periodic string
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  int n;
  sscanf(argv[2],"%d",&n);
  for(;n;--n)
    printf("%s",argv[1]);
  printf("\n");

  return 0;
}
