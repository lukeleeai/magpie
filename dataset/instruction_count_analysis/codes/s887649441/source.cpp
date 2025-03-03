

#include <cstdio>

#include <algorithm>

using namespace std;



int dp(int, int);



int N,W;

int w[1001];

int v[101];



int main(){

    scanf("%d %d",&N,&W);



    for(int i = 0; i < N; i++){

        scanf("%d %d",&v[i],&w[i]);

    }



    int dp[101][10001];

    for(int i = 0; i < W; i++){

        dp[0][i] = 0;

    }



    for(int i = 1;i <= N;i++){

        for(int j = 0;j <= W;j++){

            if(j - w[i - 1] < 0){

                dp[i][j] = dp[i - 1][j];

            }else{

                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i - 1]] + v[i - 1]);

            }

        }

    }



    printf("%d\n",dp[N][W]);



    return 0;

}
