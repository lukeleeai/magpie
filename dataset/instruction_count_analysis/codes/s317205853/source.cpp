#include "stdc++.h"

using namespace std;

typedef long long ll;

const int maxn=1e6+10;

const int MAXM=1e6+10;

int F[maxn];

struct node

{

    int x,y,id;

}sp[maxn];

bool cmp2(node a,node b)

{

    return a.x<b.x;

}

bool cmp3(node a,node b)

{

    return a.y<b.y;

}

struct Edge

{

    int u,v,w;

}e[MAXM];

int tol;

void addedge(int u,int v,int w)

{

    e[tol].u=u;

    e[tol].v=v;

    e[tol++].w=w;

}

bool cmp(Edge a,Edge b)

{

    return a.w<b.w;

}

int Find(int x)

{

    if(F[x]==-1)return x;

    else return F[x]=Find(F[x]);

}

int Krustal(int n)

{

    memset(F,-1,sizeof(F));

    sort(e,e+tol,cmp);

    int cnt=0;

    int ans=0;

    for(int i=0;i<tol;++i)

    {

        int u=e[i].u;

        int v=e[i].v;

        int w=e[i].w;

        int t1=Find(u);

        int t2=Find(v);

       // cout<<t1<<' '<<t2<<endl;

        if(t1!=t2)

        {

            ans+=w;

            F[t1]=t2;

            cnt++;

        }

        if(cnt==n-1) break;

    }

   // cout<<cnt<<endl;

    if(cnt<n-1)return -1;

    else return ans;

}

int main()

{

    int n;

    cin>>n;

    tol=0;

    for(int i=1;i<=n;++i)

    {

        cin>>sp[i].x>>sp[i].y;

        sp[i].id=i;

    }

    sort(sp+1,sp+1+n,cmp2);

    for(int i=1;i<n;++i)

    {

        addedge(sp[i].id,sp[i+1].id,sp[i+1].x-sp[i].x);

    }

    sort(sp+1,sp+1+n,cmp3);

    for(int i=1;i<n;++i)

    {

        addedge(sp[i].id,sp[i+1].id,sp[i+1].y-sp[i].y);

    }

    int ans=Krustal(n);

    cout<<ans<<endl;

    return 0;

}
