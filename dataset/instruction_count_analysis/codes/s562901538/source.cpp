#include "stdc++.h"

#include <algorithm>

#include <queue>

using namespace std;

long long int pow2[61] = {}; 

long long int dp[300010] = {}; 

long long int pow3[61] = {}; 

long long int P = 1e9 + 7; 

long long int ans(long long int n){

	if(n < 300000 && dp[n] > -1){return dp[n];}

        if(n == 0){

         		return dp[0] = 1; 

        }

		int a = upper_bound(pow2, pow2 + 61, n) - pow2; 

		long long int b = pow2[a] - n; 

		if(b == 1){

			if(n < 300000){return dp[n] = (pow3[a] + 1)/2 % P;}

			else{return (pow3[a] + 1)/2 % P;}

		}

		else{

			long long int Q = (P + pow3[a-1] + ans(n - pow2[a-1]) - ((n == pow2[a] - 2) ? 0 : ans(pow2[a] - n - 3))) % P;

			if(n < 300000){return dp[n] = Q;}

			else{return Q;} 		

		} 

	}

int main() {

	pow2[0] = 1, pow3[0] = 1; 

	for(int i = 1; i <= 60; i++){

		pow2[i] = pow2[i-1] * 2; 

		pow3[i] = (pow3[i-1] * 3) % P; 

	}

	for(int i = 0; i < 300000; i++){

		dp[i] = -1;  

	}

	long long int N; 

	cin >> N; 

	cout << ans(N) << endl; 

}