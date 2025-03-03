#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#define MAXN 1000

//const double INF=;

using namespace std;

double sx,sy,tx,ty;

struct Circle

{

	double x,y,r;

}C[MAXN+5];

bool vis[MAXN+5];

double G[MAXN+5][MAXN+5];

void Init()

{

	for(int i=0;i<=MAXN+3;i++)

		for(int j=0;j<=MAXN+3;j++)

			G[i][j]=-1.0;

}

double Getlen(double x1,double y1,double x2,double y2)

{

	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}

bool Intersect(int a,int b)

{

	double len=Getlen(C[a].x,C[a].y,C[b].x,C[b].y);

	double totr=C[a].r+C[b].r;

	if(len<=totr)

		return true;

	return false;

}

int n;

double dist[MAXN+5];

double Dijkstra(int s)

{

	memset(vis,0,sizeof(vis));

	for(int i=0;i<=MAXN+3;i++)

		dist[i]=-1;

	dist[s]=0;

	vis[s]=true;

	int u=s,nu,cnt=1;

	for(int i=1;i<=n+2;i++)

	{

		double mindist=-1;

		for(int v=0;v<=n;v++)

		{

			if(G[u][v]==-1)

				continue;

			if(dist[v]>dist[u]+G[u][v]||dist[v]==-1)

				dist[v]=dist[u]+G[u][v];

			if((mindist==-1||dist[v]<mindist)&&vis[v]==false)

			{

				mindist=dist[v];

				nu=v;

			}

		}

		vis[nu]=true;

		u=nu;

	}

	return dist[n];

}

int main()

{

	Init();

	scanf("%lf %lf %lf %lf",&sx,&sy,&tx,&ty);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%lf %lf %lf",&C[i].x,&C[i].y,&C[i].r);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=n;j++)

		{

			double len=max(Getlen(C[i].x,C[i].y,C[j].x,C[j].y)-C[i].r-C[j].r,0.0);

			if(G[i][j]==-1||len<G[i][j])

				G[i][j]=len;

		}

	for(int i=1;i<=n;i++)

	{

		double len=max(Getlen(sx,sy,C[i].x,C[i].y)-C[i].r,0.0);

		if(G[i][0]==-1||len<G[0][i])

			G[i][0]=G[0][i]=len;

		len=max(Getlen(tx,ty,C[i].x,C[i].y)-C[i].r,0.0);

		if(G[i][n+1]==-1||len<G[i][n+1])

			G[i][n+1]=G[n+1][i]=len;

	}

	n++;

	G[0][n]=G[n][0]=Getlen(sx,sy,tx,ty);

	double ans=Dijkstra(0);

	printf("%.10lf\n",ans);

	return 0;

}