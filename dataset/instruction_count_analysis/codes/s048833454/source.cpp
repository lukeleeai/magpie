#include "stdc++.h"

using namespace std;

#define Maxn 307

int n,m;

int a[Maxn][Maxn],que[Maxn];

bool vis[Maxn];

vector<int> e[2*Maxn];

int l[Maxn];

void print()

{

    for (int i=1;i<=n;i++)

    {

        for (int j=1;j<=m;j++)

            printf("%d ",a[i][j]);

        printf("\n");

    }

}

void insert(int x,int y)

{

    e[x].push_back(n+y);

    e[n+y].push_back(x);

}

int find(int u)

{

    for (int i=0;i<(int)e[u].size();i++)

    {

        int v=e[u][i];

        if (!vis[v])

        {

            vis[v]=true;

            if (l[v]==0||find(l[v]))

            {

                l[v]=u;

                return true;

            }

        }

    }

    return false;

}

int hungary()

{

    int ans=0;

    memset(l,0,sizeof(l));

    for (int i=n+1;i<=2*n;i++)

    {

        memset(vis,false,sizeof(vis));

        if (find(i)) ++ans;

    }

    return ans;

}

int main()

{

    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++)

        for (int j=1;j<=m;j++)

            scanf("%d",&a[i][j]);

    for (int i=1;i<=m;i++)

    {

        memset(e,0,sizeof(e));

        for (int j=1;j<=n;j++)

        {

            memset(vis,false,sizeof(vis));

            for (int k=i;k<=m;k++)

            {

                int tmp=(a[j][k]+m-1)/m;

                if (!vis[tmp])

                {

                    vis[tmp]=true;

                    insert(j,tmp);

                }

            }

        }

        hungary();

        for (int j=1;j<=n;j++)

        {

            int pos=i;

            for (int k=i;k<=m;k++)

            {

                int tmp=(a[j][k]+m-1)/m;

                if (tmp==l[j]-n)

                {

                    pos=k;

                    break;

                }

            }

            if (pos!=i) swap(a[j][pos],a[j][i]);

        }

    }

    print();

    for (int i=1;i<=m;i++)

    {

        for (int j=1;j<=n;j++)

            que[j]=a[j][i];

        sort(que+1,que+n+1);

        for (int j=1;j<=n;j++)

            a[j][i]=que[j];

    }

    print();

    return 0;

}