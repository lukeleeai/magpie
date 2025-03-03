#include "stdc++.h"

#define MOD 1000000007

#define M(x) ((x) % MOD)

#define N 100001

using namespace std;



typedef unsigned ui;

typedef long long ll;

typedef unsigned long long ul;



ul f[N];



int main(void) {

	ios::sync_with_stdio(0); cin.tie(0);

#ifdef _DEBUG

	ifstream cin("1.in");

#endif

	for (ui i = f[0] = 1; i != N; ++i)

		f[i] = M(f[i - 1] * i);

	ll n, m;

	cin >> n >> m;

	if (abs(n - m) > 1) cout << 0 << endl;

	else {

		if (n == m) cout << M(2 * f[n] * f[n]) << endl;

		else cout << M(f[n] * f[m]) << endl;

	}

	return 0;

}