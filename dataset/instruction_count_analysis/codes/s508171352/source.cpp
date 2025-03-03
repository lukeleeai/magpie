#include <cstdio>

#include <cstdlib>

#define N 10001

#define int long long

#define rnt register int

using namespace std;

int n,A,x,ans,sum[N],dp[60][N];

signed main(){

	scanf("%lld%lld",&n,&A);dp[0][0]=1;

	for(rnt i=1;i<=n;i=-~i){

		scanf("%lld",&x);sum[i]=sum[i-1]+x;

		for(rnt j=i;~j;--j) for(rnt k=0;k<=sum[i];k=-~k) dp[j+1][k+x]+=dp[j][k];

	}

	for(rnt i=1;i<=n;i=-~i) ans+=dp[i][i*A];

	printf("%lld",ans);

	return 0;

}