#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 1000000;

int main(int argc,char*argv[])
{
	int n=N/strlen(argv[1]);
	if(argc>2)
		n=atoi(argv[2]);
	for(int i=0;i<n;i++)
		printf("%s",argv[1]);
	puts("");
	return 0;
}