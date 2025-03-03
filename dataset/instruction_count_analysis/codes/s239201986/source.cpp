#include "stdc++.h"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 

// #include <ext/pb_ds/tree_policy.hpp> 

// using namespace __gnu_pbds;   

#define ll long long

#define ull unsigned long long

// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 

ll mod=1e9+7;

#define PI 3.1415926535897932385

#define inf 9e18

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

string char_to_str(char c){string tem(1,c);return tem;}

typedef pair<long long, long long> ii;

#define S second

#define F first

ll max(ll a,ll b){if(a>b){return a;}return b;}

ll min(ll a,ll b){if(a<b){return a;}return b;}

#define MAXN 200005

// Comment this out for interactice problem

// #define endl '\n'

// string to integer stoi() Remember: it takes string not character

// string to long long stoll()

// string.substr(position,length);

// integer to string to_string();

 

// To compile--> g++ -std=c++0x -o output one.cpp

// To run--> ./output

ll n;

vector<ll> adj[100005];

ll given[100005];

ll goal[100005];

ll vis_bfs[100005];

ll vis_dfs[100005];

ll par[100005];

ll tu[100005];



void dfs(ll u){

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)

    {

        if(!vis_dfs[*i]){

            par[*i]=u;

            vis_dfs[*i]=true;

            dfs(*i);

        }

    }

}



int main() 

{ 

    fastio;

    // freopen("input.txt/","r",stdin);

    // freopen("ouptut.txt","w",stdout);

    ll n;

    cin>>n;

    long double p[n+1];

    for (int i = 1; i < n+1; ++i)

    {

        cin>>p[i];

    }



    long double dp[n+1][n+1];

    for (int i = 0; i < n+1; ++i)

    {

        for (int j = 0; j < n+1; ++j)

        {

            dp[i][j]=0;

        }

    }

    dp[0][0]=1;



    for (int i = 1; i < n+1; ++i)

    {

        for (int j = 0; j<=i; ++j)

        {

            // This will give us exact j heads

            // with atmost ith coins

            if(j>0){

                // ith coin being the head

                dp[i][j] = dp[i][j] + (dp[i-1][j-1]*p[i]);

            }

            // Now ith being the tail

            dp[i][j] = dp[i][j] + (dp[i-1][j]*(1.0-p[i]));

        }

    }



    long double ans=0;

    for (int i = (n/2)+1; i<=n; ++i)

    {

        ans = ans + dp[n][i];

    }

    cout<<fixed<<setprecision(13)<<ans;



    return 0;

}