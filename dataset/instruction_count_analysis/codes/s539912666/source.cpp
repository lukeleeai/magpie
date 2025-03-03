#include <iostream>



using namespace std;

const int mod = 100000;



int dp[2][2001][3001];



int main(int argc, char const* argv[])

{

	int n, m, s;

	do{

			cin >> n >> m >> s;

			if(n == 0)break;

			for(int i = 0; i < n * n; i++){

					for(int j = 1; j <= m; j++){

							for(int k = 1; k <= s; k++){

									if(i == 1){

											if(j < k)dp[1][j][k] = 0;

											else dp[1][j][k] = 1;

									}

									dp[(i + 1) & 1][j][k] = dp[(i + 1) & 1][j-1][k];

									if(k -j >= 0)dp[(i + 1) & 1][j][k] += dp[i & 1][j-1][k-j];

									dp[(i + 1) & 1][j][k] %= mod;

									// cout << i << " " << j << " " << k << " " << dp[(i + 1) & 1][j][k] << endl;

							}

					}

			}

			cout << dp[(n*n) & 1][m][s] << endl;

	}while(true);

	return 0;

}


