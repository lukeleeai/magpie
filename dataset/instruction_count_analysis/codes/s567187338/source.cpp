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

inline ll getint() {

	ll A = 0;

	if (ci - cn + 24 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

 

int dpA[100001], dpB[100001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);

 

 

	ll N = getint(), A = getint(), B = getint();

	ll S[100001];

	rep(i, N) S[i] = getint();

	S[N] = 3e18;

 

	const int mod = 1e9 + 7;

 

	int a = 1, b = 1;

	int ka = 0, kb = 0;

	dpA[0] = 1;

	dpB[0] = 1;

	rep(i, N - 1) {	

		while (S[i] + A > S[a]) {

			ka += (S[a - 1] + B > S[a++]);

		}

		while (S[i] + B > S[b]) {

			kb += (S[b - 1] + A > S[b++]);

		};

		ka -= (S[i + 1] - S[i] < B);

		kb -= (S[i + 1] - S[i] < A);

 

		if (S[i + 1] - S[i] >= A) {

			dpA[i + 1] = (dpA[i] + dpA[i + 1]) % mod;

			dpB[i + 1] = (dpA[i] + dpB[i + 1]) % mod;

		}

		else if (ka <= 0) dpB[a - 1] = (dpA[i] + dpB[a - 1]) % mod;

		

		if (S[i + 1] - S[i] >= B) {

			dpA[i + 1] = (dpB[i] + dpA[i + 1]) % mod;

			dpB[i + 1] = (dpB[i] + dpB[i + 1]) % mod;

		}

		else if (kb <= 0) dpA[b - 1] = (dpB[i] + dpA[b - 1]) % mod;

	}

	printf("%d\n", (dpA[N - 1] + dpB[N - 1]) % mod);

 

	Would you please return 0;

}