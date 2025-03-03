#include "stdc++.h"

using namespace std;



const int maxn = 550000;

const int unit = 29;

const int mod = 1e9 + 7;



char w[maxn];

long long state[maxn];

long long pw[maxn];

bool f[maxn], g[maxn];



int main() {

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	cin >> w;

	int n = strlen(w);

	pw[0] = 1;

	for(int i = 1; i < maxn; ++ i) pw[i] = pw[i - 1] * unit % mod;

	for(int i = 0; i < n; ++ i) {

		state[i] = ((i == 0 ? 0 : state[i - 1]) + (w[i] - 'a' + 1) * pw[i]) % mod;

	}

	for(int i = 1; i <= n; ++ i) f[i] = true;

	int len = n;

	for(int i = 1; i < n; ++ i) {

		long long cs = state[i - 1];

		for(int j = i + i; j <= n; j += i) {

			long long ns = (state[j - 1] - state[j - i - 1] + mod) % mod;

			cs = (cs * pw[i]) % mod;

			if(ns == cs) f[j] = false;

			else break;

		}

		if(n % i == 0) {

			long long ns = (state[n - i - 1] * pw[i]) % mod;

			long long cs = (state[n - 1] - state[i - 1] + mod) % mod;

			if(ns == cs) {

				if(len > i) len = i;

			}

		}

	}

	reverse(w, w + n);

	for(int i = 0; i < n; ++ i) {

		state[i] = ((i == 0 ? 0 : state[i - 1]) + (w[i] - 'a' + 1) * pw[i]) % mod;

	}

	for(int i = 1; i <= n; ++ i) g[i] = true;

	for(int i = 1; i < n; ++ i) {

		long long cs = state[i - 1];

		for(int j = i + i; j <= n; j += i) {

			long long ns = (state[j - 1] - state[j - i - 1] + mod) % mod;

			cs = (pw[i] * cs) % mod;

			if(ns == cs) g[j] = false;

			else break;

		}

	}

	if(len == 1) {

		cout << n << "\n" << 1 << "\n";

		return 0;

	}

	if(len == n) {

		cout << 1 << "\n" << 1 << "\n";

		return 0;

	}

	cout << 2 << "\n";

	int pos = 0;

	for(int i = 1; i < n; ++ i) {

		if(f[i] && g[n - i]) ++ pos;

	}

	cout << pos << "\n";

	return 0;

}