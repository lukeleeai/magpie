#include <cstdio>

#include <algorithm>

using namespace std;



int memo[101][10001],v[1001],w[1001];

int dp(int i,int j){

    if(i == 0)return 0;

    if(memo[i][j] >= 0)return memo[i][j];

    if(j - w[i - 1] < 0)return memo[i][j] = dp(i - 1,j);



    return memo[i][j] = max(dp(i - 1,j),dp(i - 1,j - w[i - 1]) + v[i - 1]);

}



int main(){

    int N,W;

    scanf("%d %d",&N,&W);

    for(int i = 0; i < N; i++){

        scanf("%d %d",&v[i],&w[i]);

    }

    for(int i = 0; i < 101; i++){

        for(int j = 0; j < 10001; j++){

            memo[i][j] = -1;

        }

    }

    printf("%d\n",dp(N,W));

    return 0;

}
