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



const int cm = 1 << 17;

char cn[cm], *ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int BIT[200201];

inline void add(int A) {

	while (A <= 200200) {

		BIT[A]++;

		A += A & -A;

	}

}



inline int query(int A) {

	int kotae = 0;

	while (A > 0) {

		kotae += BIT[A];

		A -= A & -A;

	}

	return kotae;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	int N = getint();

	int K = getint();



	pair<ll, int> B[200001] = {};

	int C[200001] = {};

	rep(i, N) {

		B[i + 1] = mp(B[i].first + getint() - K, i + 1);

	}

	sort(B, B + N + 1);

	int kazu = 0;

	int mae = 1e18;

	rep(i, N + 1) {

		if (mae != B[i].first) kazu++;

		C[B[i].second] = kazu;

	}



	ll kotae = 0;

	add(C[0]);

	rep1(i, N) {

		kotae += query(C[i]);

		add(C[i]);

	}

	co(kotae);



	Would you please return 0;

}