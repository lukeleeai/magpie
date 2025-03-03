#include<iostream>

#include<cstdio>

#include<string.h>

#include<stdlib.h>

#include<algorithm>

#include <map>

#include <math.h>

#include <vector>

#include <queue>

#include <stack>

#include <list>

#include <limits.h>

#include <string>

#include<functional>

#include <set>

#include <utility>

#include <iomanip>

#include <string>

#define INF 1<<30

#define MO 1000000007

#define MI 998244353

#define ll long long

#define woo 140737488355327

using namespace std;

int a[2100010];ll dp[2100001][3];

int main()

{

    int n;scanf("%d",&n);

    for(int i=0;i<n;i++)

      scanf("%d",&a[i]);

    ll ans;

    if(n%2==0)

    {

    dp[0][0]=a[0];dp[0][1]=a[1];

    for(int i=2;i<n;i+=2)

    {

        dp[i/2][0]=dp[i/2-1][0]+a[i];

        dp[i/2][1]=max(dp[i/2-1][0]+a[i+1],dp[i/2-1][1]+a[i+1]);

    }

    ans=max(dp[n/2-1][0],dp[n/2-1][1]);

    }

    else

    {

    dp[0][0]=a[0];dp[0][1]=a[1];dp[0][2]=a[2];

    for(int i=1;i<n/2;i++)

    {

        dp[i][0]=dp[i-1][0]+a[i*2];

        dp[i][1]=max(dp[i-1][0]+a[i*2+1],dp[i-1][1]+a[i*2+1]);

        dp[i][2]=max(max(dp[i-1][0]+a[i*2+2],dp[i-1][1]+a[i*2+2]),dp[i-1][2]+a[i*2+2]);

    }

    ans=max(dp[n/2-1][0],max(dp[n/2-1][1],dp[n/2-1][2]));

    }

    printf("%lld\n",ans);

}


