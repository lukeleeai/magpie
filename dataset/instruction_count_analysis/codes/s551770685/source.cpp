#include <iostream>

#include <algorithm>

using namespace std;

typedef long long  ll;

#define rep(i,s,n)for(ll i=s;i<n;i++)

#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const ll LL_MAX = (ll)1 << 55;



int main()

{

	ll n, a, b;

	scanf("%lld%lld%lld", &n, &a, &b);



	ll ans = 0;

	ll x[100001] = {};

	repe(i, 1, n) {

		cin >> x[i];

		if (i >= 2) ans += min((x[i] - x[i - 1])*a, b);

	}

	cout << ans << endl;

	return 0;

}