#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 100010

int a[3][MAXN],n,tg[3],to[MAXN];

int main()

{

	scanf("%d",&n);

	for(int i=0;i<3;i++)

		for(int j=1;j<=n;j++)

			scanf("%d",&a[i][j]);

	for(int i=1;i<=n;i++)

	{

		to[i]=a[1][i]/3+1;

		if(!((a[0][i]%3==1&&a[1][i]==a[0][i]+1&&a[2][i]==a[0][i]+2)||(a[0][i]%3==0&&a[1][i]==a[0][i]-1&&a[2][i]==a[0][i]-2))||((to[i]&1)!=(i&1)))

		{

			printf("No\n");

			return 0;

		}

		tg[i&1]^=(a[0][i]>a[1][i]);

	}

	for(int i=1;i<=n;i++)

	{

		while(to[i]!=i)

		{

			tg[i&1^1]^=1;

			swap(to[i],to[to[i]]);

		}

	}

	if(tg[0]||tg[1]) printf("No\n");

	else printf("Yes\n");

}
