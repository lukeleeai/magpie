#include <iostream>

using namespace std;

int dp[55][3005];

int n,m,s,i,j,k;

int main(void){

    while(1){

    cin>>n>>m>>s;

    if(!n)break;

    n*=n;

    for(i=0;i<=n;i++)for(j=0;j<=s;j++)dp[i][j]=0;

    dp[0][0]=1;

    for(i=1;i<=m;i++)for(j=n;j>0;j--)for(k=i;k<=s;k++)dp[j][k]=(dp[j-1][k-i]+dp[j][k])%100000;

    cout<<dp[n][s]<<endl;

    }

}