#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;

int dp[2][55][3005];

int n,m,s;

int main(void){

    while(1){

    cin>>n>>m>>s;

    if(!n&&!m&&!s)break;

    n*=n;

    for(int i=0;i<=n;i++){

        for(int j=0;j<=s;j++){

            dp[0][i][j]=0;

            dp[1][i][j]=0;

        }

    }

    dp[0][0][0]=1;

    for(int i=1;i<=m;i++){

        for(int j=0;j<=n;j++){

            for(int k=0;k<=s;k++){

                dp[i%2][j][k]=dp[(i+1)%2][j][k];

                if(k-i>=0&&j>0)dp[i%2][j][k]=(dp[(i+1)%2][j-1][k-i]+dp[i%2][j][k])%100000;

                

            }

        }

    }

    cout<<dp[m%2][n][s]<<endl;

    }

}