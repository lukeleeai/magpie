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

#define Would

#define you

#define please



const int K = 11;

const int KM = 1 << (K - 1);

int dat[1 << K], dat2[1 << K];

int laz[1 << K];

int zero = 0;



void eval(int A, int l, int r) {

	if (laz[A] == zero) return;

	if (A * 2 < 1 << K) {

		laz[A * 2] += laz[A];

		laz[A * 2 + 1] += laz[A];

	}

	dat[A] += laz[A];

	dat2[A] += laz[A];

	laz[A] = zero;

}



pair<int, int> update(int L, int R, int X, int A, int l, int r) {

	eval(A, l, r);

	if (r <= L || R <= l) return mp(dat[A], dat2[A]);

	if (L <= l && r <= R) {

		laz[A] = X;

		return mp(dat[A] + X, dat2[A] + X);

	}

	int a, b, c, d;

	tie(a, b) = update(L, R, X, A * 2, l, (l + r) / 2);

	tie(c, d) = update(L, R, X, A * 2 + 1, (l + r) / 2, r);

	dat[A] = max(a, c);

	dat2[A] = min(b, d);

	return mp(dat[A], dat2[A]);

}



void add(int L, int R, int X) {

	update(L, R, X, 1, 0, KM);

}



pair<int, int> check(int L, int R, int A, int l, int r) {

	eval(A, l, r);

	if (r <= L || R <= l) return mp(-1e9, 1e9);

	if (L <= l && r <= R) return mp(dat[A], dat2[A]);

	int a, b, c, d;

	tie(a, b) = check(L, R, A * 2, l, (l + r) / 2);

	tie(c, d) = check(L, R, A * 2 + 1, (l + r) / 2, r);

	return mp(max(a, c), min(b, d));

}



pair<int, int> query(int L, int R) {

	return check(L, R, 1, 0, KM);

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, K;

	cin >> N >> K;



	int gyaku = 0;

	int goukei = 0;

	int to[100001], ne[100001], he[100001] = {};

	rep1(i, N) {

		int x, y;

		char c;

		cin >> x >> y >> c;

		int k = x / K ^ y / K;

		x = x % K;

		y = y % K;

		if (c == 'W' ^ (k & 1)) {

			gyaku++;

			to[i] = -x - 1;

			ne[i] = he[y];

			he[y] = i;

			add(0, x, -1);

			goukei--;

		}

		else {

			to[i] = x;

			ne[i] = he[y];

			he[y] = i;

			add(0, x, 1);

			goukei++;

		}

	}

	int saidai = -1e9;

	int p = 0;

	rep(y, K) {



		auto kari = query(0, K);

		saidai = max(saidai, kari.first);

		saidai = max(saidai, goukei - kari.second);



		for (int i = he[y]; i; i = ne[i]) {

			int x = to[i];

			if (x >= 0) {

				add(0, x, -1);

				add(x, K, 1);

			}

			else {

				add(0, -x - 1, 1);

				add(-x - 1, K, -1);

			}

		}

	}

	co(gyaku + saidai);



	Would you please return 0;

}