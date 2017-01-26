// Maximal possible answer among strings with fixed length
#include <stdio.h>
#include <string.h>

#define MAX 4010

int ans[MAX],len;
int dp[MAX];

char str[MAX],cur_str[MAX];
char is_pal[MAX][MAX];

int gen(int k,int cnt) {
  if(k>=len) {
    cur_str[len]=0;
    return 1;
  }
  for(char c='a';c<='b';++c) {
    int i;
    cur_str[k]=c;
    dp[k]=dp[k-1]+1;
    is_pal[k][k]=1;
    for(i=0;i<k;++i) {
      if(cur_str[i]==c) {
        if(i==k-1 || is_pal[i+1][k-1]) {
          is_pal[i][k]=1;
          if(!i) {
            dp[k]=1;
            if(dp[k]+ans[len-k-1]<cnt)
              break;
          } else {
            if(dp[k]>dp[i-1]+1) {
              dp[k]=dp[i-1]+1;
              if(dp[k]+ans[len-k-1]<cnt)
                break;
            }
          }
        } else is_pal[i][k]=0;
      } else is_pal[i][k]=0;
    }
    if(dp[k]+ans[len-k-1]>=cnt) {
      if(gen(k+1,cnt)) return 1;
    }
  }
  return 0;
}

int main(int argc,char *argv[]) {
  int n,k,i,j;
  char a,b;
  a=argv[1][0];
  b=argv[2][0];
  sscanf(argv[3],"%d",&n);
  if(n<=50) {
    ans[1]=1;
    cur_str[0]='a';
    for(len=2;len<=n;++len) {
      memset(is_pal,0,sizeof(is_pal));
      memset(dp,0,sizeof(dp));
      dp[0]=1;
      is_pal[0][0]=1;
      if(!gen(1,ans[len-1]+1)) {
        for(j=MAX-1;j;--j) str[j]=str[j-1];
        str[0]='a';
        ans[len]=ans[len-1];
      } else {
        memcpy(str,cur_str,sizeof(str));
        ans[len]=ans[len-1]+1;
      }
    }
  }
  else {
    if(n%6<2) {
      k=0;
      if(n%6==1) {
        str[k++]='a';
        --n;
      }
      strcpy(str+k,"aababbaaabaababbba");
      k+=18;
    }
    else {
      for(k=0;n%6!=2;--n) {
        str[k++]='a';
      }
      strcpy(str+k,"aababbba");
      k+=8;
    }
    while(k+6<n) {
      strcpy(str+k,"ababba");
      k+=6;
    }
    strcpy(str+k,"aababb");
  }
  for(i=0;i<n;++i)
    if(str[i]=='a')
      str[i]=a;
    else
      str[i]=b;

  printf("%s\n",str);
  return 0;
}
