#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long LL;

typedef long double ld;

typedef vector<ll>VI;

typedef pair<int,int>P;

#define VV(T) vector<vector<T>>

#define sz(x) int(x.size())

#define PI 3.1415926535897932384626433832795

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

#define reprev(i,n) for (ll i=(ll)n-1;i>=0;i--)

#define ALL(a)  (a).begin(),(a).end()

#define rALL(a) (a).rbegin(),(a).rend()

#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))

#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define vmax(v) *max_element(ALL(v))

#define vmin(v) *min_element(ALL(v))

#define $(x) {cout<<#x<<" = " <<(x)<<endl;}

#define fi first

#define se second

#define MAX 100100//5

#define MAX2 200100

#define MAX6 1001001//6

#define MAX7 10010010//7

#define SENTINEL 2000000000//9

#define INF 1<<30

#define INFTY 1LL<<60

#define MAX_INT INT_MAX

#define Endl '\n'

#define CLR(mat) memset(mat, 0, sizeof(mat))

inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}//最大公約数

inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}//最小公倍数

template<class T> bool contain(const std::string& s, const T& v) {

   return s.find(v) != std::string::npos;

}

const int MOD = 1000000007;



inline ll mod_add(ll a,ll b){return (a+b)%MOD;}

inline ll mod_sub(ll a,ll b){return (a+MOD-b)%MOD;}

inline ll mod_mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}

inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){ll res=1;while(n>0){

if(n&1)res=res*x%mod;

x=x*x%mod;n>>=1;}return res;}

inline ll mod_inv(ll x){return mod_pow(x,MOD-2);}

inline ll mod_div(ll a, ll b){return mod_mul(a,mod_inv(b));}

const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());

// g++ -o a a.cpp -Wall -lm -std=c++17

//push_back -> emplace_back

int h,w,d;

int A[310][310];

int q;

int cost[MAX6];

int main(){

    cin>>h>>w>>d;

    int n=h*w;

    map<int,P>m;

    rep(i,h)rep(j,w){

        cin>>A[i][j];

        m[A[i][j]-1]=P(i,j);

    }

    CLR(cost);

    rep(i,n){

        cost[i+d]=cost[i]+abs(m[i].fi-m[i+d].fi)+abs(m[i].se-m[i+d].se);

    }



    cin>>q;

    rep(i,q){

        int l,r;cin>>l>>r;

        cout<<cost[r-1]-cost[l-1]<<endl;

    }

}