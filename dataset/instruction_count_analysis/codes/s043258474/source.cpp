#include <iostream>

#include <algorithm>

#include <iomanip>

#include <string>

#include <vector>

#include <math.h>

#include <queue>

#include <deque>

#include <stack>

#include <set>

#include <map>

const int MOD = 1e9+7;

const int MOOD = 998244353;

#define PI 3.14159265359

typedef long long ll;

using namespace std;



int dp[11][2001];



int main(){

	int d, g;

	cin >> d >> g;

	vector<int> p(d+1), c(d+1);



	for (int i = 1; i <= d; i++){

		cin >> p[i] >> c[i];

	}



	for (int i = 0; i <= 10; i++){

		for (int j = 0; j <= 2000; j++){

			dp[i][j] = -1;

		}

	}



	dp[0][0] = 0;



	for (int i = 1; i <= d; i++){

		for (int j = 0; j <= 1000; j++){

			if (dp[i-1][j] != -1){

				for (int k = 0; k < p[i]; k++){

					dp[i][j+k] = max(dp[i][j+k], dp[i-1][j] + 100*i*k);

				}

				dp[i][j+p[i]] = max(dp[i][j+p[i]], dp[i-1][j] + 100*i*p[i] + c[i]);

			}

		}

	}



	int ans = MOD;

	for (int i = 1; i <= 10; i++){

		for (int j = 0; j <= 1000; j++){

			if (dp[i][j] >= g){

				ans = min(ans, j);

			}

		}

	}

	cout << ans << endl;

	return 0;

}