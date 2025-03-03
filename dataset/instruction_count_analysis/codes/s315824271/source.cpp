//お勉強中

//これは高速ゼータ変換の応用なの？



#include"stdc++.h"

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



const int cm = 1 << 16;

char cn[cm], * ci = cn;

inline int getint() {

	char C = *ci++;

	int A = C - '0';

	while ((C = *ci++) >= '0') A = A * 10 + C - '0';

	return A;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, cm, stdin);



	int N = getint(), M = getint();

	int n = 1 << N;

	int dp[1 << 12];

	rep(i, n) dp[i] = 1e9;



	rep(i, M) {

		int A = getint();

		int B = getint();

		int C = 0;

		rep(j, B) {

			int c = getint();

			C += 1 << (c - 1);

		}

		dp[C] = min(dp[C], A);

	}



	rep(j, N) {

		rep (i, n) {

			if (!(i >> j & 1)) dp[i] = min(dp[i], dp[i | 1 << j]);

		}

	}



	rep1(i, n - 1) {

		for (int j = i - 1 & i; j > 0; j = j - 1 & i) {

			dp[i] = min(dp[i], dp[j] + dp[i ^ j]);

		}

	}



	if (dp[n - 1] >= 1e9) printf("-1");

	else printf("%d", dp[n - 1]);





	Would you please return 0;

}