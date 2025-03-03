#include<cstdio>

#include <algorithm>

using namespace std;



int v[1001],w[1001];

int N,W,i,j;

int dp[101][10001];

int main(){

    scanf("%d %d",&N,&W);

    for(j = 0; j < W; j++)dp[0][j] = 0;

    for(i = 1;i <= N;i++){

        scanf("%d %d",&v[i - 1],&w[i - 1]);

        for(j = 0;j <= W;j++){

            if(j - w[i - 1] < 0) dp[i][j] = dp[i - 1][j];

		    else dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i - 1]] + v[i - 1]);

        }

    }

    printf("%d\n",dp[N][W]);

    return 0;

}
