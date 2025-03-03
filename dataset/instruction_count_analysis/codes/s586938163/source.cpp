/**

     **author : _KMS_

     **created : 30-03-2020

**/

#include"stdc++.h"

using namespace std;

const long long M =3e5+10,MOD=1e9+7;

typedef long long ll;

vector<int>v[M];

bool vis[M];

int dp[M];

void dfs(int i)

{

  vis[i]=1;

  for(int j=0;j<v[i].size();j++)

  {

    int y=v[i][j];

    if(!vis[y])dfs(y);

    dp[i]=max(dp[i],dp[y]+1);

  }

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

     int n,m;

     cin>>n>>m;

     for(int i=0;i<m;i++)

     {

       int x,y;

       cin>>x>>y;

       v[x].push_back(y);

     }

     for(int i=1;i<=n;i++)

     {

      if(!vis[i])

      {

        dfs(i);

      }

     }

    sort(dp+1,dp+n+1);

    cout<<dp[n]<<"\n";

    return 0;

}