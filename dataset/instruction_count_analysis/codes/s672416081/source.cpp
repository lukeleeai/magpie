#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

#include"stdc++.h"

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

int ne[200001], he[100001];

char C[1200100];



ll num[524300];

int kazu[524300];

const int ma = (1 << 19) - 1;

int query(ll n) {

	int n2 = (n & ma) + 1;

	while (num[n2]) {

		if (num[n2] == n + 1) return kazu[n2];

		n2 = n2 * 61 % 524287;

	}

	return 0;

}

void add(ll n, int b) {

	int n2 = (n & ma) + 1;

	while (num[n2]) {

		if (num[n2] == n + 1) {

			kazu[n2] |= b;

			return;

		}

		n2 = n2 * 61 % 524287;

	}

	num[n2] = n + 1;

	kazu[n2] = b;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	fread(C, 1, 1200100, stdin);

	char* ci = C, c;

	int N = 0;

	while ((c = *ci++) >= '0') N = N * 10 + c - '0';

	set<pair<int, char*>> ST;

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

			ST.insert(mp(n, s[i]));

		}

	}



	ll kotae = 0;



	for (int M = 1; M <= 100000; M++) {

		for (int p = he[M]; p; p = ne[p]) {

			auto S = s[p];

			int k[26] = {};

			ll are = 0;

			for (int i = M - 1; i >= 1; i--) {

				int tmp = query(are);

				rep(j, 26) if ((tmp >> j & 1)) {

					k[j]++;

				}

				kotae += k[S[i] - 'a'];

				k[S[i] - 'a'] = 0;

				are = (are * 30 + S[i] - 'a' + 1) % mod;

			}



			kotae += k[S[0] - 'a'];

			k[S[0] - 'a'] = 0;



			add(are, 1 << (S[0] - 'a'));

		}

	}

	for (auto p : ST) {

		auto S = p.second;

		int k[26] = {};

		ll are = 0;

		for (int i = p.first - 1; i >= 1; i--) {

			int tmp = query(are);

			rep(j, 26) if ((tmp >> j & 1)) {

				k[j]++;

			}

			kotae += k[S[i] - 'a'];

			k[S[i] - 'a'] = 0;

			are = (are * 30 + S[i] - 'a' + 1) % mod;

		}



		kotae += k[S[0] - 'a'];

		k[S[0] - 'a'] = 0;



		add(are, 1 << (S[0] - 'a'));

	}

	co(kotae);





	Would you please return 0;

}