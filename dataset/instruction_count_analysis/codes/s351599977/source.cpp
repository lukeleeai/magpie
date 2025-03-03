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

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	if (ci - cn + 16 > cm) {

		int A = getcha() - '0';

		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

		return A;

	}

	else {

		int A = *ci++ - '0';

		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

		return A;

	}

}



pair<pair<int, int>, int> E[200002];

int H[100001];

int D[100001];

void dfs(int A, int B) {

	if (!D[A]) {

		D[A] = B;

		for (int i = H[A]; i; i = E[i].second) {

			dfs(E[i].first.first, B + E[i].first.second);

		}

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint();

	for (int i = 1; i < 2 * N - 2; i += 2) {

		int x = getint();

		int y = getint();

		int z = getint() & 1;

		E[i] = mp(mp(y, z), H[x]);

		H[x] = i;

		E[i + 1] = mp(mp(x, z), H[y]);

		H[y] = i + 1;

	}

	

	dfs(1, 1);

	const int dm = 1 << 18;

	char dn[dm], *di = dn;

	rep1(i, N) {

		if (D[i] & 1) *di++ = '0';

		else *di++ = '1';

		*di++ = '\n';

	}

	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}