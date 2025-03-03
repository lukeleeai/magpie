#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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





int BIT[200001];



void add(int A) {

	while (A > 0) {

		BIT[A]++;

		A -= A & -A;

	}

}



int query(int A) {

	int kotae = 0;

	while (A <= 200000) {

		kotae += BIT[A];

		A += A & -A;

	}

	return kotae;

}



int ne[200001], he[26];





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	char S[200000];

	scanf("%s", S);

	int N = strlen(S);

	bool k[26] = {};

	rep(i, N) {

		int c = S[i] - 'a';

		ne[i + 1] = he[c];

		he[c] = i + 1;

		k[c] ^= true;

	}

	int kisuu = 0;

	rep(i, 26) if (k[i] & 1) kisuu++;

	if (kisuu > 1) {

		printf("-1");

		return 0;

	}

	int kazu = 0;

	ll kotae = 0;

	int atta = 0;

	rep(i, N) {

		if (kazu * 2 >= N - 1) break;

		if (S[i] >= 'a') {

			int c = S[i] - 'a';

			int kari = he[c] - 1;

			he[c] = ne[he[c]];

			if (i == kari) {

				atta = 1;

				continue;

			}

			kotae += N - kari - 1 - query(kari) + atta;

			S[kari] = 0;

			add(kari);

			kazu++;

		}

	}

	printf("%lld", kotae);



	Would you please return 0;

}