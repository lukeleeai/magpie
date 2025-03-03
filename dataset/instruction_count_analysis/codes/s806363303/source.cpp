#include<iostream>

#include<cstdio>

#include<cstring>

#include<climits>

#include<algorithm>

#include<cmath>

#include<queue>

using namespace std;

#define MAXN 100000

#define MAXM 100000

#define INF 1000000000000000

struct node

{

    int next,to;

    long long w;

}e[MAXM*2+5];

struct Qr

{

    int xr,dec;

    long long lim;

};

long long T;

int cnt,m,n;

int x,y,z,flag;

long long ri=INF,le=-INF;

long long vis[2][MAXN+5];

int b[MAXN+5];

void fpush(int u,int v,long long w)

{

    e[++cnt].next=b[u];

    e[cnt].w=w;

    e[cnt].to=v;

    b[u]=cnt;

}

int Ch(int x){if(x==-1)x=0;return x;}

int main()

{

    fill(vis[0],vis[0]+MAXN+1,INF);

    fill(vis[1],vis[1]+MAXN+1,INF);

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)

    {

        scanf("%d%d%d",&x,&y,&z);

        fpush(x,y,z);fpush(y,x,z);

    }

    queue<Qr> Q;

	Q.push((Qr){1,1,0});

	while(!Q.empty())

	{

	    Qr A=Q.front();

	    Q.pop();

	    int xr=A.xr,dec=A.dec;

	    long long lim=A.lim;

	    for(int i=b[xr];i;i=e[i].next)

        {

            int xnext=e[i].to;

            long long nlim=e[i].w-lim;

            int FD=Ch(dec);

            if(vis[FD][xnext]!=INF)

            {

                if(vis[FD][xnext]!=nlim){printf("0\n");return 0;}

                else continue;

            }

            vis[FD][xnext]=nlim;

            if(!FD)le=max(le,-vis[FD][xnext]);

            else ri=min(ri,vis[FD][xnext]);

            Q.push((Qr){xnext,-dec,nlim});

        }

	}

    long long T=-1;

    for(int i=1;i<=n;i++)

        if(vis[0][i]!=INF&&vis[1][i]!=INF)

        {

            long long NT=(vis[1][i]-vis[0][i])/2;

            if(NT<0){flag=1;break;}

            if(T==-1)T=NT;

            else if(T!=NT){flag=1;break;}

        }

    if(flag){printf("0\n");}

    if(T!=-1)

    {

        if(T>le&&T<ri)printf("1\n");

        else printf("0\n");

    }

    else printf("%lld",max((long long)0,ri-le-1));

}