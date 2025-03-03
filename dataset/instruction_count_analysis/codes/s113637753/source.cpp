#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

#define MAXN 505

int n,m,lx=-1,ly=-1;

char s[MAXN][MAXN],a[MAXN][MAXN],b[MAXN][MAXN];

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		scanf("%s",s[i]+1);

	memcpy(a,s,sizeof s);

	memcpy(b,s,sizeof b);

	for(int i=1;i<=n;i++)

	{

		a[i][1]=b[i][m]='#';

		if(i&1)

		{

			for(int j=2;j<m;j++)

				a[i][j]='#';

		}

		else

		{

			for(int j=2;j<m;j++)

				b[i][j]='#';

		}

	}

	for(int i=1;i<=n;i++)

		printf("%s\n",a[i]+1);

	printf("\n");

	for(int i=1;i<=n;i++)

		printf("%s\n",b[i]+1);

}