#include "stdc++.h"

     

using namespace std;



double dp[3010][3010];



int main(void)

{

	cin.tie(0);

	ios::sync_with_stdio(false);



	int n;

	double t;

	vector <double> p;



	cin >> n;

	for(int i=0;i<n;i++)

	{

		cin >> t;

		p.push_back(t);

	}



	dp[0][0] = 1 - p[0];

	dp[0][1] = p[0];



	for(int i=1;i<n;i++)

	{

		for(int j=0;j<=n;j++)

		{

			dp[i][j] += (dp[i-1][j])*(1 - p[i]);

			dp[i][j+1] += (dp[i-1][j])*(p[i]);

		}

	}



	double res = 0;



	for(int i=(n/2)+1;i<=n;i++)

	{

		res += dp[n-1][i];

	}



	cout << fixed;

	cout.precision(9);



	cout << res << '\n';



	return 0;

}
