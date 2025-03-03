#include"stdc++.h"

using namespace std;

#define inf 0x3f3f3f3f

typedef long long ll;

const int N=2e5+5;

int n,a[N][3];

ll dp[N][5];

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d",&a[i][0]);

        a[i][1]=a[i][0]%2==0;

        a[i][2]=a[i][0]==0?2:a[i][0]%2;

    }

    for(int i=1;i<=n;i++)

    {

        ll mn=1e18;

        for(int j=0;j<5;j++)

        {

            mn=min(mn,dp[i-1][j]);

            ll s;

            if(j==0) s=a[i][0];

            else if(j==1) s=a[i][2];

            else if(j==2) s=a[i][1];

            else if(j==3) s=a[i][2];

            else s=a[i][0];

            dp[i][j]=mn+s;

        }

    }

    ll ans=1e18;

    for(int i=0;i<5;i++) ans=min(ans,dp[n][i]);

    printf("%lld\n",ans);

}
