#include"stdc++.h"

using namespace std;

long long d[100005];

int n,m;

bool vis[100005],use[100005];

vector<int>v[100005];

vector<int>e[100005];

bool dfs(int fa)

{

    vis[fa]=true;

    use[fa]=true;

    for(int i=0;i<v[fa].size();i++)

    {

        int y=v[fa][i];

        int z=e[fa][i];

        if(d[y]>d[fa]+z)

        {

            if(vis[y])return true;

            d[y]=d[fa]+z;

            if(dfs(y))return true;

        }

    }

    vis[fa]=false;

    return false;

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

    {

        d[i]=0x7fffffffffffffff;

    }

    for(int i=1;i<=m;i++)

    {

        int x,y,z;

        scanf("%d%d%d",&x,&y,&z);

        v[x].push_back(y);

        e[x].push_back(z);

        v[y].push_back(x);

        e[y].push_back(-z);

    }

    bool ok=false;

    for(int i=1;i<=n;i++)

    {

        if(!use[i])

        {

            d[i]=false;

            if(dfs(i))

            {

                ok=true;

            }

        }

    }

    if(ok)printf("No\n");

    else printf("Yes\n");

    return 0;

}