#include "stdc++.h"

     

using namespace std;



map <int,double> dp[3000];



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



	dp[0][0] = 1;

	for(int i=0;i<n;i++)

	{

		for(auto it : dp[i])

		{

			dp[i+1][it.first - 1] += it.second*(1 - p[i]);

			dp[i+1][it.first + 1] += it.second*(p[i]);

		}

	}



	double res = 0;



	for(auto it : dp[n])

	{

		if(it.first > 0)

		{

			res += it.second;

		}

	}



	cout << fixed;

	cout.precision(9);

	

	cout << res << '\n';



	return 0;

}
