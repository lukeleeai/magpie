#include <cstdio>

#include <algorithm>



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



int d = 1;

bool D[10001];

int H[10001], topo[10001];

pair<int, int> E[20002];

void dfs(int A) {

	if (!D[A]) {

		D[A] = true;

		topo[A] = d;

		d++;

		for (int i = H[A]; i; i = E[i].second) {

			dfs(E[i].first);

		}

	}

}



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 8 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {





	int N = getint();

	for (int i = 2; i < 2 * N; i += 2) {

		int a = getint(), b = getint();

		E[i] = mp(a, H[b]);

		H[b] = i;

		E[i + 1] = mp(b, H[a]);

		H[a] = i + 1;

	}



	int C[10000];

	int goukei = 0;

	rep(i, N) {

		C[i] = getint();

		goukei += C[i];

	}

	sort(C, C + N);



	dfs(1);



	const int dm = 1 << 17;

	char dn[dm], * di = dn;

	int X = goukei - C[N - 1];

	int keta = 0;

	char c[10];

	while (X) {

		*(c + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(c + i));

	*di++ = '\n';

	rep1(i, N) {

		X = C[N - topo[i]];

		keta = 0;

		while (X) {

			*(c + keta) = '0' + X % 10;

			X /= 10;

			keta++;

		}

		for (int i = keta - 1; i >= 0; i--)* di++ = (*(c + i));

		*di++ = ' ';

	}



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}