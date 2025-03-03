#include<iostream>

#include<cstring>

#include<cstdio>

using namespace std;

typedef long long ll;

const int maxn = 1000010;

const int inf = 0x3f3f3f3f;

ll dp[maxn];

ll n, W;

ll v[maxn];

ll w[maxn];

inline ll max(ll x, ll y) {

	return x > y ? x : y;

}

inline ll min(ll x, ll y) {

	return x < y ? x : y;

}

int main() {

	memset(dp, 0x3f, sizeof(dp));

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	cin >> n >> W;

	for (int i = 1; i <= n; i++)

		cin >> w[i] >> v[i];

	ll ans = 0ll;

	dp[0] = 0;

	for (int i = 1; i <= n; i++){

		for (int j = 1e5; j >= v[i]; --j){

			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);

			if (dp[j] <= W) ans = max(ans, (ll)(j));

		}

	}

	cout << ans;

	return 0;

}