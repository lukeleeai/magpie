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

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, M;

	cin >> N >> M;

	int A[100001] = {};

	rep(i, M) {

		int a;

		cin >> a;

		A[a] = 1;

	}



	ll dp[100001] = {};

	dp[0] = 1;

	ll mod = 1e9 + 7;



	rep1(i, N) {

		if (A[i] == 0) {

			dp[i] = dp[i - 1];

			if (i - 2 >= 0) dp[i] += dp[i - 2];

			dp[i] %= mod;

		}

	}



	co(dp[N]);



	Would you please return 0;

}