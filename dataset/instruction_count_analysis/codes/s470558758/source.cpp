#include<cstdio>

#include<cstring>

#include<string>

#include<vector>

#include<iostream>

#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn=1e4+10;

const ll mod=1e9+7;

ll dp[maxn][120];

int a[maxn],d;

char num[maxn];

ll dfs(int pos,int sum,bool limit)

{

    if(pos==-1)

        return sum%d==0?1:0;

    if(!limit&&dp[pos][sum]!=-1)

        return dp[pos][sum];

    int up=limit?a[pos]:9;

    ll ans=0;

    for(int i=0; i<=up; i++)

    {

        int tmp=0;

        tmp=(i+sum)%d;

        ans=(ans+dfs(pos-1,tmp,limit&&i==a[pos]))%mod;

    }

    if(!limit)

        dp[pos][sum]=ans%mod;

    return ans%mod;

}

ll solve()

{

    int pos=0;

    int len=strlen(num);

    for(int i=len-1; i>=0; i--)

        a[pos++]=num[i]-'0';

    return dfs(pos-1,0,true);

}

int main()

{

    memset(dp,-1,sizeof(dp));

    scanf("%s",num);

    scanf("%d",&d);

    printf("%lld\n",(solve()-1+mod)%mod);

    return 0;

}
