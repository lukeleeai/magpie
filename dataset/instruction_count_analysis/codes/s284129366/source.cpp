#include<cstdio>

#include<algorithm>

#define MAXN 56

using namespace std;

long long d[MAXN][MAXN][MAXN*MAXN],ans;

int n,A,a[MAXN],sum[MAXN];

int main()

{

	scanf("%d%d",&n,&A);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i]);

		sum[i]=sum[i-1]+a[i];

	}

	for(int i=0;i<=n;i++)

		d[i][0][0]=1;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=i;j++)

			for(int k=1;k<=sum[i];k++)

			{

				d[i][j][k]=d[i-1][j][k];

				if(k>=a[i]) d[i][j][k]=d[i][j][k]+d[i-1][j-1][k-a[i]];

			}

	for(int i=1;i<=n;i++)

		ans+=d[n][i][A*i];

	printf("%lld",ans);

}