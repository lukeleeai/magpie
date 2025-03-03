#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 50

using namespace std;

typedef long long LL;

int a[MAXN+5];

LL dp[MAXN+5][MAXN*MAXN+5];

int main()

{

	int n,A;

	scanf("%d %d",&n,&A);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	dp[0][0]=1LL;

	for(int i=1;i<=n;i++)

		for(int j=A*n;j>=a[i];j--)

			for(int tot=n;tot>=1;tot--)

				dp[tot][j]+=dp[tot-1][j-a[i]];

	LL ans=0;

	for(int tot=1;tot<=n;tot++)

		ans+=dp[tot][A*tot];

	printf("%lld\n",ans);

	return 0;

}