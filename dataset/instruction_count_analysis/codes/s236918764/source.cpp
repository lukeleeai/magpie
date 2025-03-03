#include<cstdio>

using namespace std;

int n,m;

int main()

{

	scanf("%d%d",&n,&m);

	for(register int x=0;x<=n;x++)

		for(register int y=0;y<=n;y++)

				if(x*10000+y*5000+(n-x-y)*1000==m && x>=0 && y>=0 && n-x-y>=0)

				{

					printf("%d %d %d",x,y,n-x-y);

					return 0;

				}

	printf("-1 -1 -1");

	return 0;

}