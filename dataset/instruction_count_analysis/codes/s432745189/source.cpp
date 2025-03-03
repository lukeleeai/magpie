#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

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

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int D = getint();

	ll kotae = (N - 1) * (ll)D;

	int A[200001];

	int C[200001];

	C[0] = 1e9;

	rep1(i, N) {

		A[i] = getint();

		kotae += A[i];

		C[i] = min(C[i - 1] + D, A[i]);

	}

	int mae = 1e9;

	for (int i = N - 1; i > 1; i--) {

		mae = min(mae + D, A[i + 1]);

		kotae += min(A[i], min(mae, C[i - 1]) + D);

	}

	printf("%lld", kotae);



	Would you please return 0;

}