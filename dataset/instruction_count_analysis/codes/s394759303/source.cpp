#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 100010

#define MAXM 200010

#define INF 1000000000

int Adj[MAXN],V[MAXM],nxt[MAXM],c;

void AddEdge(int u,int v)

{

    c++;V[c]=v,nxt[c]=Adj[u];

    Adj[u]=c;

}

int L[MAXN],R[MAXN],root,odd[MAXN];

void dfs1(int u,int p)

{

    for(int i=Adj[u];i;i=nxt[i])

    {

        int v=V[i];

        if(v==p) continue;

        dfs1(v,u);

        R[u]=min(R[v]+1,R[u]);

        L[u]=max(L[v]-1,L[u]);

        if(odd[v]!=-1)

        {

            if(odd[u]==-1) odd[u]=!odd[v];

            else if(odd[v]==odd[u])

            {

                printf("No\n");

                exit(0);

            }

        }

    }

}

void dfs2(int u,int p)

{

    if(p)

    {

        R[u]=min(R[u],R[p]+1);

        L[u]=max(L[u],L[p]-1);

        if(odd[u]==-1) odd[u]=!odd[p];

    }

    if(L[u]>R[u]||(L[u]==R[u]&&odd[u]!=(L[u]&1)))

    {

        printf("No\n");

        exit(0);

    }

    for(int i=Adj[u];i;i=nxt[i])

        if(V[i]!=p)

        {

            dfs2(V[i],u);

        }

}

int ans[MAXN];

void GetAns(int u,int p)

{

    if(!p) ans[u]=L[u];

    else

    {

        ans[u]=ans[p]-1;

        if(ans[u]<L[u]) ans[u]+=2;

    }

    for(int i=Adj[u];i;i=nxt[i])

        if(V[i]!=p)

            GetAns(V[i],u);

}

int main()

{

    int n,m,u,v;

    scanf("%d",&n);

    for(int i=1;i<n;i++)

    {

        scanf("%d%d",&u,&v);

        AddEdge(u,v);

        AddEdge(v,u);

    }

    for(int i=1;i<=n;i++)

        L[i]=-INF,R[i]=INF,odd[i]=-1;

    scanf("%d",&m);

    for(int i=0;i<m;i++)

    {

        scanf("%d%d",&u,&v);

        root=u;

        odd[u]=(v&1);

        L[u]=R[u]=v;

    }

    dfs1(root,0);

    dfs2(root,0);

    GetAns(root,0);

    printf("Yes\n");

    for(int i=1;i<=n;i++)

        printf("%d\n",ans[i]);

    return 0;

}