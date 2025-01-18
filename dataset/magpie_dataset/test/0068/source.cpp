#include"bits/stdc++.h"

using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<n;i++)

const long long mod = 1000000007;

const long long inf = 1ll << 61;

typedef pair<int, int> P;

typedef pair<double,P> PP;

struct edge { int to; int cost; };

int imos[100006];

signed main() {

	int n, m; cin >> n >> m;

	rep(i, m) {

	

		int l, r; cin >> l >> r;

		imos[l]++;

		imos[r + 1]--;

	}

	rep(i, 100003)imos[i + 1] += imos[i];

	int cnt = 0;

	rep(i, 100003) {

		if (imos[i] == m)cnt++;

	}cout << cnt << endl;

}
