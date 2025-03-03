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



const int K = 19;

const int KM = 1 << (K - 1);

int dat[1 << K];

int laz[1 << K];

int zero = 2e9;



void update(int L, int R, int X, int A, int l, int r) {

	if (r <= L || R <= l) return;

	if (L <= l && r <= R) {

		laz[A] = min(laz[A], X);

		return;

	}

	update(L, R, X, A * 2, l, (l + r) / 2);

	update(L, R, X, A * 2 + 1, (l + r) / 2, r);

}



void add(int L, int R, int X) {

	update(L, R, X, 1, 0, KM);

}



int check(int L, int A, int l, int r) {

	if (laz[A] != zero) {

		if (A * 2 < 1 << K) {

			laz[A * 2] = min(laz[A * 2], laz[A]);

			laz[A * 2 + 1] = min(laz[A * 2 + 1], laz[A]);

		}

		dat[A] = min(dat[A], laz[A]);

		laz[A] = zero;

	}

	if (r <= L || L + 1 <= l) return zero;

	if (L <= l && r <= L + 1) return dat[A];

	return min(check(L, A * 2, l, (l + r) / 2), check(L, A * 2 + 1, (l + r) / 2, r));

}



int query(int L) {

	return check(L, 1, 0, KM);

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, Q;

	cin >> N >> Q;

	pair<int, pair<int, int>> XST[200000];

	rep(i, N) {

		int S, T, X;

		cin >> S >> T >> X;

		XST[i] = mp(X, mp(S, T));

	}

	sort(XST, XST + N);

	int D[200002];

	D[0] = 0;

	D[Q + 1] = zero;

	rep1(i, Q) cin >> D[i];

	rep(i, 1 << K) {

		dat[i] = zero;

		laz[i] = zero;

	}



	rep(i, N) {



		int L = 0, R = Q + 1;

		while (L + 1 < R) {

			int H = (L + R) / 2;

			if (D[H] + XST[i].first >= XST[i].second.first) R = H;

			else L = H;

		}

		int L2 = 0, R2 = Q + 1;

		while (L2 + 1 < R2) {

			int H = (L2 + R2) / 2;

			if (D[H] + XST[i].first >= XST[i].second.second) R2 = H;

			else L2 = H;

		}



		if (R <= L2) {

			add(R, L2 + 1, XST[i].first);

		}



	}



	rep1(i, Q) {

		int kari = query(i);

		if (kari == zero) co(-1);

		else co(kari);

	}



	Would you please return 0;

}