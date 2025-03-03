//code by lynmisakura.wish to be accepted!

/****************************/

#include<iostream>

#include<math.h>

#include<vector>

#include<string>

#include<stack>

#include<queue>

#include<map>

#include<algorithm>

#include<bitset>

#include <climits>

#include<set>

#include<bitset>

using namespace std;

/***************************/

typedef long long ll;

typedef pair<int,int> pi;

typedef vector<pair<int,int>> vpi;

 

const long long MOD = 998244353;

const long long mod = 1000000007;

const long long INF = 10000000000000;

 

#define itn int

#define endl "\n"

#define pb push_back

#define mp make_pair

#define ss second

#define ff first

#define mins(x,y) x = min(x,y)

#define maxs(x,y) x = max(x,y)

#define all(x) (x).begin(),(x).end()

#define Rep(n) for(int i = 0;i < n;i++)

#define rep(i,n) for(int i = 0;i < n;i++)

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

 

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }

ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

 

#define _GLIBCXX_DEBUG

#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



int visited[200010];

vector<vector<int>> G(200010,vector<int>(0));

void dfs(int x){

   

   visited[x]++;

   int s = G[x].size();

   if(s != 0)rep(i,s){

      if(visited[G[x][i]] == 0){

         dfs(G[x][i]);

      }

   }

   return;

}

int main(void){

   int n,m;cin >> n >> m;

   rep(i,m){

      int x,y,z;cin >> x >> y >> z;

      G[--x].pb(--y);

      G[y].pb(x);

   }

   int ans = 0;

   for(int i = 0;i < n;i++){

      if(visited[i] == 0){

         ans++;

         dfs(i);

      }

   }

   cout << ans << endl;

   return 0;

}