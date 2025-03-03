#include"stdc++.h"

using namespace std;

const int M=1e5+5;

vector<int>mmp[M];

int col[M],du[M],val[M],dp1[M],dp2[M],n,rt,tot,more;

bool allb[M];

char ch[M];

void in()

{

    int a,b;

    scanf("%d",&n);

    for(int i=1;i<n;++i)

    scanf("%d%d",&a,&b),mmp[a].push_back(b),mmp[b].push_back(a);

    scanf("%s",ch+1);

    for(int i=1;i<=n;++i)col[i]=ch[i]=='W'?0:1,rt=col[i]?rt:i;

}

void dfs(int v,int f)

{

    allb[v]=col[v];int to;

    for(int i=mmp[v].size()-1;i>=0;--i)

    {

        to=mmp[v][i];if(to==f)continue;

        dfs(to,v);

        if(!allb[to])++du[v],++du[to];

        allb[v]&=allb[to];

    }

}

void dp(int v,int f)

{

    tot+=du[v];

    if((du[v]+col[v])&1)val[v]=0;

    else val[v]=2,++tot;

    int mx1=0,mx2=0,to;bool flag=0;

    for(int i=mmp[v].size()-1;i>=0;--i)

    {

        to=mmp[v][i];if(to==f||allb[to])continue;

        flag=1;dp(to,v);

        more=max(more,max(dp1[to]+mx2+val[v],dp2[to]+mx1+val[v]));

        mx1=max(dp1[to],mx1);mx2=max(dp2[to],mx2);

    }

    dp1[v]=mx1+val[v];dp2[v]=flag?mx2+val[v]:-INT_MAX;

}

void ac()

{

    dfs(rt,0);dp(rt,0);

    if(rt)printf("%d",tot-more);

    else printf("0");

}

int main()

{

    in();ac();

    return 0;

}