#include "stdc++.h"

using namespace std;



int dp[110][100100], n, k, l[110];



int main(){



	scanf("%d %d", &n, &k);

	

	for(int i = 0; i < n; i++) scanf(" %d", &l[i]);

	

	for(int i = n - 1; i >= 0; i--){

		

		for(int j = 0; j < k + 1; j++){

			if(i == n - 1) dp[i][j] = j <= l[i];

			else dp[i][j] = dp[i + 1][j] - ((j < l[i] + 1) ? 0 : dp[i + 1][j - l[i] - 1]);

			if(dp[i][j] < 0) dp[i][j] += 1000000007;

		}

		

		if(i != 0) {for(int j = 1; j < k + 1; j++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;}

	}

	

	printf("%d", dp[0][k] % 1000000007);

			

	return 0;

}
