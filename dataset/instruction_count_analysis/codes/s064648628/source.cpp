#include <algorithm>

#include <cstdio>

using namespace std;

const int M = 1000000007;

const int N = 2e5 + 10;

int n, dp[N], s[N], c[N];

int main() {

	scanf("%d", &n); dp[0] = 1;

	for(int i = 1; i <= n; i ++) {

		scanf("%d", c + i);

		if(c[i] == c[i - 1]) {

			i --; n --;

		}

	}

	for(int i = 1; i <= n; i ++) {

		dp[i] = (s[c[i]] + dp[i - 1]) % M;

		(s[c[i]] += dp[i - 1]) %= M;

	}

	printf("%d\n", dp[n]);

	return 0;

}
