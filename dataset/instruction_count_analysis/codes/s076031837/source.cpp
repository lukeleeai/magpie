#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=2e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;

#define mst(a) memset(a,0,sizeof a)

#define lx x<<1

#define rx x<<1|1

#define reg register

#define PII pair<int,int>

#define fi first 

#define se second

ll a[N];

int main(){

	int n,k;

	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++) scanf("%lld",&a[i]);

	sort(a,a+n);

	int l=0,r=n-1,w=1; 

	ll ans=1;

	if(k&1) ans=a[r--],k--,w=(ans<0?-1:1);

	while(k){

		ll x=a[l]*a[l+1],y=a[r]*a[r-1];

		if(x*w>y*w) ans=(ans*(x%mod))%mod,l+=2;

		else ans=(ans*(y%mod))%mod,r-=2;

		k-=2;

	}

	printf("%lld\n",(ans%mod+mod)%mod);

	return 0;

}
