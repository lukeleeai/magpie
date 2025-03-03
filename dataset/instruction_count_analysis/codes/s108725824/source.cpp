//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

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

char cn[cm], * ci = cn + cm;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	char C = getcha();

	int A = C - '0';

	while ((C = getcha()) >= '0') A = A * 10 + C - '0';

	return A;

}



const int dm = 1 << 21;

char dn[dm], * di = dn;

inline void putint(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--) *di++ = (*(C + i));

	*di++ = '\n';

}

int n;

char c[6];

inline void putsaidai() {

	for (int i = n - 1; i >= 0; i--) *di++ = c[i];

	*di++ = '\n';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int A[200000];

	

	int saidai = 0;

	int niban = 0;

	rep(i, N) {

		A[i] = getint();

		if (niban < A[i]) {

			niban = A[i];

			if (niban > saidai) swap(niban, saidai);

		}

	}



	int kari = saidai;

	while (kari) {

		*(c + n) = '0' + kari % 10;

		kari /= 10;

		n++;

	}



	rep(i, N) {

		if (A[i] == saidai) putint(niban);

		else putsaidai();

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}