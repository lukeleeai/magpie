#include"stdc++.h"

#define LL long long

using namespace std;

int main()

{

    int n,a[100005];

    bool vis[100005];

    while(scanf("%d",&n)!=EOF)

    {

        LL ans=0;

        memset(vis,false,sizeof(vis));

        for(int i=0; i<n; i++)

        {

            scanf("%d",&a[i]);

            if(a[i])vis[i]=true;

            ans+=a[i]/2;

            a[i]%=2;

        }

        for(int i=1; i<n; i++)

        {

            if(a[i]&&a[i-1])

            {

                a[i]=0;

                a[i-1]=0;

                ans++;

            }

            else if(a[i]==0&&a[i-1])

                if(vis[i]) a[i]++,a[i-1]--;

        }

        printf("%lld\n",ans);

    }

}
