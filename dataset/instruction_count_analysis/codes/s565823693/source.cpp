#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, P;

	cin >> N >> P;

	string s;

	cin >> s;



	if (P == 2) {

		ll kotae = 0;

		rep(i, N) {

			if((s[i] - '0') % 2 == 0) kotae += i + 1;

		}

		co(kotae);

		return 0;

	}

	if (P == 5) {

		ll kotae = 0;

		rep(i, N) {

			if ((s[i] - '0') % 5 == 0) kotae += i + 1;

		}

		co(kotae);

		return 0;

	}



	map<int, int> MP;

	MP[0] = 1;

	ll kotae = 0;

	int ima = 1;

	int mae = 0;

	rep(i, N) {

		int a = s[N - 1 - i] - '0';

		a = (a * ima + mae) % P;

		kotae += MP[a];

		MP[a]++;

		mae = a;



		ima = ima * 10 % P;

	}



	co(kotae);



	Would you please return 0;

}