#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

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

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please



char S[2000020];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(S, 1, 2000020, stdin);



	char* c = S, ct;

	int N = 0;

	

	while ((ct = *c++) >= '0') N = N * 10 + ct - '0';



	int L = 0, R = 2000001;

	while (L + 1 < R) {

		int M = (L + R) / 2;

		if (*(c + M) >= ' ') L = M;

		else R = M;

	}



	if (*c == '0') {

		printf("0\n");

		return 0;

	}



	for (char* d = c; d < c + R - 8; d += 7) {

		ll tmp = *(ll*)(d);

		tmp += 0x1010101010101010;

		tmp ^= 0xcfcfcfcfcfcfcfcf;



		ll tmp2 = tmp + 0x0001000100010001;

		if ((tmp2 << 1 ^ tmp2) & 0x2000200020002000) {

			printf("0\n");

			return 0;

		}

		tmp2 = tmp + 0x0000010001000100;

		if ((tmp2 << 1 ^ tmp2) & 0x0020002000200000) {

			printf("0\n");

			return 0;

		}

	}



	for (char* d = c + max(0, R - 10); d < c + R; d++) {

		if (*d == ' ' && *(d + 1) == '0') {

			printf("0\n");

			return 0;

		}

	}



	if (R >= N * 2 + 18) {

		printf("-1\n");

		return 0;

	}



	ll kotae = 1;

	auto owa = c + R;

	while (c < owa) {

		ll tmp = *(ll*)(c);

		if (tmp != 0x2031203120312031) {

			ll k = 0;

			while ((ct = *c++) >= '0') k = k * 10 + ct - '0';

			if (ll(1e18) / kotae < k) {

				printf("-1\n");

				return 0;

			}

			else kotae *= k;

		}

		else c += 8;

	}



	printf("%lld\n", kotae);



	Would you please return 0;

}