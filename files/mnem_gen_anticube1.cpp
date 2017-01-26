// Anticube #1
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  int n,i;
  char a,b,c;
  a=argv[1][0];
  b=argv[2][0];
  c=argv[3][0];
  sscanf(argv[4],"%d",&n);
  n=(n-2)>>1;
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("%c%c",b,c);
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("\n");
  return 0;
}
