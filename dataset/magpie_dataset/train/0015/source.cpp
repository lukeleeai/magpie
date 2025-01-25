#include <iostream>

#include <cstdio>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)



int main(){

	int weight;

	int n,v,w,c=0;

	int dp[1001][1001];

	while(scanf("%d\n",&weight) && weight){

		c++;

		rep(i,1001)rep(j,1001)dp[i][j]=0;

		

		scanf("%d\n",&n);

		for(int k=1;k<=n;k++){

			scanf("%d,%d\n",&v,&w);

			for(int i=0;i<=w;i++){

				dp[k][i] = dp[k-1][i];

			}

			for(int i=w;i<=weight;i++){

				dp[k][i] = max(dp[k-1][i],dp[k-1][i-w]+v);

			}

		}

		/*for(int k=0;k<=n;k++){

			for(int i=0;i<=weight;i++)

				printf("%4d",dp[k][i]);

			puts("");

		}*/

		printf("Case %d:\n",c);

		printf("%d\n",dp[n][weight]);

		for(int i=0;i<=weight;i++){

			if(dp[n][i]==dp[n][weight]){

				printf("%d\n",i);

				break;

			}

		}

	}

}