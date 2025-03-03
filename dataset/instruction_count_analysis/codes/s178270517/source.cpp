#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<string>

#include<cstring>

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



const int dm = 1 << 22;

char dn[dm], *di = dn;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	//cのstringがはやいのかしら？勉強が必要ですね



	int N, K;

	char S[20];

	scanf("%d", &N);

	scanf("%d", &K);

	scanf("%s", S);

	int s = atoi(S);



	int L = strlen(S);

	S[L++] = ' ';	



	int tot = 0;

	if (K) {

		int n = 1;

		strcpy(di, S);

		di += L;

		while (n * 2 <= K) {

			strncpy(di, dn, n * L);

			di += L * n;

			n *= 2;

		}

		int nokori = K - n;

		strncpy(di, dn, nokori * L);

		di += L * nokori;

		tot += L * K;

	}



	if (N - K) {

		int n = 1;

		int p;

		if (L <= 6) {

			rep1(i, 10) if (s % i) {

				p = i;

				break;

			}

		}

		else p = 1;

		char S2[3];

		S2[0] = '0' + p;

		S2[1] = ' ';

		L = 2;

		auto dn2 = di;

		strcpy(di, S2);

		di += L;

		while (n * 2 <= N - K) {

			strncpy(di, dn2, n * L);

			di += L * n;

			n *= 2;

		}

		int nokori = N - K - n;

		strncpy(di, dn2, nokori * L);

		di += L * nokori;

		tot += L * (N - K);

	}



	fwrite(dn, 1, tot, stdout);









	Would you please return 0;

}