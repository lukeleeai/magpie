#include"stdc++.h"

#define int long long int

#define pb push_back

#define inf 1e9

#define pp pop_back

#define pii pair<int,int>

#define vec vector<int>

#define mp make_pair

using namespace std;

int h[100001],dp[100001];

int ans(int n,int k)

{

  if(n==1)

    return 0;

  if(dp[n]!=-1)

    return dp[n];

  int res=inf;

  for(int i=1;i<=min(k,n-1);i++)

    res=min(res,abs(h[n]-h[n-i])+ans(n-i,k));

  return dp[n]=res;

}

int32_t main()

{

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  cout.tie(NULL);

  int t=1;

  //cin>>t;

  while(t--)

  {

    memset(dp,-1,sizeof(dp));

    int n,k;

    cin>>n>>k;

    int i;

    for(i=1;i<=n;i++)

        cin>>h[i];

    cout<<ans(n,k);

  }

}
