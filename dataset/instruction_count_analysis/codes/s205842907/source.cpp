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



int P[100001];

int K[100001];



int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint();



	pair<int, int> E[100010];

	int H[100010] = {};

	rep1(i, N) {

		int x = getint(), y = getint();

		E[i] = mp(y, H[x]);

		H[x] = i;

	}



	rep1(i, 100000) P[i] = -1;



	rep1(i, 100000) {

		if (H[i]) {

			int a = Find(E[H[i]].first);

			for (int j = E[H[i]].second; j; j = E[j].second) {

				int b = Find(E[j].first);



				if (a == b) continue;

				if (P[a] > P[b]) swap(a, b);

				P[a] += P[b];

				P[b] = a;

				K[a] += K[b];

			}

			K[a]++;

		}

	}



	ll kotae = 0;

	rep1(i, 100000) {

		if (K[i] && P[i] < 0) {

			kotae -= 1ll * K[i] * P[i];

		}

	}

	co(kotae - N);



	Would you please return 0;

}