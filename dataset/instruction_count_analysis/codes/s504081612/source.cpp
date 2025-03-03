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



const int K = 18;

const int KM = 1 << (K - 1);

int dat[1 << K];



void update(int A) {

	dat[A] = min(dat[A * 2], dat[A * 2 + 1]);

	if (A != 1) update(A / 2);

}



void add(int A, int B) {

	int C = A + KM;

	dat[C] = B;

	update(C / 2);

}



int check(int L, int R, int A, int l, int r) {

	if (L <= l && r <= R) return dat[A];

	if (r <= L || R <= l) return 1e9;

	return min(check(L, R, A * 2, l, (l + r) / 2), check(L, R, A * 2 + 1, (l + r) / 2, r));

}



int query(int L, int R) {

	return check(L, R, 1, 0, KM);

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	pair<int, int> LR[100000];

	int kotae = 0;

	rep(i, N) {

		int l, r;

		cin >> l >> r;

		LR[i] = mp(l, r);

	}

	sort(LR, LR + N);

	rep(i, 1 << K) dat[i] = 1e9;

	rep(i, N) add(i, LR[i].second);



	rep(i, N) {

		int l1 = LR[i].first;

		int r1 = LR[i].second;

		int lr1 = max(0, r1 - l1 + 1);

		int l2 = (i == N - 1) ? LR[N - 2].first : LR[N - 1].first;

		int r2 = min(query(i + 1, N), query(0, i));

		int lr2 = max(0, r2 - l2 + 1);



		kotae = max(kotae, lr1 + lr2);

	}





	rep(i, N - 1) {

		int l1 = LR[i].first;

		int r1 = query(0, i + 1);

		int lr1 = max(0, r1 - l1 + 1);

		int l2 = LR[N - 1].first;

		int r2 = query(i + 1, N);

		int lr2 = max(0, r2 - l2 + 1);



		kotae = max(kotae, lr1 + lr2);

	}

	co(kotae);



	Would you please return 0;

}