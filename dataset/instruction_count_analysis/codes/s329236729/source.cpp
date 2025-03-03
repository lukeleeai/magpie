#include "stdc++.h"

 

#define ll long long

#define X first

#define Y second

#define MP make_pair

 

using namespace std;



const int N = 3e5 + 123;

const ll mod = 1e9 + 7;             



int n, h, w;

pair<int, int> a[N];

ll f[N], dp[N];

vector<int> srt;



ll bin_pow(ll x, ll y){

	ll res = 1;

	while(y){

		if(y & 1ll)

			res = res * x % mod;

		x = x * x % mod;

		y >>= 1LL;

	}

	return res;

}



ll calc(ll x, ll y){

	if(x < 0 || y < 0) return 0;

	return f[x + y - 2] * bin_pow(f[x - 1], mod - 2) % mod * bin_pow(f[y - 1], mod - 2) % mod;	

}



int main () {

	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);	



	f[0] = 1;

	for(ll i = 1;i <= 300000;i++){

		f[i] = f[i - 1] * i % mod;

	}



	cin >> h >> w >> n;

	for(int i = 1;i <= n;i++){

		int x, y;

		cin >> x >> y;

		a[i] = MP(x, y);

	}

	a[++n] = MP(h, w);



	sort(a + 1, a + n + 1);

	for(int i = 1;i <= n;i++){

		ll all = calc(a[i].X, a[i].Y);

		for(int j = 1; j < i; j++){

			all = (all - (dp[j] * calc(a[i].X - a[j].X + 1, a[i].Y - a[j].Y + 1) % mod) + mod) % mod;

		}

		dp[i] = all;

	}

	cout << dp[n];

	return 0;

}
