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



//なんこれ？



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



const int dm = 1 << 21;

char dn[dm], * di = dn;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N = getint();

	int X[200000], X2[200000];

	rep(i, N) X2[i] = (X[i] = getint());



	//int L = 0;

	//int R = 1e9 + 1;

	//while (L < R) {

	//	int H = (L + R) / 2;

	//	int k = 0;

	//	rep(i, N) k += X[i] <= H;

	//	if (k < N / 2) L = H + 1;

	//	else R = H;

	//}

	//int L2 = L;

	//int R2 = 1e9 + 1;

	//while (L2 < R2) {

	//	int H = (L2 + R2) / 2;

	//	int k = 0;

	//	rep(i, N) k += X[i] <= H;

	//	if (k < N / 2 + 1) L2 = H + 1;

	//	else R2 = H;

	//}



	nth_element(X, X + N / 2, X + N);

	nth_element(X, X + N / 2 - 1, X + N / 2);

	int L = X[N / 2 - 1];

	int L2 = X[N / 2];

	int K = L;

	int keta1 = 0, keta2 = 0;

	char C1[10], C2[10];

	while (L) {

		*(C1 + keta1) = '0' + L % 10;

		L /= 10;

		keta1++;

	}

	while (L2) {

		*(C2 + keta2) = '0' + L2 % 10;

		L2 /= 10;

		keta2++;

	}



	rep(i, N) {

		if (X2[i] > K) {

			for (int i = keta1 - 1; i >= 0; i--)* di++ = (*(C1 + i));

			*di++ = '\n';

		}

		else {

			for (int i = keta2 - 1; i >= 0; i--)* di++ = (*(C2 + i));

			*di++ = '\n';

		}

	}



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}