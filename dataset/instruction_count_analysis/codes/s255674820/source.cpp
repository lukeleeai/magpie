#include"stdc++.h"

using namespace std;

typedef long long ll;

const int maxn=1e5+100;

int main()

{

	ll n,s[maxn];

	scanf("%lld",&n);

	for(int i=0;i<n;i++)

		scanf("%lld",&s[i]);

//	sort(s,s+n);

	ll ans=s[0];

	for(int i=1;i<n;i++)

		ans=__gcd(ans,s[i]);

	cout<<ans;

}