/*Lucky_Glass*/

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

using namespace std;

const int MAXN=1000;

const double INF=1e18;

int beg[2],ove[2],rnd[MAXN+5][3];

double dis[MAXN+5][MAXN+5];

int n;

double F[MAXN+5];

bool vis[MAXN+5];

double Dij()

{

	fill(F,F+MAXN+5,INF);

	F[0]=0;

	for(int i=0;i<=n;i++)

	{

		double MIN=INF;

		int u;

		for(int j=0;j<=n+1;j++)

			if(F[j]<MIN && !vis[j])

				MIN=F[j],u=j;

		vis[u]=true;

		for(int j=0;j<=n+1;j++)

			F[j]=min(F[j],F[u]+dis[u][j]);

	}

	return F[n+1];

}

int main()

{

	scanf("%d%d%d%d",&beg[0],&beg[1],&ove[0],&ove[1]);

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		for(int j=0;j<3;j++)

			scanf("%d",&rnd[i][j]);

	rnd[0][0]=beg[0];rnd[0][1]=beg[1];

	rnd[n+1][0]=ove[0];rnd[n+1][1]=ove[1];

	for(int i=0;i<=n+1;i++)

		for(int j=i+1;j<=n+1;j++)

			dis[i][j]=dis[j][i]=max(sqrt(1.0*(rnd[i][0]-rnd[j][0])*(rnd[i][0]-rnd[j][0])+1.0*(rnd[i][1]-rnd[j][1])*(rnd[i][1]-rnd[j][1]))-rnd[i][2]-rnd[j][2],0.0);

	printf("%.9lf\n",Dij());

	return 0;

}
