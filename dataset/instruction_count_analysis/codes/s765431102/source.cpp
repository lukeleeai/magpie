#include "stdc++.h"

using namespace std;



const int N = 2e5+10;

int fa1[N],fa2[N];

int findroot1(int u)

{

    return fa1[u]==u?u:fa1[u]=findroot1(fa1[u]);

}

int findroot2(int u)

{

    return fa2[u]==u?u:fa2[u]=findroot2(fa2[u]);

}

set<int>s2[N];

int ans[N];

int main()

{

    int n,k,l;

    int u,v;

    // freopen("in.txt","r",stdin);

    scanf("%d%d%d",&n,&k,&l);

    for(int i=1;i<=n;i++) fa1[i]=fa2[i]=i;

    for(int i=1;i<=k;i++)

    {

        scanf("%d%d",&u,&v);

        int uu=findroot1(u);

        int vv=findroot1(v);

        if(uu==vv) continue;

        else fa1[vv]=uu;

    }

    for(int i=1;i<=l;i++)

    {

        scanf("%d%d",&u,&v);

        int uu=findroot2(u);

        int vv=findroot2(v);

        if(uu==vv) continue;

        else fa2[vv]=uu;

    }

    for(int i=1;i<=n;i++)

    {

        v=findroot2(i);

        s2[v].insert(i);

    }

    for(int i=1;i<=n;i++)

    {

        if(!s2[i].empty())

        {

            map<int,int>mp;

            for(auto it:s2[i])

            {

                int uu=findroot1(it);

                mp[uu]++;

            }

            for(auto it:s2[i])

            {

                int uu=findroot1(it);

                ans[it]=mp[uu];

            }

        }

    }

    for(int i=1;i<=n;i++)

    {

        printf("%d",ans[i]);

        if(i!=n) printf(" ");

        else printf("\n");

    }

    return 0;

}
