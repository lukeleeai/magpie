#include<cstdio>

#include<iostream>

#include<cstring>

#include<vector>

#include<queue>

#include<map>

#include<cmath>

#include<algorithm>

#include<cstdlib>

#include<stack>

#include<set>

using namespace std;

#define pb push_back

#define POP pop_back()

#define ll long long

#define db double

#define POP pop_back()

#define endl '\n'

const int maxn = 5e2 + 5;

const int inf = 0x3f3f3f3f;

const int inF = 0x3f3f3f3f3f3f3f3f;

const int mod = 1e9 + 7;

const db eps = 1e-8;

ll a[maxn] , dp[maxn][maxn][2];

int main(){

	int n;cin >> n;

	memset(dp, inf , sizeof dp);

	for(int i = 1;i <= n;i++)cin >> a[i] , dp[i][i][1] = a[i] , dp[i][i][0] = 0;

	for(int i = 2;i <= n;i++){

		for(int j = 1;j+i-1 <= n;j++){

			int k = j+i-1;

			for(int m = j;m < k;m++){

				dp[j][k][0] = min(dp[j][k][0] , dp[j][m][0]+dp[m+1][k][0]+dp[j][m][1] + dp[m+1][k][1]);

			}

			dp[j][k][1] = dp[j][k-1][1]+a[k];

		}

	}

	/*for(int i = 1;i <= n;i++){

		for(int j = 1;j <= n;j++)cout << dp[j][i][0] << " " ;

		cout << endl;

	}*/

	cout << dp[1][n][0] << endl;

	return 0;

}