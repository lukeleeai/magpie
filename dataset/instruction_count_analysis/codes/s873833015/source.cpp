#pragma GCC target("avx2")

#pragma GCC optimize("O3")

   

#include <x86intrin.h>

#include "stdc++.h"   

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

 

using namespace __gnu_pbds;

using namespace std;



template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

     

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

#define al 0x3F3F3F3F

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

const int N = (int)1e4 + 123;

const ll inf = (ll)1e18 + 1;



const double pi = acos (-1.0);

const double eps = 1e-7;                  

const int dx[] = {0, 0, 1, 0, -1};

const int dy[] = {0, 1, 0, -1, 0};



string k;

int a[N], n, d, dp[2][N][100];



inline int add (int a, int b) {

   a += b;

   if (a >= mod) a -= mod;

   if (a < 0) a += mod;

   return a;

}



int calc (bool sp = 1, int pos = 0, int D = 0) {

   if (pos == n) return (D == 0);

   int &res = dp[sp][pos][D];

   if (res != -1) return res;

   res = 0;

   int r = (sp ? a[pos] : 9);

   for (int i = 0; i <= r; i ++) 

      res = add (res, calc ((sp & (i == a[pos])), pos + 1, (D + i) % d));

   return res;

}



inline void boost () {                    

   ios_base :: sync_with_stdio (NULL);

   cin.tie (NULL), cout.tie (NULL);          

}                                                     



inline void Solve () {

   cin >> k >> d;

   n = sz (k);

   for (int i = 0; i < sz (k); i ++) a[i] = k[i] - '0';

   memset (dp, -1, sizeof dp);

   cout << add (calc (), -1);

}



main () {                                       

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

                          