#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



const int dm = 1 << 18;

char dn[dm], * di = dn;

inline void putint(int X) {

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = ' ';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, M;

	scanf("%d", &N);

	scanf("%d", &M);

	char S[100001];

	scanf("%s", S);





	if (M == 1) {

		int OK = 1;

		rep(i, N + 1) if (S[i] == '1') OK = 0;

		if (OK) {

			rep(i, N) {

				*di++ = '1';

				*di++ = ' ';

			}

		}

		else {

			*di++ = '-';

			*di++ = '1';

			*di++ = '\n';

		}

	}

	else {

		int kotae[100001];

		int k = 0;

		for (int i = N; i > 0;) {

			int atta = 0;

			for (int j = max(0, i - M); j < i; j++) {

				if (S[j] == '0') {

					kotae[k++] = i - j;

					i = j;

					atta = 1;

					break;

				}

			}

			if (atta == 0) {

				printf("-1\n");

				return 0;

			}

		}

		for (int i = k - 1; i >= 0; i--) {

			putint(kotae[i]);

		}

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}