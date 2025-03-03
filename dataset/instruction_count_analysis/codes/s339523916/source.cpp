#include<stdio.h>

const int maxn = 1e5+5;



int a[maxn];

int can[maxn];



int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);can[i]=1;}



    for(int i=1;i<=m;i++)

    {

        int u,v;

        scanf("%d%d",&u,&v);

        if(a[u]>=a[v]) can[v] = 0;

        if(a[v]>=a[u]) can[u] = 0;

    }

    int ans = 0;

    for(int i=1;i<=n;i++) if(can[i]) ans++;

    printf("%d\n",ans);

    return 0;

}
