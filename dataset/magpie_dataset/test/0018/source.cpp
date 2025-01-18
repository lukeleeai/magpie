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

  ll k2;

  ll arr[1000000];

  ll arr2[1000000];



  ll func(ll n,ll cur){

    if(cur==n)

      return 0;

    if(cur>n)

      return inf;

    if(arr2[cur]!=-1)

      return arr2[cur];



    ll sum=inf;

    for (ll i = 1; i <=k2; ++i)

    {

      sum=min(sum,func(n,cur+i)+abs(arr[cur]-arr[cur+i]));

    }



    return arr2[cur]=sum;

  }





  int main()

  {

    std::ios::sync_with_stdio(false);

    ll n=0,m=0,k=0,x=0,t1=0,t2=0,t3=0,f=0,sum=0,count=0;



    cin>>n>>k2;



    for (ll i = 0; i < n; ++i){

      cin>>arr[i];

    }



    mem(arr2,-1);



    cout<<func(n-1,0);



    return 0;

  }