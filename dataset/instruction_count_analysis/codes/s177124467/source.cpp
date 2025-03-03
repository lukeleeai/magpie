#include<stdio.h>



int n,k;

int cnt[105];



int main()

{

    scanf("%d%d",&n,&k);

    while(k--)

    {

        int t;

        scanf("%d",&t);

        while(t--)

        {

            int a;

            scanf("%d",&a); cnt[a]++;

        }

    }

    int ans= 0;

    for(int i=1;i<=n;i++) if(cnt[i]==0) ans++;

    printf("%d\n",ans);

    return 0;

}