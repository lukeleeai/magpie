/**



+++---------+++--------- Don't lose faith ---------+++---------+++

+++---------+++--------- Author : sea_26 ----------+++---------+++



**/



#pragma GCC optimize("03")

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>

#include "stdc++.h"



using namespace __gnu_pbds;

using namespace std;



template <typename T>

    using ordered_set = tree<T, null_type, less<T>,

        rb_tree_tag, tree_order_statistics_node_update>;





using ll = long long;

using ld = long double;



priority_queue<int> pq;



const int M = 1e9 + 7;

const ll MOD = 998244353;

const ld eps = 1e-9;

const ld PI = acos(-1.0);



// const double pi = atan2(0, -1);

// const double PI = 4 * atan(1);

// const double pi = 2*cos(0.0);



const int iinf = 0x3f3f3f3f;

const ll linf = 0x3f3f3f3f3f3f3f3f;



#define mp make_pair

#define eb emplace_back

#define ep emplace

#define fbo find_by_order

#define ook order_of_key

#define f first

#define s second

#define sz size()



#define bp(n)  __builtin_popcount(n)

#define bclz(n) __builtin_clzll(n)

#define bctz(n) __builtin_ctzll(n)

#define bip(n) __builtin_parity(n)



#define vsort(v) sort(v.begin(),v.end())

#define rvsort(v) sort(v.begin(),v.end(),greater<int>())

#define mnv(v) *min_element(v.begin(),v.end())

#define mxv(v) *max_element(v.begin(),v.end())

#define all(v) (v).begin(),(v).end()

#define ita(v) iota(all(v), 0)

#define acm(v, ini) accumulate(all(v),ini)



#define ub upper_bound

#define lb lower_bound

#define cr(n) (floor)cbrt(n)

#define msz(a) memset(a, 0, sizeof(a))

#define msm(a) memset(a, 0xff, sizeof(a))



#define rep(n) for(int i=0; i<n; i++)

#define rrep(n) for(int i=n-1; i>=0; i--)

#define lrep(p,q) for(int j=p; j<=q; j++)

#define ldrep(p,q) for(int i=p; i>=q; i--)





#define yes cout << "YES" << endl

#define no cout << "NO" << endl



#define fs ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);



template< typename T> inline T MAX(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }

template< typename T> inline T MIN(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }

template< typename T> void SWAP(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }

template< typename T> inline T sqr(T x){ return x * x; }

template< typename T> inline T lcm(T a, T b){ return (a / gcd(a,b)) * b; }



template< typename T> inline T gcd(T a, T b){ while (b) b ^= a ^= b ^= a %= b; return a; }

template< typename T> T exgcd(T a, T b, T& x, T& y){ if(!b){ x = 1; y = 0;return a;} else{T g = exgcd(b,a%b,y,x); y -= (a/b)*x; return g;}}

template< typename T>T gcdextd(T a, T b, T& x, T& y) { if (!a) { x = 0; y = 1; return b; }  T x1,y1,d; d = gcdextd(b % a, a, x1, y1);  x = y1 - (b / a) * x1; y = x1; return d; }



template< typename T> T icbrt(T mul){T r = cbrt(mul) + 1; while(r * r * r > mul) r--; return r; } /// 54229668

template< typename T> void tpns(T n){ rrep(30){ if(n & (1 << i)) pq.push(1 << i); } }



template< typename T> inline T mod(T a, T b){ return a >= b ? a % b : a; }

template< typename T> T binpow(T n, T p){ T res = 1; while(p > 0){ if(p & 1) res *= n; n *= n; p >>= 1; } return res;}

template< typename T> T bigmod(T n, T p, T M){ n %= M; T res = 1; while(p > 0){ if(p & 1)res = ((res%M) * (n % M)) % M; n = ((n%M) * (n%M))%M; p >>= 1; } return res;}

template< typename T> T modInv(T a, T m){return bigmod(a, m-2, m);}





void ReT(){ cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC  << " Sec"<< endl; exit(0);}







int main(){



    fs;



    ll x,y;

    cin >> x >> y;

    ll i;

    for(i=0;x<=y;i++)

        x *= 2;



    cout << i << endl;

    /// ReT();



return 0;

}
