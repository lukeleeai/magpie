#include"stdc++.h"

using namespace std;

const int N=2e5+5;

int n,m,a[N],c[N],b[N],hs[N],tot,head[N],nex[N<<1],to[N<<1],wi[N<<1];

void add(int u,int v,int w){to[++tot]=v;nex[tot]=head[u];head[u]=tot;wi[tot]=w;}

bool vis[N],use[N];

int lowb(int x)

{

    return lower_bound(hs+1,hs+1+n,x)-hs;

}

int uppb(int x)

{

    return upper_bound(hs+1,hs+1+n,x)-hs;

}

bool dfs(int u)

{

    vis[u]=true;

    int x=c[u];

    for(int i=head[u];i;i=nex[i])

    {

        int v=to[i];

        if(!vis[v]&&dfs(v))

        {

            x^=1;use[wi[i]]=true;

        }

    }

    return x;

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

        scanf("%d%d",&a[i],&b[i]),hs[i]=a[i];

    sort(hs+1,hs+1+n);

    for(int i=1;i<=n;i++)

        a[i]=lowb(a[i]),c[a[i]]=b[i];

    for(int i=n+1;i>=1;i--)

        c[i]^=c[i-1];

    for(int i=1;i<=m;i++)

    {

        int l,r;scanf("%d%d",&l,&r);

        l=lowb(l);

        r=uppb(r)-1;

        if(l<=r)

        {

            //     cout<<l<<" "<<r+1<<endl;

            add(l,r+1,i),add(r+1,l,i);

        }

    }

    for(int i=1;i<=n+1;i++)

        if(!vis[i]&&dfs(i))

        {

            printf("-1\n");return 0;

        }

    int ans=0;

    for(int i=1;i<=m;i++)

        if(use[i]) ans++;

    printf("%d\n",ans);

    for(int i=1;i<=m;i++)

        if(use[i])

            printf("%d ",i);

}