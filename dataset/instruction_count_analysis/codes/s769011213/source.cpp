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



const int N = 3002;

const int MOD = 998244353;



typedef long long ll;



int add(int a, int b) {

	if (a + b >= MOD) {

		return a + b - MOD;

	} else {

		return a + b;

	}

}



int mul(int a, int b) {

	return ((ll)a * b) % MOD;

}



int pw[N];

int dp[N][N];





void init() {

	pw[0] = 1;

	for (int i = 1; i < N; i++) {

		pw[i] = mul(2, pw[i - 1]);

	}

}



signed main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);



	int n, s;

	cin >> n >> s;

	vector<int> a(n);

	for (auto &t : a) {

		cin >> t;

	}

	int ans = 0;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= s + 1; j++) {

			//tk

			int nw = min(s + 1, j + a[i]);

			if (j == 0) {

				dp[i + 1][nw] = i + 1;

			} else {

				dp[i + 1][nw] = add(dp[i + 1][nw], dp[i][j]);

			}

			//

			dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);

		}

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= s + 1; j++) {

			if (j + a[i] == s) {

				if (j > 0)

					ans = add(ans, mul(dp[i][j], n - i));

				else 

					ans = add(ans, mul(i + 1, n - i));

			}

		}

	}

	cout << ans << endl;

} 	




