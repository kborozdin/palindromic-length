// Anticube #2
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) {
  int n,i;
  char a,b,c,d,e;
  a=argv[1][0];
  b=argv[2][0];
  c=argv[3][0];
  d=argv[4][0];
  e=argv[5][0];
  sscanf(argv[6],"%d",&n);
  n=(n-6)>>2;
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("%c%c",b,c);
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("%c%c",d,e);
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("%c%c",c,b);
  for(i=0;i<n;++i)
    printf("%c",a);
  printf("\n");
  return 0;
}
