#include "stdc++.h"

#include <algorithm>

#include <string>

using namespace std;

int main(){

	int H, W, K; 

	cin >> H >> W >> K; 

	long long int dp[110][10] = {}; 

	long long int P = 1e9 + 7; 

	int Fib[8] = {1, 1, 2, 3, 5, 8, 13, 21}; 

	if(W == 1){cout << 1 << endl; }

	else{

	dp[0][1] = 1; 

	for(int i = 1; i < 105; i++){

		dp[i][1] = ((dp[i-1][1] * Fib[W-1]) % P + (dp[i-1][2] * Fib[W-2]) % P) % P; 

		dp[i][W] = ((dp[i-1][W] * Fib[W-1]) % P + (dp[i-1][W-1] * Fib[W-2]) % P) % P; 

		for(int j = 2; j < W; j++){

			dp[i][j] = ((dp[i-1][j-1] * Fib[j-2] * Fib[W-j]) % P + (dp[i-1][j] * Fib[j-1] * Fib[W-j]) % P + (dp[i-1][j+1] * Fib[j-1] * Fib[W-j-1]) % P ) % P; 

	}

        }

	cout << dp[H][K] << endl; 

	}

}


