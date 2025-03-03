#include"stdc++.h"



using namespace std;



inline int read()

{

    int x=0;char ch=getchar();

    while(ch<'0'|| ch>'9')ch=getchar();

    while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();

    return x;

}



typedef long long ll;

typedef pair<ll,ll> pr;

typedef vector<pr> vec;

#define x first

#define y second

const int N=131100;



int n,fa[N];

vec g[N],f[N];

ll mid,mv[N];



inline bool cmpx(pr a,pr b){return a.x<b.x;}

inline bool cmpy(pr a,pr b){return a.y<b.y;}



inline void work(vec &ls,vec &rs,vec &f)

{

    if(ls.size()>rs.size())swap(ls,rs);

    int el=ls.size(),er=rs.size();



    sort(ls.begin(),ls.end(),cmpy);

    sort(rs.begin(),rs.end(),cmpx);



    mv[0]=rs[0].y;

    for(int i=1;i<er;i++)

        mv[i]=min(mv[i-1],rs[i].y);



    for(int i=0,j=er-1;i<el;i++)

    {

        while(j>=0 && ls[i].y+rs[j].x>mid)j--;

        if(j>=0)f.push_back(pr(ls[i].x,mv[j]));

    }



    sort(ls.begin(),ls.end(),cmpx);

    sort(rs.begin(),rs.end(),cmpy);

    mv[0]=rs[0].x;

    for(int i=1;i<er;i++)

        mv[i]=min(mv[i-1],rs[i].x);



    for(int i=0,j=er-1;i<el;i++)

    {

        while(j>=0 && ls[i].x+rs[j].y>mid)j--;

        if(j>=0)f.push_back(pr(mv[j],ls[i].y));

    }

}



inline void dfs(int u)

{

    if(!f[u].empty())f[u].clear();

    if(g[u].empty())

    {

        f[u].push_back(pr(0,0));

        return;

    }



    for(int i=0,e=g[u].size();i<e;i++)

        dfs(g[u][i].x);



    vec &ls=f[g[u][0].x];

    for(int i=0,e=ls.size(),c=g[u][0].y;i<e;i++)

        ls[i].x+=c,ls[i].y+=c;

    vec &rs=f[g[u][1].x];

    for(int i=0,e=rs.size(),c=g[u][1].y;i<e;i++)

        rs[i].x+=c,rs[i].y+=c;



    work(ls,rs,f[u]);

    ls.clear();

    rs.clear();

}



int main()

{

    n=read();

    for(int i=2,a;i<=n;i++)

    {

        fa[i]=read();

        g[fa[i]].push_back(pr(i,read()));

    }



    ll l=0,r=1e10,ans=1e10;

    while(l<=r)

    {

        mid=l+r>>1;

        dfs(1);

        if(f[1].empty())

            l=mid+1;

        else

            r=mid-1,ans=mid;

    }

    printf("%lld\n",ans);

    return 0;

}
