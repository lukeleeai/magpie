#include"stdc++.h"



using namespace std;



const int mod=1e9+7;

long long dp[700][2002];



long long DP(int cur,long long sum)

{

    if(sum == 0)return dp[cur][0]=1;

    if(sum < 3)return dp[cur][sum]=0;

    long long &ans=dp[cur][sum];

    if(ans > -1)return ans;

    ans=0;

    for(int i=3;i<=sum;i++)ans=(ans+DP(cur+1,sum-i))%mod;

    return ans;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    int n;

    memset(dp,-1,sizeof(dp));

    cin >> n;

    cout << DP(1,n);

    return 0;

}
