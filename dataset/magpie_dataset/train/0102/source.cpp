#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <queue>

#include <set>

#include <map>

#include <string.h>

#include <cmath>



using namespace std;

typedef long long i64;

typedef long double ld;

typedef pair<i64,i64> P;

#define rep(i,s,e) for(int (i) = (s);(i) <= (e);++(i))



int n;



i64 c[1010];

i64 w[1010];



i64 sum[1010];



int dp[1010][1010];



int main()

{

	cin >> n;

	rep(i,0,n - 1)

		cin >> c[i] >> w[i];



	rep(i,1,n)

	{

		sum[i] = sum[i - 1] + w[i - 1];

	}



	auto getsum = [&](int l,int r){

		return sum[r] - sum[l];

	};



	rep(i,0,1000) rep(j,0,1000) dp[i][j] = 1e9;



	rep(i,0,1000)

		dp[i][i + 1] = 1;

	

	rep(w,2,n)

	{

		rep(l,0,n - 1)

		{

			//[l,r)

			int r = l + w;

			if(r > n) continue;



			rep(mid,l + 1,r - 1)

			{

				dp[l][r] = min(dp[l][r] , dp[l][mid] + dp[mid][r]);

			}



			//left is mighty

			{



				i64 w_s = getsum(l + 1,r);

				if(c[l] >= w_s && dp[l + 1][r] == 1)

				{

					dp[l][r] = 1;

				}

			}

			{

				i64 w_s = getsum(l,r - 1);

				if(c[r - 1] >= w_s && dp[l][r - 1] == 1)

				{

					dp[l][r] = 1;

				}

			}

			/*

			rep(i,0,n)

			{

				if(l <= i && i < r)

					cout << "=";

				else

					cout << " ";

			}

			cout << dp[l][r] << endl;

			*/

		}



	}



	cout << dp[0][n] << endl;



}


