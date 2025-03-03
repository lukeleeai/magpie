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

	int A[200000];

	rep(i, N) A[i] = getint();



	ll AB[200000];

	ll keiAB = A[0], saA = A[0];

	int p = 0;



	for (int i = 1; i < N - 2; i++) {

		keiAB += A[i];

		saA -= A[i];

		while (p + 1 < i && saA + A[p + 1] + A[p + 1] < 0) {

			p++;

			saA += A[p] + A[p];

		}

		ll kari = min(abs(saA), saA + A[p + 1] + A[p + 1]);

		AB[i] = kari;

	}

	ll S = keiAB + A[N - 2] + A[N - 1];



	ll kotae = 1e18;

	ll keiCD = A[N - 1], saD = A[N - 1];

	p = N - 1;

	for (int i = N - 2; i >= 2; i--) {

		keiCD += A[i];

		saD -= A[i];

		while (p - 1 > i && saD + A[p - 1] + A[p - 1] < 0) {

			p--;

			saD += A[p] + A[p];

		}

		ll kari = min(abs(saD), saD + A[p - 1] + A[p - 1]);



		kotae = min(kotae, max(S - keiCD + AB[i - 1], keiCD + kari) - min(S - keiCD - AB[i - 1], keiCD - kari));

	}

	co(kotae / 2);



	Would you please return 0;

}