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





	string S;

	cin >> S;

	int N = S.size();



	int dp0 = 0;

	int dp1 = 1e9;

	for (int i = N - 1; i >= 0; i--) {

		int s = S[i] - '0';



		int tmp0 = dp0 + s;

		int tmp1 = dp1 + (9 - s);

		chmin(tmp0, dp1 + s + 1);

		chmin(tmp1, dp0 + (10 - s));



		dp0 = tmp0;

		dp1 = tmp1;

	}



	co(min(dp0, dp1 + 1));





	Would you please return 0;

}