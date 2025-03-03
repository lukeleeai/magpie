#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

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



//みなさん天才的ですよね



ll num[858200];

const int ma = (1 << 19) - 1;

bool query(ll n) {

	int n2 = n % 858100 + 1;

	while (num[n2]) {

		if (num[n2] == n + 1) return 1;

		n2 = n2 * 2 % 858101;

	}

	return 0;

}

void add(ll n) {

	int n2 = n % 858100 + 1;

	while (num[n2]) {

		if (num[n2] == n + 1) {

			return;

		}

		n2 = n2 * 2 % 858101;

	}

	num[n2] = n + 1;

}



int KH[300001], KW[300001];

int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int H, W, M;

	cin >> H >> W >> M;



	rep(i, M) {

		int h, w;

		cin >> h >> w;



		KH[h]++;

		KW[w]++;

		add(ll(h) * W + w);

	}



	int saidaih = -1;

	int hh[300001], h = 0;

	rep1(i, H) {

		if (saidaih < KH[i]) {

			saidaih = KH[i];

			h = 1;

			hh[0] = i;

		}

		else if (saidaih == KH[i]) {

			hh[h++] = i;

		}

	}

	int saidaiw = -1;

	int ww[300001], w = 0;

	rep1(i, W) {

		if (saidaiw < KW[i]) {

			saidaiw = KW[i];

			w = 1;

			ww[0] = i;

		}

		else if (saidaiw == KW[i]) {

			ww[w++] = i;

		}

	}



	if (ll(h) * w > M) {

		co(saidaih + saidaiw);

		return 0;

	}

	int atta = 0;

	rep(i, h) rep(j, w) {

		if (!query(ll(hh[i]) * W + ww[j])) {

			atta = 1;

			break;

		}

	}



	if (atta) co(saidaih + saidaiw);

	else co(saidaih + saidaiw - 1);



	Would you please return 0;

}