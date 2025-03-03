#include"stdc++.h"

using namespace std;



#define rep(i,n) for(int i=0;i<(n);++i)

#define reps(i,n) for(int i=1;i<=(n);++i)

#define repr(i,n) for(int i=(n);i>=0;--i)

#define step(i,s,n,c) for(int i=(s);i<(n);i+=(c))

#define REP(i,s,n) for(int i=(s);i<(n);++i)

#define each(i,vec) for(auto i:vec)

#define cinv(n,vec) VL vec(n);for(auto&v:vec)cin>>v;

#define int long long

#define itn int

#define pb push_back

#define eb emplace_back

#define m_p make_pair

#define m_t make_tuple

#define p_p(a,b) pb(m_p(a,b))

#define all(a) a.begin(),a.end()

#define SORT(a) sort(all(a))

#define RSORT(a) sort(all(a),greater<>())

#define UNIQUE(a) a.erase(unique(all(a)),a.end())

#define SZ(a) (signed)(a.size())

#define debg(a) cout<<#a<<" "<<a<<endl;

#define debgp(a) cout<<#a<<" "<<a.fi<<" : "<<a.se<<endl

#define call(a) for(auto i:a)cout<<i<<" ";cout<<endl

#define callp(a) for(auto [k,v]:a)cout<<k<<":"<<v<<endl

#define show(a) for(cont &y:a){for(cont &x:y){cout<<x<<" ";}cout<<endl;}

#define out(a) cout<<(a)<<endl

#define ENDL cout<<endl

#define YES cout<<"YES"<<endl

#define NO cout<<"NO"<<endl

#define Yes cout<<"Yes"<<endl

#define No cout<<"No"<<endl

#define fi first

#define se second

#define V vector

#define P pair

#define T tuple

#define PQ priority_queue

#define cont const auto

#define VV(type,name,y,x,a) vector<vector<type>> name = vector<vector<type>>(y,vector<type>(x,a))

typedef long long ll;

typedef double D;

typedef long double LD;

typedef string str;

typedef vector<ll> VL;

typedef pair<ll,ll> PL;

typedef vector<pair<ll,ll>> VP;

typedef tuple<ll,ll,ll> T3;

typedef tuple<ll,ll,ll,ll> T4;

const signed INF = (1LL<<30);

const long long MOD = (1e9+7);

const long long LINF = (1LL<<60);

const long long LMAX = LLONG_MAX;

void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}

template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}

template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}



signed main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout<<fixed<<setprecision(10);

  

  str s;

  cin>>s;

  bool a=true;

  if(s[0]==s[1])a=false;

  if(s[1]==s[2])a=false;

  if(s[2]==s[3])a=false;

  out(a?"Good":"Bad");

  

  

  return 0;

}