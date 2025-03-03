#include "stdc++.h"

using namespace std;

const int N=2e5+10;

typedef long long ll;

ll a[N],c[N];

ll n;

int main() {

	ll i,x,cnt=0,ans=0;

	scanf("%lld",&n);

	for (i=1;i<=n;i++) {

		scanf("%lld",&x);

		a[x]++;

		c[i]=x;

	}

	ans=0;

	for (i=1;i<=n;i++)

		if (a[i]>0) ans+=a[i]*(a[i]-1)/2;

//	cout<<ans<<endl;

	for (i=1;i<=n;i++) 

		printf("%lld\n",ans-(a[c[i]]-1));

	return 0;

} 