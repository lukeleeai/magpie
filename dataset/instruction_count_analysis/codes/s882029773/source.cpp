#include "stdc++.h"

using namespace std;

#define MOD 1000000007

#define ll long long

#define li long

#define pb push_back

#define mem(arr,x) memset(arr,x,sizeof(arr))



ll n,W;

ll w[101],v[101];

ll dp[101][100010];

ll totalV=0;



ll minWeight(ll end, ll Val)

{

  if(Val<=0)

  return 0;

  if(end==0)

  return INT_MAX;

  if(dp[end][Val]!=1000000010)

  return dp[end][Val];

  // if(v[end-1]>Val)

  // return dp[end][Val]=minWeight(end-1,Val);

  // else

  return dp[end][Val]=min(w[end-1]+minWeight(end-1,Val-v[end-1]), minWeight(end-1,Val));

}



int main() 

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll i,j;

    cin>>n>>W;

    for(i=0;i<n;i++)

    {

      cin>>w[i]>>v[i];

      totalV+=v[i];

    }



    for(i=0;i<=n;i++)

      for(j=0;j<=totalV;j++)

        dp[i][j]=1000000010;



    for(i=totalV;i>=1;i--)

    {

      if(minWeight(n,i)<=W)

      break;

    }

    cout<<i;

    return 0;

}