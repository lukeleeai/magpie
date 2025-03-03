#include"stdc++.h"

typedef long long ll;

const int maxn=1e6+5;

using namespace std;

const ll INF=1e13+7;

ll n,m;

char str[maxn];

ll dp[maxn];

ll q[maxn];

int pre[maxn];

void TraceBack(int x)

{

    if(pre[x]==-1)

    {

        printf("%d",x);

        return;

    }

    TraceBack(pre[x]);

    printf(" %d",x-pre[x]);

}

int main()

{

    memset(pre,-1,sizeof(pre));

    scanf("%lld%lld",&n,&m);

    scanf("%s",str);

    //数有n+1个

    int s=1,e=0;

    for(int i=0;i<=m;i++)

    {

        if(str[i]=='0')

            dp[i]=1;

        else

            dp[i]=INF;

        while(s<=e&&dp[i]<dp[q[e]]) e--;

        q[++e]=i;

    }

    s++;

    for(int i=m+1; i<=n; i++)

    {

        dp[i]=INF;

        if(str[i]=='0')

        {

            dp[i]=min(dp[q[s]]+1,dp[i]);

            if(!dp[i]!=INF)

                pre[i]=q[s];

        }

        while(s<=e&&dp[i]<dp[q[e]]) e--;

        q[++e]=i;

        while(s<=e&&q[s]<i+1-m)

            s++;

    }

    if(dp[n]==INF) printf("-1\n");

    else TraceBack(n);

    return 0;

}


