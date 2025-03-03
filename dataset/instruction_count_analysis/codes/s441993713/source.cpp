//nani?

//omo ta tori da

#include"stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#include <ext/pb_ds/detail/standard_policies.hpp>

#define pi acos(-1);

#define fs first

#define sc second

#define pb push_back

#define mp make_pair

#define f(i,a,b) for( int i = a; i < b ; i++ )

#define sor(a) sort( a.begin(), a.end() )

#define rsor(a) sort( a.rbegin(), a.rend() )

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

#define inf 1LL<<62

typedef long long ll;

typedef double ld;

using namespace std;

using namespace __gnu_pbds;

//const ll inf=1e10;

const ll MOD=1e9+7;

const ll mod=998244353;

const ll N = 1e7 + 5;

// ac cmtr;

const int MAX_N = 2e5+5;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

 

#define TRACE

#ifdef TRACE

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void __f(const char* name, Arg1&& arg1) {

  cout << name << " : " << arg1 << endl;}

 

template <typename Arg1, typename... Args>

void __f(const char* names, Arg1&& arg1, Args&&... args) {

  const char* comma = strchr(names + 1, ',');

  cout.write(names, comma - names) << " : " << arg1<<" | ";

  __f(comma+1, args...);}

#else

#define trace(...)

#endif

//---------------------------



ll dp[2005][2005];

ll cnt[MAX_N];

ll n;

vector <pair <ll,ll > > adj[MAX_N];



void dij(ll a){



    set <pair <ll,ll> > s;

    f(i,0,n+1) {dp[i][a]=inf;}

    s.insert(mp(0,a));

    dp[a][a] = 0;

    //ans[a] = 1;

    while(!s.empty()){

        ll ini  = s.begin()->sc;s.erase(s.begin());

        for(auto xd : adj[ini]){

            if(dp[xd.fs][a] > dp[ini][a] + xd.sc){

                s.erase(mp(dp[xd.fs][a],xd.fs)); 

                //ans[xd.fs] = ans[ini];

                dp[xd.fs][a] = dp[ini][a] + xd.sc;

                s.insert(mp(dp[xd.fs][a],xd.fs));

            }

        }

        

    }

  return;

}



int main(){

    fastio;

    ll x,y;

    cin>>n>>x>>y;

    f(i,1,n){

        adj[i].pb({i+1,1});

        adj[i+1].pb({i,1});

    }

    adj[x].pb({y,1});

    adj[y].pb({x,1});

    f(i,1,n+1){

        dij(i);

    }

    f(i,1,n+1){

        for(int j=1;j<=n;j++){

            cnt[dp[i][j]]++;

        }

    }

    f(i,1,n){

        cout<<cnt[i]/2<<" "<<endl;

    }

//ga



   

}