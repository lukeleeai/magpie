#include"stdc++.h"

using namespace std;

const int mod=1e9+7;

int add(int x,int y){return x+y<mod?x+y:x+y-mod;}

int qpow(int x,int k)

{

    int r=1;

    while(k)

    {

        if(k&1)r=1ll*r*x%mod;

        k>>=1;x=1ll*x*x%mod;

    }

    return r;

}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int C[1010][1010];

int n,m,K;

struct data{

    int to,nxt;

}mp[220];

int head[55],cnt;

void link(int x,int y)

{

    mp[++cnt].to=y;

    mp[cnt].nxt=head[x];

    head[x]=cnt;

}



struct Edge{

    int x,y;

};

int dfn[55],clk;

int low[55];

Edge sta[1010];

int top;

int col[55],tcol;

int cp[110],ce[110];

void Tarjan(int x,int fa)

{

    low[x]=dfn[x]=++clk;

    int v,p,q;

    Edge cur;

    for(int i=head[x];i;i=mp[i].nxt)

    {

        if(mp[i].to==fa)continue;

        v=mp[i].to;

        if(!dfn[v])

        {

            sta[++top]=(Edge){x,v};

            Tarjan(v,x);

            low[x]=min(low[x],low[v]);

            if(low[v]>=dfn[x])

            {

                tcol++;

                while(233)

                {

                    cur=sta[top];top--;

                    ce[tcol]++;

                    p=cur.x;q=cur.y;

                    if(col[p]!=tcol)col[p]=tcol,cp[tcol]++;

                    if(col[q]!=tcol)col[q]=tcol,cp[tcol]++;

                    if(p==x&&q==v)break;

                }

            }

        }

        else if(dfn[v]<dfn[x])

            low[x]=min(low[x],dfn[v]),sta[++top]=(Edge){x,v};

    }

}

int main()

{

    for(int i=0;i<=1000;++i)

    {

        C[i][0]=1;

        for(int j=1;j<=i;++j)

            C[i][j]=add(C[i-1][j],C[i-1][j-1]);

    }

    scanf("%d%d%d",&n,&m,&K);

    int xx,yy;

    for(int i=1;i<=m;++i)

    {

        scanf("%d%d",&xx,&yy);

        link(xx,yy);

        link(yy,xx);

    }

    for(int i=1;i<=n;++i)

        if(!dfn[i])top=0,Tarjan(i,0);



    int ans=1,ta;

    int siz;

    for(int i=1;i<=tcol;++i)

    {

//        cout<<"i: "<<i<<" ce: "<<ce[i]<<" cp: "<<cp[i]<<endl;

        if(ce[i]==1)ans=1ll*ans*K%mod;

        else if(ce[i]==cp[i])

        {

            siz=ce[i];

            ta=0;

            for(int j=1;j<=siz;++j)

                ta=add(ta,qpow(K,gcd(siz,j)));

            ta=1ll*ta*qpow(siz,mod-2)%mod;

//            cout<<"ta: "<<ta<<endl;

            ans=1ll*ans*ta%mod;

        }

        else ans=1ll*ans*C[ce[i]+K-1][K-1]%mod;

    }

    printf("%d\n",ans);

    return 0;

}
