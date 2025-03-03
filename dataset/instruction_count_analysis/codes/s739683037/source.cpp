#include "stdc++.h"

using namespace std;



const int N = 5e5 + 5;

const int mod = 1e9 + 9277;



int n;

string s;

int hs[N], pw[N];

bool prf[N], suf[N];



int get(int l,int r) {

	return (hs[r] - 1LL * hs[l - 1] * pw[r - l + 1] % mod + mod) % mod;

}



int main() {

	ios_base::sync_with_stdio(false);

	cin >> s; n = s.size(); s = '#' + s;

	hs[0] = 0, pw[0] = 1;

	for (int i = 1; i <= n; ++i) {

		hs[i] = (1LL * hs[i - 1] * 1007 % mod + (s[i] - 'a' + 1)) % mod;

		pw[i] = 1LL * pw[i - 1] * 1007 % mod;

	}

	

	for (int i = 1; i <= n; ++i) {

		for (int j = i + i; j <= n; j += i) {

			if (get(j - i + 1, j) == get(1, i)) prf[j] = true;

			else break;

		}

	}

	

	for (int i = 1; i <= n; ++i) {

		for (int j = n - i - i + 1; j >= 1; j -= i) {

			if (get(j, j + i - 1) == get(n - i + 1, n)) suf[j] = true;

			else break;

		}

	}

	

	if (!prf[n]) return cout << 1 << '\n' << 1 << '\n',0;

	int cnt = 0;

	for (int i = 1; i < n; ++i) if (!prf[i] && !suf[i + 1]) {

		cnt++;

	} 

	if (cnt) cout << 2 << '\n' << cnt << '\n';

	else cout << n << '\n' << 1 << '\n';

}