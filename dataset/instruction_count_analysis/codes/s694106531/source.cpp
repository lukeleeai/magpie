#include <iostream>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <string>

#include <cmath>

#include <cstdio>

#include <iomanip>

#include <fstream>

#include <cassert>

#include <cstring>

#include <unordered_set>

#include <unordered_map>

#include <numeric>

#include <ctime>

#include <bitset>

#include <complex>

#include <random>



using namespace std;



// #define int long long



const int N = 3002;

const int MOD = 998244353;



typedef long long ll;



int add(int a, int b) {

	// assert(a < MOD);

	// assert(b < MOD);

	if (a + b >= MOD) {

		return a + b - MOD;

	} else {

		return a + b;

	}

}



int mul(int a, int b) {

	return ((ll)a * b) % MOD;

}



vector<vector<int>> calc(vector<int> &a) {

	int n = (int)a.size();

	vector<vector<int>> dp(n + 1, vector<int> (N));

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < N; j++) {

			if (j + a[i] < N) {

				dp[i + 1][j + a[i]] = add(dp[i + 1][j + a[i]], dp[i][j]);

			}

			dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);

		}

	}

	vector<vector<int>> rdp(n + 1, vector<int> (N));

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < N; j++) {

			if (j >= a[i - 1]){

				rdp[i][j] = dp[i - 1][j - a[i - 1]]; 

			}

		}

	}

	rdp[0][0] = 1;

	return rdp;

}



int n, s;

int a[N];



int solve(int l, int r) {

	if (l == r) {

		return 0;

	}

	if (l + 1 == r) {

		if (a[l] == s) {

			return (l + 1) * (n - l);

		} else {

			return 0;

		}

	}

	int m = (r + l) >> 1;

	int ans = 0;

	ans = add(ans, solve(l, m));

	ans	= add(ans, solve(m, r));

	vector<int> x, y;

	for (int i = l; i < r; i++) {

		if (i < m) x.push_back(a[i]);

		else y.push_back(a[i]);

	}

	reverse(x.begin(), x.end());

	auto fdp = calc(x);

	auto sdp = calc(y);

	vector<int> tsum(s);

	for (int fs = 0; fs < s; fs++) {

		if (s - fs >= N) continue;

		int c = 0;

		for (int j = m; j < r; j++) {

			c = add(c, mul(sdp[j - m + 1][s - fs], (n - j)));

		}

		tsum[fs] = c;

	}

	for (int i = l; i < m; i++) {

		for (int fsum = 1; fsum < s; fsum++) {

			int ml = mul((i + 1), fdp[m - i][fsum]);

			int c = tsum[fsum];

			ans = add(ans, mul(c, ml));

		}

	}

	return ans;

}



signed main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);



	cin >> n >> s;

	// n = 100;

	// s = 10;

	for (int i = 0; i < n; i++) {

		cin >> a[i];

		// a[i] = 1;

	}

	int ans = solve(0, n);

	cout << ans << endl;

	// vector<int> b = {1, 5};

	// calc(b);

} 
