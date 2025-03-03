#include<cstdio>

#include<algorithm>

#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=100000+10;

int h[maxn],go[maxn*2],nxt[maxn*2],fa[maxn],d[maxn],a[maxn];

int i,j,k,l,t,n,m,tot,root;

bool czy;

void add(int x,int y){

    d[y]++;

    go[++tot]=y;

    nxt[tot]=h[x];

    h[x]=tot;

}

void dfs(int x,int y){

    if (d[x]==1){

        fa[x]=a[x];

        return;

    }

    int t=h[x];

    fa[x]=2*a[x];

    while (t){

        if (go[t]!=y){

            dfs(go[t],x);

            fa[x]-=fa[go[t]];

        }

        t=nxt[t];

    }

}

void dg(int x,int y){

    if (d[x]==1) return;

    int t,l=0;

    if (fa[x]>a[x]) czy=0;

    else{

        t=h[x];

        while (t){

            if (go[t]!=y){

                if (fa[go[t]]>a[x]-fa[x]) l+=(fa[go[t]]+fa[x]-a[x]);

            }

            t=nxt[t];

        }

        if (l>fa[x]) czy=0;

    }

    t=h[x];

    while (t){

        if (go[t]!=y) dg(go[t],x);

        t=nxt[t];

    }

}

int main(){

    scanf("%d",&n);

    fo(i,1,n) scanf("%d",&a[i]);

    fo(i,1,n-1){

        scanf("%d%d",&j,&k);

        add(j,k);add(k,j);

    }

    if (n==2){

        if (a[1]==a[2]) printf("YES\n");else printf("NO\n");

        return 0;

    }

    fo(i,1,n)

        if (d[i]>1) break;

    root=i;

    dfs(root,0);

    if (fa[root]){

        printf("NO\n");

        return 0;

    }

    czy=1;

    dg(root,0);

    if (czy) printf("YES\n");else printf("NO\n");

}