#include<cstdio>

#include<cstdlib>

#define rnt register int

using namespace std;

int n,m,x,cnt;

int main()

{

	scanf("%d %d",&n,&m);

	for(;n;--n)

	{

		scanf("%d",&x);

		if(x>=m) cnt=-~cnt;

	}

	printf("%d",cnt);

	return 0;

}