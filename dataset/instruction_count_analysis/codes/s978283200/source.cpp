#include<cstdio>

#include<algorithm>

#include<cstdlib>

using namespace std;

const int maxn=100005;

int cost[maxn],dp[maxn];

int main(){

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d",&cost[i]);

    }

    dp[2]=abs(cost[2]-cost[1]);

    dp[3]=min(abs(cost[3]-cost[1]),dp[2]+abs(cost[3]-cost[2]));

    for(int i=4;i<=n;i++){

        dp[i]=min(abs(cost[i]-cost[i-2])+dp[i-2],abs(cost[i]-cost[i-1])+dp[i-1]);

    }

    printf("%d",dp[n]);

    return 0;

}