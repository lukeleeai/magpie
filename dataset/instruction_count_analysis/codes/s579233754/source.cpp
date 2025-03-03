#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	pair<int, int> XL[100000];

	rep(i, N) {

		int x, l;

		cin >> x >> l;

		XL[i] = mp(x + l, x - l);

	}

	sort(XL, XL + N);



	int mae = -2e9;

	int kotae = 0;

	rep(i, N) {

		if (mae <= XL[i].second) {

			kotae++;

			mae = XL[i].first;

		}

	}

	co(kotae);





	Would you please return 0;

}