#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXN int(1e5)

int n,tot;

int poi[MAXN+5];

int main()

{

    //freopen("in.txt","r",stdin);

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        scanf("%d",&poi[i]),tot+=abs(poi[i-1]-poi[i]);

    tot+=abs(poi[n]);

    for(int i=1;i<=n;i++)

    {

        int ans=tot;

        if(i==n)

            ans=ans-abs(poi[n])-abs(poi[n-1]-poi[n])+abs(poi[n-1]);

        else

            ans=ans-abs(poi[i-1]-poi[i])-abs(poi[i]-poi[i+1])+abs(poi[i-1]-poi[i+1]);

        printf("%d\n",ans);

    }

    return 0;

}
