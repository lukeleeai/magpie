#include <algorithm>

#include <iostream>

#include <cstring>

#include <vector>

using namespace std;



const int MAX_N = 3e5 + 15, MOD = 1e9 + 7;

string s;

int n, ans;

int dp[MAX_N][3][2][2][5];



int _sum (int a, int b) {

	int c = a + b;

	if (MOD <= c)

		c -= MOD;



	return c;

}



int _sub (int a, int b) {

	int c = a - b;

	if (c < 0)

		c += MOD;



	return c;

}



int _mul (int a, int b) {

	int c = 1LL * a * b % MOD;

	return c;

}



int _pow (int a, int b) {

	if (!b)

		return 1;



	int res = _pow(a, b >> 1);

	res = _mul(res, res);



	if (b & 1)

		res = _mul(res, a);

	return res;

}



int main() {

	ios::sync_with_stdio(false), cin.tie(0);

	cin >> s;

	n = s.size();

	s = '#' + s;



	int num = 0;

	for (int i = 1; i <= n; i++)

		num += s[i] == '?';



	if (s[1] != '0')

		dp[1][2][1][1][0] = 1;

	if (s[1] != '1')

		dp[1][2][0][1][2] = 1;



	for (int i = 1;  i < n; i++)

		for (int j = 0; j < 4; j++) {

			if (s[i + 1] != '1') {

				if (j) dp[i + 1][1][0][0][j - 1] = _sum(dp[i + 1][1][0][0][j - 1], dp[i][0][0][0][j]);

				if (j) dp[i + 1][2][0][1][j - 1] = _sum(dp[i + 1][2][0][1][j - 1], dp[i][0][0][1][j]);



				dp[i + 1][0][0][0][j + 1] = _sum(dp[i + 1][0][0][0][j + 1], dp[i][0][1][0][j]);

				dp[i + 1][2][0][1][j + 1] = _sum(dp[i + 1][2][0][1][j + 1], dp[i][0][1][1][j]);



				dp[i + 1][0][0][0][j + 1] = _sum(dp[i + 1][0][0][0][j + 1], dp[i][1][0][0][j]);

				dp[i + 1][0][0][0][j + 1] = _sum(dp[i + 1][0][0][0][j + 1], dp[i][1][0][1][j]);



				dp[i + 1][1][0][0][j + 1] = _sum(dp[i + 1][1][0][0][j + 1], dp[i][1][1][0][j]);

				dp[i + 1][1][0][0][j + 1] = _sum(dp[i + 1][1][0][0][j + 1], dp[i][1][1][1][j]);



				dp[i + 1][0][0][1][j + 1] = _sum(dp[i + 1][0][0][1][j + 1], dp[i][2][0][1][j]);

				dp[i + 1][1][0][1][j + 1] = _sum(dp[i + 1][1][0][1][j + 1], dp[i][2][1][1][j]);

			}

			if (s[i + 1] != '0' && j) {

				dp[i + 1][0][1][0][j - 1] = _sum(dp[i + 1][0][1][0][j - 1], dp[i][0][0][0][j]);

				dp[i + 1][0][1][0][j - 1] = _sum(dp[i + 1][0][1][0][j - 1], dp[i][0][0][1][j]);



				dp[i + 1][1][1][0][j - 1] = _sum(dp[i + 1][1][1][0][j - 1], dp[i][0][1][0][j]);

				dp[i + 1][1][1][0][j - 1] = _sum(dp[i + 1][1][1][0][j - 1], dp[i][0][1][1][j]);



				dp[i + 1][1][1][0][j - 1] = _sum(dp[i + 1][1][1][0][j - 1], dp[i][1][0][0][j]);

				dp[i + 1][2][1][1][j - 1] = _sum(dp[i + 1][2][1][1][j - 1], dp[i][1][0][1][j]);



				dp[i + 1][1][1][0][j - 1] = _sum(dp[i + 1][1][1][0][j - 1], dp[i][1][1][0][j]);

				dp[i + 1][1][1][0][j - 1] = _sum(dp[i + 1][1][1][0][j - 1], dp[i][1][1][1][j]);



				dp[i + 1][0][1][1][j - 1] = _sum(dp[i + 1][0][1][1][j - 1], dp[i][2][0][1][j]);

				dp[i + 1][1][1][1][j - 1] = _sum(dp[i + 1][1][1][1][j - 1], dp[i][2][1][1][j]);

			}

		}



	for (int i = 0; i < 3; i++)

		for (int j = 0; j < 2; j++)

			for (int t = 0; t < 2; t++)

				for (int k = 1; k < 4; k++)

					ans = _sum(ans, dp[n][i][j][t][k]);



	cout << _sub(_pow(2, num), ans) << "\n";

	return 0;

}