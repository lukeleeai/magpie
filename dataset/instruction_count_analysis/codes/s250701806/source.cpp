#include"stdc++.h"

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;



ll d[MAXN], s[MAXN];



ll quick_pow(ll a, ll b, ll mod) {

	ll ans = 1;

	while(b) {

		if(b & 1) {

			ans = ans * a % mod;

		}

		a = a * a % mod;

		b >>= 1;

	}

	return ans;

}



int main() {

	ios::sync_with_stdio(false);

	ll n, num, mod = 998244353;

	while(cin >> n) {

		ll maxd = -1;

		memset(d, 0, sizeof(d));

		memset(s, 0, sizeof(s));

		for(int i = 0; i < n; i++) {

			cin >> num;

			s[i] = num;

			d[num]++;

			maxd = max(maxd, num);

		}

		ll ans;

		if(s[0] != 0 || d[0] != 1) {

			ans = 0;

		} else if(n == 1) {

			if(d[0] == 1 && s[0] == 0) {

				ans = 1;

			} else {

				ans = 0;

			}

		} else {

			ans = 1;

			for(int i = 0; i <= maxd; i++) {

				ans = ans * quick_pow(d[i], d[i + 1], mod) % mod;

			}

		}

		cout << ans << endl;

	}

	return 0;

}