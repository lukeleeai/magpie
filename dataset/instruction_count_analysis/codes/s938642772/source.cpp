#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<vector>

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





	int N;

	cin >> N;



	double dp[1501] = {};

	dp[0] = 1.0;

	int M = N / 2;



	rep(i, N) {

		double P;

		cin >> P;

		for (int j = min(M, i); j >= max(0, i - M); j--) {

			dp[j + 1] += dp[j] * P;

			dp[j] *= 1 - P;

		}

	}



	cout << setprecision(15) << dp[M + 1] << endl;



	Would you please return 0;

}