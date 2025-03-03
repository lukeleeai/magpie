#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#include <vector>

#include <map>

#include <queue>

using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;



LL n,m;

LL dp[505][505];

char ch[505][505];



int main(){

	ios::sync_with_stdio(false);

	memset(dp,INF,sizeof(dp));

	cin >> n >> m;

	for(LL i = 1;i <= n;i ++){

		for(LL j = 1;j <= m;j ++){

			cin >> ch[i][j];

		}

	}

	if(ch[1][1] == '.') dp[1][1] = 0;

	else dp[1][1] = 1;

	

	

	for(LL i = 1;i <= n;i ++){

		for(LL j = 1;j <= m;j ++){

			if(i > 1){

				if(ch[i][j] == ch[i - 1][j]) dp[i][j] = min(dp[i][j],dp[i - 1][j]);

				if(ch[i][j] != ch[i - 1][j]) dp[i][j] = min(dp[i][j],dp[i - 1][j] + 1);

			}

			if(j > 1){

				if(ch[i][j] == ch[i][j - 1]) dp[i][j] = min(dp[i][j],dp[i][j - 1]);

				if(ch[i][j] != ch[i][j - 1]) dp[i][j] = min(dp[i][j],dp[i][j - 1] + 1);

			}

		}

	}

	if(ch[n][m] == '#') dp[n][m] ++;

	dp[n][m] >>= 1;

	cout << dp[n][m] << endl;

	return 0;

}

//