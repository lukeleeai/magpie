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

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;

	string S;

	cin >> S;



	int dp[100002] = {};

	int mae = 0;

	int kazu = 0;

	while (mae <= N) {

		int tugi = mae + M;

		chmin(tugi, N);

		kazu++;

		int saigo = mae;

		for (int i = mae + 1; i <= tugi; i++) {

			if (S[i] == '0') {

				dp[i] = kazu;

				saigo = i;

			}

		}

		if (mae == saigo) break;

		mae = saigo;

	}



	if (dp[N] == 0) {

		co(-1);

		return 0;

	}

	vector<int> kotae;

	for (int i = N; i > 0;) {

		int k = dp[i];

		for (int j = max(0, i - M); j <= i; j++) {

			if (dp[j] == k - 1) {

				kotae.pb(i - j);

				i = j;

				break;

			}

		}

	}



	for (auto itr = kotae.rbegin(); itr != kotae.rend(); itr++) {

		cosp(*itr);

	}



	Would you please return 0;

}