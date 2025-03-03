#include <cstdio>

#include <algorithm>

#define ll long long

using namespace std;

const ll inf=1e18+10;

ll n,k,ans,a[200005];

ll find1(int now,ll x){

	int l=now+1,r=n,best=now;

	while(l<=r){

		int mid=l+r>>1;

		if(a[now]*a[mid]<=x){

			l=mid+1;

			best=mid;

		}

		else r=mid-1;

	}

	return best;

}

ll find2(int now,ll x){

	int l=now+1,r=n,best=n+1;

	while(l<=r){

		int mid=l+r>>1;

		if(a[now]*a[mid]<=x){

			r=mid-1;

			best=mid;

		}

		else l=mid+1;

	}

	return best;

}

bool check(ll x){

	ll cnt=0;   //找比 x 小的积 

	for(int i=1;i<n;i++){

		if(a[i]>=0) cnt+=find1(i,x)-i;

		else cnt+=n-find2(i,x)+1;

	}

	return cnt>=k;

}

int main(){

	scanf("%lld%lld",&n,&k);

	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

	sort(a+1,a+n+1);

	ll l=-inf,r=inf;

	while(l<=r){

		ll mid=l+r>>1;

		if(check(mid)){

			ans=mid;

			r=mid-1;

		}

		else l=mid+1;

	}

	printf("%lld",ans);

	return 0;

}