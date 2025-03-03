#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007LL;

bool b[100001] = { false };

int num[100001];

LL fact[100001];

LL inv[100001];

LL inv_fact[100001];

LL mod_pow(LL x, LL a) {

	if (a == 0) return 1;

	if (a % 2 == 0) {

		LL ret = mod_pow(x, a / 2);

		return (ret*ret) % MOD;

	}

	else {

		return (x*mod_pow(x, a - 1)) % MOD;

	}

}

LL comb(LL n, LL k) {

	if (n < k) return 0;

	LL ans = (fact[n] * inv_fact[k]) % MOD;

	ans = (ans*inv_fact[n - k]) % MOD;

	return ans;

}

int main() {

	int n, dup[2];

	cin >> n;

	for (int i = 0; i <= n; i++) {

		int a;

		cin >> a;

		num[i] = a;

		if (!b[a - 1])b[a - 1] = true;

		else {

			dup[1] = i;

			break;

		}

	}

	for (int i = 0; i < dup[1]; i++) {

		if (num[i] == num[dup[1]])dup[0] = i;

	}

	fact[0] = 1;

	inv_fact[0] = 1;

	for (int i = 1; i < n + 1; i++) {

		inv[i] = mod_pow(i, MOD - 2);

		fact[i] = (fact[i - 1] * i) % MOD;

		inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;

	}

	int cen = dup[1] - dup[0] - 1;

	cout << n << endl;

	for (int i = 2; i <= n + 1; i++) {

		LL sum = 0;

		sum = (sum + comb(n - 1, i)) % MOD;

		sum = (sum + comb(n - 1, i - 2)) % MOD;

		sum = (sum + 2 * comb(n - 1, i - 1)) % MOD;

		sum = (sum - comb(n - cen - 1, i - 1) + MOD) % MOD;

		cout << sum << endl;

	}

}