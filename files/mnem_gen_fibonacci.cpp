// Fibonacci strings
#include <stdio.h>
#include <string.h>

#define MAX 100000

char f[3][MAX];

int main(int argc,char *argv[]) {
  int i,n;
  char a=argv[1][0];
  char b=argv[2][0];
  sscanf(argv[3],"%d",&n);
  f[0][0]=b;
  f[1][0]=a;
  int step=0;
  for(i=2;i<=n;++i) {
    int j,k;
    for(k=0;f[(step+1)%3][k];++k)
      f[(step+2)%3][k]=f[(step+1)%3][k];
    for(j=0;f[step][j];++j)
      f[(step+2)%3][j+k]=f[step][j];
    step=(step+1)%3;
  }
  if(n) step=(step+1)%3;
  printf("%s\n",f[step]);
  return 0;
}
