#include<cstdio>

#define maxn 502

using namespace std;

int dp[maxn][maxn],h[maxn][maxn];

int main(){

	int n,m,q;

	scanf("%d%d%d",&n,&m,&q);

	for(int i=1;i<=m;i++){

		int x,y;

		scanf("%d%d",&x,&y);

		h[x][y]++;

	}

	for(int len=1;len<=n;len++){

		for(int i=1;i+len-1<=n;i++){

			int j=i+len-1;

			if(i==j){

				dp[i][j]=h[i][j];

			}

			else if(i+1==j){

				dp[i][j]=dp[i][i]+dp[j][j]+h[i][j];

			}

			else{

				dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+h[i][j];

			}

		}

	}

	while(q--){

		int x,y;

		scanf("%d%d",&x,&y);

		printf("%d\n",dp[x][y]);

	}

	return 0;

}