#include "stdc++.h"

#define rep(i, n) for (ll i = 0; i < (n); ++i)

#define all(a) (a).begin(), (a).end()

#define dunk(a) cout << (a) << endl

#define rall(a) (a).rbegin(), (a).rend()

const int INF = 2e9;

using namespace std;

using Graph = vector<vector<int>>;

typedef pair<int, int> P;

typedef long long ll;



int main() {

	int n; cin >> n;

	vector<int> v(n); rep(i, n) cin >> v[i];



	int even[100200];

	int odd[100200];

	rep(i, 100010) {

		even[i] = 0;

		odd[i] = 0;

	}



	int maxev = 0, semaxev = 0;

	int maxod = 0, semaxod = 0;

	int numev, numod;



	//偶数入力

	for (int i = 1; i < n; i += 2) even[v[i]]++;

	//奇数入力

	for (int i = 0; i < n; i += 2) odd[v[i]]++;





	//偶数整理

	for (int i = 1; i < 100001; i++) {

		if (even[i] >= maxev) {

			semaxev = maxev;

			maxev = even[i];

			numev = i;

		}

		if (even[i] >= semaxev && even[i] < maxev) {

			semaxev = even[i];

		}

	}



	//奇数整理

	for (int i = 1; i < 100001; i++) {

		if (odd[i] >= maxod) {

			semaxod = maxod;

			maxod = odd[i];

			numod = i;

		}

		if (odd[i] >= semaxod && odd[i] < maxod) {

			semaxod = odd[i];

		}

	}



	//回答パート

	int ans;

	if (numev != numod) ans = n - maxev - maxod;



	else ans = min(n - maxev - semaxod, n - maxod - semaxev);



	cout << ans << endl;



}
