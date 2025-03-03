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

char cn[cm], * ci = cn + cm, ct;

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



int D[1001][1001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), K = getint();



	int gyaku = 0;

	rep(i, N) {

		int x = getint(), y = getint();

		char c = getcha();

		getcha();

		int k = x / K ^ y / K;

		x = x % K;

		y = y % K;

		if (c == 'W' ^ (k & 1)) {

			gyaku++;

			D[x][y]--;

		}

		else D[x][y]++;

	}



	for (int i = K - 1; i >= 0; i--) {

		for (int j = K - 1; j >= 0; j--) {

			D[i][j] += D[i][j + 1] + D[i + 1][j] - D[i + 1][j + 1];

		}

	}

	int saidai = -1e9;

	rep(i, K) rep(j, K) {

		int kari = D[i][0] + D[0][j] - D[i][j] - D[i][j];

		saidai = max(saidai, kari);

		saidai = max(saidai, D[0][0] - kari);

	}

	printf("%d", gyaku + saidai);



	Would you please return 0;

}