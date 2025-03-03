#include"stdc++.h"

#define ll long long

using namespace std;

ll dp[1005],n,a[1005],l[1005],r[1005],id,ans[1005],tail;

int main(){

	scanf("%lld",&n);

	dp[0]=-0x3f3f3f3f;

	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),dp[i]=a[i];

	for(int i=1;i<=n;++i)

		for(int j=1;j<i;++j)

			if((i-j)%2==0&&dp[j]+a[i]>dp[i])

				dp[i]=dp[j]+a[i],l[i]=j;

	for(int i=1;i<=n;++i) if(dp[i]>dp[id]) id=i;

	printf("%lld\n",dp[id]);

	for(int i=n;i>id;--i) ans[++tail]=i;

	while(l[id]!=0){

		int mid=(id+l[id])>>1;

		for(int i=mid;i>l[id];--i) ans[++tail]=i;

		id=l[id];

	}

	for(int i=1;i<id;++i) ans[++tail]=1;

	printf("%lld\n",tail);

	for(int i=1;i<=tail;++i) printf("%lld\n",ans[i]);

}