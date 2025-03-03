//解説すごいなー



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



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint();

	pair<int, int> XY[200000];

	int saidai = 0;

	int saishou = 1e9;

	int saidai2 = 0;

	int saishou2 = 1e9;

	rep(i, N) {

		int x = getint();

		int y = getint();

		if (x > y) swap(x, y);

		saidai = max(saidai, y);

		saidai2 = max(saidai2, x);

		saishou = min(saishou, x);

		saishou2 = min(saishou2, y);

		*(XY + i) = mp(x, y);

	}

	ll kotae = 1ll * (saidai - saishou2) * (saidai2 - saishou);



	sort(XY, XY + N);



	int saidai3 = saidai2;

	int saishou3 = 1e9;

	int mae = saishou;

	rep(i, N) {

		if ((*(XY + i)).first != mae) {

			kotae = min(kotae, 1ll * (saidai - saishou) * (saidai3 - min((*(XY + i)).first, saishou3)));

		}

		saidai3 = max(saidai3, (*(XY + i)).second);

		saishou3 = min(saishou3, (*(XY + i)).second);

		mae = (*(XY + i)).first;

	}

	kotae = min(kotae, 1ll * (saidai - saishou) * (saidai3 - saishou3));

	co(kotae);



	Would you please return 0;

}