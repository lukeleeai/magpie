#include "stdc++.h"

using namespace std;



int main() {

	// your code goes here

	cin.tie(NULL);

	cout.tie(NULL);

	

	long long n,k;

	

	while(cin>>n && cin>>k)

	{

		vector<long long>cost(n);

		

		for(int i=0;i<n;i++)cin>>cost[i];

		

		vector<long long>dp(n,INT_MAX);

		

		dp[0] = 0;

		dp[1] = abs(cost[1]-cost[0]);

		

		for(int i=2;i<n;i++)

		{

			for(int j=i-1;j>=0 && j>=i-k;j--)

			{

				dp[i] = min(dp[i],dp[j]+abs(cost[i]-cost[j]));

			}

		}

		

		cout<<dp[n-1]<<endl;

	}

	return 0;

}