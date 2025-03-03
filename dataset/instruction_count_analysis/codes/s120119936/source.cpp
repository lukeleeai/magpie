#include <cstdio>

#include <algorithm>

#define ll long long

using namespace std;

const int N=1e5+5;

int n,m,v,p;

ll a[N],sum[N];

bool check(int x){

	if(a[x]+m<a[p]) return 0;

	return 1ll*m*v<=1ll*(p-1ll)*m+1ll*(n-x+1)*m-1ll*(sum[x-1]-sum[p-1])+1ll*(a[x]+m)*(x-p);

}

signed main() {

	scanf("%d%d%d%d",&n,&m,&v,&p);

	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

	sort(a+1,a+n+1);

	reverse(a+1,a+n+1);

	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

	int l=p,r=n,ans=p;

	while(l<=r){

		int mid=l+r>>1;

		if(check(mid)){

			ans=mid;

			l=mid+1;

		}

		else r=mid-1;

	}

	printf("%d\n",ans);

	return 0;

}