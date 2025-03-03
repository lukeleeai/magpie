//Bokan ga bokka--nn!!

//Daily Lunch Special Tanoshii !!

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cassert>

#include <string>

#include <algorithm>

#include <vector>

#include <queue>

#include <stack>

#include <functional>

#include <iostream>

#include <map>

#include <set>

using namespace std;

typedef pair<int,int> P;

typedef pair<int,P> P1;

typedef pair<P,P> P2;

typedef long long ll;

#define pu push

#define pb push_back

#define mp make_pair

#define eps 1e-7

#define INF 2000000000

#define f first

#define s second

#define rep(i,x) for(int i=0;i<x;i++)

int cut[10005];

int dp[2][5005][2];

int main()

{

	srand((unsigned int)time(NULL));

	int n; scanf("%d",&n);

	for(int i=1;i<n;i++) scanf("%d",&cut[i]);

	for(int i=0;i<2;i++)for(int j=0;j<5005;j++)for(int k=0;k<2;k++)dp[i][j][k]=1e8;

	dp[0][1][0]=0; int cur=0,nxt=1;

	for(int i=1;i<n;i++)

	{

		for(int j=0;j<5005;j++)for(int k=0;k<2;k++) dp[nxt][j][k]=1e8;

		for(int j=0;j<=n/2;j++)

		{

			dp[nxt][j+1][0]=min(dp[nxt][j+1][0],dp[cur][j][0]);

			dp[nxt][j][1]=min(dp[nxt][j][1],dp[cur][j][0]+cut[i]);

			dp[nxt][j][1]=min(dp[nxt][j][1],dp[cur][j][1]);

			dp[nxt][j+1][0]=min(dp[nxt][j+1][0],dp[cur][j][1]+cut[i]);

		}

		swap(cur,nxt);

	}

	printf("%d\n",min(dp[cur][n/2][0],dp[cur][n/2][1]));

}