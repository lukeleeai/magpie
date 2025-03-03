#include "stdc++.h"

using namespace std;



const int N = 305;



int n, K, mod;

int f[N][N], c[N][N], prf[N][N];



int main() {

	ios_base::sync_with_stdio(false);

	cin >> n >> K >> mod; n++, K++;

	for (int i = 0;i <= n;++i){

		c[i][0] = 1;

		for (int j = 1;j <= i;++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;

	}

	for (int i = 1;i <= n;++i) {

		for (int j = 1;j <= K;++j) {

			if (i == 1) f[i][j] = 1;

			else for (int k = 1;k < i;++k) {

				int cur = 1LL * c[i - 2][k - 1] * f[k][j] % mod;

				cur = 1LL * cur * prf[i - k][j - 1] % mod;

				f[i][j] = (f[i][j] + cur) % mod;

			} 

			prf[i][j] = (prf[i][j - 1] + f[i][j]) % mod;

		}

	}

	cout << f[n][K] << '\n';

}