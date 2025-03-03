#include"stdc++.h"

using namespace std;

int main() {

	int n, a[1000][1000], dp[1000][1000];

	cin >> n;

	for(int i = 0; i <= 2; i++)

		for(int j = 0; j <= n; j++)

			dp[i][j] = 0;

	for(int i = 1; i <= 2; i++)

		for(int j = 1; j <= n; j++)

			cin >> a[i][j];

	for(int i = 1; i <= 2; i++)

		for(int j = 1; j <= n; j++)

			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];

	cout << dp[2][n];

}