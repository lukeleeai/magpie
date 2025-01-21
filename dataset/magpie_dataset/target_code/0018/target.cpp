  #include "stdc++.h"

  #define endl "\n"

  #define ll long long int

  #define vi vector<int>

  #define vll vector<ll>

  #define vvi vector < vi >

  #define pii pair<int,int>

  #define pll pair<long long, long long>

  #define mod 1000000007

  #define inf 1000000000000000001;

  #define all(c) c.begin(),c.end()

  #define mp(x,y) make_pair(x,y)

  #define mem(a,val) memset(a,val,sizeof(a))

  #define pb push_back

  #define f first

  #define se second

  

  using namespace std;

  int main()

  {

    std::ios::sync_with_stdio(false);

    ll n=0,m=0,k=0,x=0,t1=0,t2=0,t3=0,f=0,sum=0,count=0;



    cin>>n>>k;

    ll arr[n+1],dp[n+1];

    arr[0]=inf; dp[0]=0; 

   

    for (ll i = 1; i <= n; ++i){

      cin>>arr[i];

    }

    dp[1]=0;



    for (ll i = 2; i <= n; ++i)

    {

      dp[i]=INT_MAX;

      for (ll j = 1; j <=k; ++j)

      {

        if(i-j>=1)

         dp[i]=min(abs(arr[i]-arr[i-j])+dp[i-j],dp[i]);

      }

    }



    cout<<dp[n]<<endl;



    return 0;

  }


