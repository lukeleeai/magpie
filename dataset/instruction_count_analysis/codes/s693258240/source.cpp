#include "stdc++.h"

using namespace std;

#define mx 15000000

#define MK 200005

#define pii pair<int,int>

#define tii pair<pii,int>

#define fs first

#define sc second

#define mp make_pair



int dp[105][105],ara[105],n;

int dp_func(int pos,int col)

{

    if(pos>n)return 0;

    if(dp[pos][col]!=-1)return dp[pos][col];

    int ret=20000;

    for(int i=1;i<=101;i++)

    {

        if(i==col)continue;

        ret=min(ret,dp_func(pos+1,i)+(i!=ara[pos]));

    }

    return dp[pos][col]=ret;



}

int name[200000];

int main()

{

    int id=0;

    memset(dp,-1,sizeof dp);

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

            scanf("%d",&ara[i]);

            if(name[ara[i]]==0)

            {

                name[ara[i]]=++id;

            }

            ara[i]=name[ara[i]];

           // cout<<ara[i]<<endl;

    }

    int ans=dp_func(1,0);

    cout<<ans<<endl;



}
