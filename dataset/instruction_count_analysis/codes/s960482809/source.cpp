/*Lucky_Glass*/

#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

using namespace std;

typedef long long ll;

const ll INF=9223372036854775807ll;

ll n,s,ans=INF;

ll GetS(ll x)

{

	ll f=n,ret=0;

	while(f)

		ret+=f%x,f/=x;

	return ret;

}

int main()

{

	scanf("%lld%lld",&n,&s);

	if(n==s) {printf("%lld\n",n+1ll);return 0;}

	ll T=n-s;

	for(ll i=1;i<=sqrt(T);i++)

		if(T%i==0)

		{

			ll x=i+1ll,y=T/i+1ll;

			if(GetS(x)==s) ans=min(ans,x);

			if(GetS(y)==s) ans=min(ans,y);

		}

	for(ll i=2;i<=sqrt(n);i++)

		if(GetS(i)==s)

		{

			ans=min(ans,i);

			break;

		}

	printf("%lld\n",ans==INF? -1ll:ans);

	return 0;

}
