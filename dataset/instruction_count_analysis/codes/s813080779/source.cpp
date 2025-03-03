#include"stdc++.h"

#define rep(i,N) for(int i=0;i<(N);i++)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

const long long MOD = 1e9 + 7;

const long long INF = 1e12;

const int inf = 1e9;

const int mod = 1e9+7;

typedef long long ll;

typedef pair<ll,int> P;

typedef set<int> S;

int main(){

	cout << fixed << setprecision(10);

	ll ans = 0;

	ll n,k;

	cin >> n >> k;

	for(ll i=k; i<=n+1;i++){

		ll left = i*(0+i-1)/2;

		ll right = i*(n+n-i+1)/2;

		ans += right - left + 1;

		ans %= mod;

	}

	cout << ans << endl;

	return 0;

}