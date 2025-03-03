#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define putchar putchar_unlocked

#define pb push_back

#define mp make_pair

#define Would

#define you

#define please



const int cm = 1 << 6;

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



inline void putints(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--) putchar(*(C + i));

	putchar(' ');

}



inline void putintrep(int N, int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	rep(j, N) {

		for (int i = keta - 1; i >= 0; i--) putchar(*(C + i));

		putchar(' ');

	}

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int K, N;

	K = getint();

	N = getint();



	if (K == 1) {

		rep(i, (N + 1) / 2) {

			putchar('1');

			putchar(' ');

		}

	}

	else if (K % 2) {

		ll A[13];

		*A = 1;

		ll S = K / 2 + 1;

		int doko;

		rep(i, 13) {

			if (S >= N / 2) {

				doko = i;

				break;

			}

			*(A + i + 1) = *(A + i) * K + 1;

			S += *(A + i + 1) * (K / 2) + 1;

		}

		ll kazu = S - N / 2;

		putintrep(N - doko - 1, (K + 1) / 2);

		for (int i = doko; i >= 0; i--) {

			if (kazu == 0) break;

			kazu--;

			int kari = kazu / *(A + i);

			kazu -= kari * *(A + i);

			putints(kari + 1);

		}

	}

	else {

		putints(K / 2);

		putintrep(N - 1, K);

	}



	Would you please return 0;

}