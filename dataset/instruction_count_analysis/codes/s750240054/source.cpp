#include "stdc++.h"



using namespace std;

typedef long long ll;



const int MAX_N = 55;



int n,a,x;

ll dp[MAX_N*MAX_N][MAX_N];



int main()

{

	cin >> n >> a;

	dp[0][0]=1;

	for (int i=1; i<=n; i++)

	{

		cin >> x;

		for (int k=n; k>=1; k--)

			for (int s=x; s<=n*a; s++)

				dp[s][k]+=dp[s-x][k-1];

	}

	ll ans=0;

	for (int k=1; k<=n; k++)

		ans+=dp[a*k][k];

	cout << ans;

	return 0;

}