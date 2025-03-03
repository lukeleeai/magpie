#include <iostream>

#include <vector>

#include <algorithm>

#include <cstring>



using namespace std;



const int MOD = 1000000007;



int main(){

	int N, W;

	static int dp[201][10001];

	while(cin >> N >> W){

		vector<int> w(N);

		for(int i=0;i<N;i++) cin >> w[i];

		sort(w.begin(), w.end());

		memset(dp, 0, sizeof(dp));

		dp[N][0] = 1;

		for(int i=N-1;i>=0;i--){

			for(int j=i+1;j<=N;j++){

				for(int k=W;k>=0;k--){

					dp[i][k] = (dp[i][k]+dp[j][k])%MOD;

					if(k+w[i]<=W) dp[j][k+w[i]] = (dp[j][k+w[i]]+dp[j][k])%MOD;

					dp[j][k] = 0;

				}

			}

		}

		int res = 0;

		for(int i=0;i<=N;i++){

			for(int j=0;j<=W;j++){

				if(i==N || j+w[i] > W) res = (res+dp[i][j])%MOD;

			}

		}

		cout << res << endl;

	}

}