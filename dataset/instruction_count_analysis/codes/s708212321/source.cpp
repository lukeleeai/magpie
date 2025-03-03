#include <cstdio>

#include <algorithm>

using namespace std;

#define INF (1<<27)

int cost[100][100];

int main() {

	int n,m,s,g1,g2;

	while(scanf("%d %d",&n,&m),n) {

		scanf("%d %d %d",&s,&g1,&g2);s--;g1--;g2--;

		for(int i=0;i<n;i++)

			for(int j=0;j<n;j++)

				cost[i][j]=cost[j][i]=(i==j)?0:INF;

		for(int i=0;i<m;i++) {

			int a,b,c;

			scanf("%d %d %d",&a,&b,&c);

			cost[a-1][b-1]=c;

		}

		for(int k=0;k<n;k++)

			for(int i=0;i<n;i++)

				for(int j=0;j<n;j++)

					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

		int ans=1<<30;

		for(int k=0;k<n;k++)

			ans=min(ans,cost[s][k]+cost[k][g1]+cost[k][g2]);

		printf("%d\n",ans);

	}

}