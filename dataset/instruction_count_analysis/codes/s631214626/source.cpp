#include <cstdio>

#include <algorithm>

using namespace std;

#define inf (1<<27)

#define rep(i,n)for(int i=0;i<n;i++)

int cost[100][100];

int n,m,s,g1,g2,b1,b2,c;

int main() {

	while(scanf("%d %d %d %d %d",&n,&m,&s,&g1,&g2),n) {

		fill(cost[0],cost[0]+100*100,inf);

		rep(i,n)cost[i][i]=0;

		rep(i,m) {

			scanf("%d %d %d",&b1,&b2,&c);

			cost[b1-1][b2-1]=c;

		}

		rep(k,n)rep(i,n)rep(j,n) {

			cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

		}

		int res=inf;

		rep(k,n) {

			res=min(res,cost[s-1][k]+cost[k][g1-1]+cost[k][g2-1]);

		}

		printf("%d\n",res);

	}

}