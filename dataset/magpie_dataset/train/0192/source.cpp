//Bokan ga bokka--nn!!

//Daily Lunch Special Tanoshii !!

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

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

#define s(x) scanf("%d",&x)

#define rep(i,x) for(int i=0;i<x;i++)

int a[3005],b[3005];

int dp[3005][2]={};

int main()

{

	int n,t,s;

	scanf("%d %d %d",&n,&t,&s);

	for(int i=1;i<=n;i++)

	{

		scanf("%d %d",&a[i],&b[i]);

	}

	int cur=0;

	int nex=1;

	dp[0][cur]=0;

	for(int i=1;i<=n;i++)

	{

		for(int j=0;j<3005;j++)dp[j][nex]=0;

		for(int j=0;j<=t;j++)

		{

			dp[j][nex]=max(dp[j][nex],dp[j][cur]);

		}

		for(int j=0;j<=t-b[i];j++)

		{

			if(j<s && s<j+b[i]) continue;

			dp[j+b[i]][nex]=max(dp[j+b[i]][nex],dp[j][cur]+a[i]);

		}

		cur=1-cur; nex=1-nex;

	}

	int ret=0;

	for(int i=0;i<=t;i++) ret=max(ret,dp[i][cur]);

	printf("%d\n",ret);

}