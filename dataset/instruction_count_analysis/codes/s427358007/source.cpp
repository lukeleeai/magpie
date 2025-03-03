#pragma GCC optimize ("O2")

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



const ll mod = 100000000000000003;

int ne[200001], he[10001];

char C[1200100];



int num[2097153];

int kazu[2097153];

int atta[1000001];

const int ma = (1 << 21) - 1;

int cnt = 0;

int query(int n) {

	int n2 = (n & ma) + 1;

	while (num[n2]) {

		if (num[n2] == n + 1) return kazu[n2];

		n2 = n2 * 61 % 2097143;

	}

	num[n2] = n + 1;

	return kazu[n2] = ++cnt;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(C, 1, 1200100, stdin);

	char* ci = C, c;

	int N = 0;

	while ((c = *ci++) >= '0') N = N * 10 + c - '0';



	ll dekai[100];

	int d = 0;

	char* s[200001];

	rep1(i, N) {

		s[i] = ci;

		while (*ci++ >= '0');

		int n = ci - s[i] - 1;

		if (n <= 100000) {

			ne[i] = he[n];

			he[n] = i;

		}

		else {

			dekai[d++] = (ll(n) << 30) + s[i] - C;

		}

	}



	ll kotae = 0;

	for (int M = 1; M <= 10000; M++) {

		for (int p = he[M]; p; p = ne[p]) {

			auto S = s[p];

			int k[26] = {};

			int mae = 0;

			for (int i = M - 1; i >= 1; i--) {

				int tmp = atta[mae];

				if (tmp) {

					rep(j, 26) if ((tmp >> j & 1)) {

						k[j]++;

					}

				}

				int ct = S[i] - 'a';

				mae = query((mae << 5) + ct);

				kotae += k[ct];

				k[ct] = 0;

			}



			kotae += k[S[0] - 'a'];

			k[S[0] - 'a'] = 0;



			atta[mae] |= 1 << (S[0] - 'a');

		}

	}

	sort(dekai, dekai + d);

	rep(p, d) {

		auto S = C + (dekai[p] & ma);

		int k[26] = {};

		int mae = 0;

		for (int i = (dekai[p] >> 30) - 1; i >= 1; i--) {

			int tmp = atta[mae];

			if (tmp) {

				rep(j, 26) if ((tmp >> j & 1)) {

					k[j]++;

				}

			}

			int ct = S[i] - 'a';

			mae = query((mae << 5) + ct);

			kotae += k[ct];

			k[ct] = 0;

		}



		kotae += k[S[0] - 'a'];

		k[S[0] - 'a'] = 0;



		atta[mae] |= 1 << (S[0] - 'a');

	}

	printf("%lld\n", kotae);





	Would you please return 0;

}