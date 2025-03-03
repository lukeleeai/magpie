#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#include<iostream>

#include<vector>

#include<queue>

#include<stack>

#include<map>

using namespace std;

typedef long long LL;

#define M(a,b) memset(a,b,sizeof(a))

struct Node

{

    int u,v,val;

    bool operator < (const Node &a) const

    {

        return val<a.val;

    }

}g[50005];

int fa[505],E[505];

int n,m,pos;

const int inf = 1<<30;

int Find(int x)

{

    return x==fa[x]?x:fa[x]=Find(fa[x]);

}

int kruscal(int x)

{

    int sum=0,edge=0;

    for (int i=1;i<=n;++i) fa[i]=i;

    for (int i=1;i<=m;++i)

    {

        if (i!=x)

        {

            int u=Find(g[i].u);

            int v=Find(g[i].v);

            if (u!=v)

            {

                sum+=g[i].val;

                fa[u]=v;

                if (!x) E[++pos]=i;

                ++edge;

            }

        }

    }

    return edge!=n-1?inf:sum;

}

int main()

{

    while(~scanf("%d%d",&n,&m))

    {

        for (int i=1;i<=m;++i)

            scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].val);

        sort(g+1,g+1+m);

        pos=0;

        int tmp=kruscal(0);

        int ans=0,sum=0;

        for (int i=1;i<=pos;++i)

            if (kruscal(E[i])>tmp)

            {

                ++ans;

                sum+=g[E[i]].val;

            }

        printf("%d %d\n",ans,sum);

    }

}