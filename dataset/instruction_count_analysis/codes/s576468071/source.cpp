#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

 

int main()

{

    int i,j,N,v[100],ans;

    long long w[100],W,dp[101][10001];

     

    cin >> N >> W;

     

    for(i=0;i<=N-1;i++) cin >> v[i] >> w[i];

     

    for(i=0;i<=100*N;i++) dp[0][i]=1000000001;

    dp[0][0]=0;

    for(i=1;i<=N;i++)

    {

        for(j=0;j<=N*100;j++)

        {

            if(j-v[i-1]>=0) dp[i][j]=min(dp[i-1][j], dp[i-1][j-v[i-1]]+w[i-1]);

            else dp[i][j]=dp[i-1][j];

        }

    }

    for(i=0;i<=N*100;i++)

    {

        if(dp[N][i]<=W) ans=i;

    }

    cout << ans << endl;

    return 0;

}
