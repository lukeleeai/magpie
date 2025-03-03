#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>



#include <vector>



using namespace std;



const int maxN = 50 + 10;

long long dp[maxN][2], arr[maxN];

int n, p;



int main(){

	//freopen("in.txt", "r", stdin);

	//freopen("out.txt", "w", stdout);

	

	memset(dp, 0, sizeof(dp));

	

	cin>>n>>p;

	for(int i=1;i<=n;i++)cin>>arr[i];

	

	dp[0][0] = 1, dp[0][1] = 0;

	for(int i=1;i<=n;i++){

		if(arr[i]%2==0){

			dp[i][0] += dp[i-1][0] * 2;

			dp[i][1] += dp[i-1][1] * 2;

		}

		if(arr[i]%2==1){

			dp[i][0] += dp[i-1][1] + dp[i-1][0];

			dp[i][1] += dp[i-1][0] + dp[i-1][1];

		}

	}

	//long long ans = 0;

	//for(int i=0;i<=n;i++)ans += dp[i][p];

	cout<<dp[n][p]<<endl;

	//for(int i=0;i<=n;i++)cout<<dp[i][0]<<' ';cout<<endl;

	//for(int i=0;i<=n;i++)cout<<dp[i][1]<<' ';cout<<endl;

	

	return 0;

}