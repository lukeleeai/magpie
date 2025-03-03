/**

     **author : _KMS_

     **created : 01-04-2020

**/

#include"stdc++.h"

using namespace std;

const long long M =3e5+10,MOD=1e9+7;

typedef long long ll;

vector<int>v[M];

bool vis[M];

int dp[M][7];

int arr[10];

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int t,n;

    cin>>n;

    for(int i=1;i<=n;++i)

    {

      for(int j=1;j<=3;j++)

      {

        cin>>arr[j];

       for(int k=1;k<=3;k++)if(j!=k)dp[i][j]=max(dp[i][j],dp[i-1][k]+arr[j]);

      }

    }



  cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";

    return 0;

}