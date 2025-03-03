//#pragma GCC target("avx2")

//#pragma GCC optimize("O3")

 

//#include <x86intrin.h>

#include <algorithm>

#include <iostream>

#include <cstring>

#include <string>

#include <bitset> 

#include <vector>

#include <cmath>

#include <deque>

#include <queue>

#include <iomanip>

#include <stack>

#include <map>

#include <set>

//#include <ordered_set>

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

 

//using namespace __gnu_pbds;

using namespace std;

 

//template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

     

#define F first

#define S second           

#define lb lower_bound               

#define ub upper_bound

#define pb push_back

#define pf push_front    

#define ppb pop_back

#define mp make_pair                                     

#define bpp __builtin_popcountll                                                                                        

#define sqr(x) ((x) * (x)) 

#define sz(x) (int)x.size()

#define all(x) x.begin(), x.end()

#define in insert

#define ppf pop_front

#define endl '\n'

//#define int long long

 

typedef unsigned long long ull;

typedef long long ll;

typedef long double ld;

typedef pair <int, int> pii;

 

const int mod = (int)1e9 + 7;

const int N = (int)3e5 + 123;

const ll inf = (ll)1e18 + 1;

 

const double pi = acos (-1.0);

const double eps = 1e-7;                  

const int dx[] = {0, 0, 1, 0, -1};

const int dy[] = {0, 1, 0, -1, 0};



int n, dp[N], sz[N], fact[N], inv[N];

vector <int> g[N];



inline int add (int a, int b) {

   a += b;

   if (a >= mod) a -= mod;

   if (a < 0) a += mod;

   return a;

}



inline int mult (int a, int b) {

   return 1ll * a * b % mod;

}



inline int binpow (int a, int b) {

   int res = 1;

   while (b) {

      if (b & 1) res = mult (res, a);

      a = mult (a, a);

      b >>= 1;

   }

   return res;

}



void dfs (int v = 1, int pr = 0) {

   sz[v] = 1;

   for (auto to : g[v]) {

      if (to != pr)

         dfs (to, v), sz[v] += sz[to];

   }

   dp[v] = fact[sz[v] - 1];

   for (auto to : g[v]) {

      if (to != pr) {

         dp[v] = mult (dp[v], mult (dp[to], inv[sz[to]]));

      }

   }

}



void recalc (int v = 1, int pr = 0) {

   if (v != 1) dp[v] = mult (mult (dp[pr], sz[v]), binpow (n - sz[v], mod - 2));

   for (auto to : g[v])

      if (to != pr)

         recalc (to, v);

}



inline void boost () {

   ios_base :: sync_with_stdio (0);

   cin.tie (0), cout.tie (0);

}

 

inline void Solve () {

   cin >> n;

   for (int i = 1; i < n; i ++) {

      int x, y;

      cin >> x >> y;

      g[x].pb (y);

      g[y].pb (x);

   }

   fact[0] = 1;

   for (int i = 1; i <= n; i ++) fact[i] = mult (fact[i - 1], i), inv[i] = binpow (fact[i], mod - 2);

   dfs ();

   recalc ();

   for (int i = 1; i <= n; i ++) cout << dp[i] << endl;

}            

 

signed main () {                                       

   #ifdef QWERTY

      freopen("input", "r", stdin);

   #endif

// freopen (".in", "r", stdin);    

// freopen (".out", "w", stdout);              

   boost ();

   int tt = 1;

   //cin >> tt;   

   while (tt --) {

      Solve ();

   }                                               

   return 0;      

}