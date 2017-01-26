#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc,char*argv[])
{
	int n=100000/strlen(argv[1]);
	if(argc>2)
		n=atoi(argv[2]);
	for(int i=0;i<n;i++)
		printf("%s",argv[1]);
	puts("");
	return 0;
}