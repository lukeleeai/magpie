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



const int cm = 1 << 12;

char cn[cm], * ci = cn;

inline int getint() {

	char C = *ci++;

	int A = C - '0';

	while ((C = *ci++) >= '0') A = A * 10 + C - '0';

	return A;

}



const int dm = 1 << 20;

char dn[dm], * di = dn;

inline void putint(int X) {

	int keta = 0;

	char C[3];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, cm, stdin);



	int N = getint();

	pair<int, int> X[1001] = {};

	X[0].first = 0;

	rep1(i, N) {

		X[i].first = getint();

		X[i].second = i;

	}



	sort(X + 1, X + N + 1);



	int num[1001] = {};

	rep1(i, N) num[i] = X[i].second - 1;



	int q = 1, q2 = N + 1;

	int OK = 1;

	rep1(i, N) {

		for (int j = X[i - 1].first + 1; j < X[i].first; j++) {

			while (q <= N * 2 && num[q] == 0) q++;

			if (q == N * 2 + 1) {

				OK = 0;

				break;

			}

			if (X[q].first < j) {

				OK = 0;

				break;

			}

			num[q]--;

			putint(X[q].second);

		}

		num[q2] = N - X[i].second;

		X[q2].second = X[i].second;

		X[q2++].first = 300000;

		putint(X[i].second);

	}

	for (int j = X[N].first + 1; j <= N * N; j++) {

		while (q <= N * 2 && num[q] == 0) q++;

		if (q == N * 2 + 1) {

			OK = 0;

			break;

		}

		if (X[q].first < j) {

			OK = 0;

			break;

		}

		num[q]--;

		putint(X[q].second);

	}



	if (OK) {

		printf("Yes\n");

		fwrite(dn, 1, di - dn, stdout);

	}

	else printf("No\n");



	Would you please return 0;

}