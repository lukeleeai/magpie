#pragma GCC optimize("Ofast")

#include"stdc++.h"

using namespace::std;

//struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;

__attribute__((constructor))

void init(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	cout<<fixed<<setprecision(15);

}

// random_device rd;

// mt19937 mt(rd());

// #include <boost/numeric/interval.hpp>

// #include <boost/numeric/interval/io.hpp>

// #include <boost/intrusive/rbtree.hpp>

// #include <boost/dynamic_bitset.hpp>

// #include <boost/geometry.hpp>

// #include <boost/geometry/geometries/linestring.hpp>

// #include <boost/geometry/geometries/polygon.hpp>

// #include <boost/geometry/geometries/point_xy.hpp>

// #include <boost/math/tools/minima.hpp>

// using boost::math::tools::brent_find_minima;

// #include <boost/multiprecision/cpp_dec_float.hpp>

// #include <boost/multiprecision/cpp_int.hpp>

// namespace mp = boost::multiprecision;

// typedef mp::number<mp::cpp_dec_float<256>> cdouble;

// typedef mp::cpp_int cint;



#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

//#include <ext/pb_ds/priority_queue.hpp>

#include<ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;

template<typename T=long long>using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<typename T=long long>using pbds_map=tree<T,T,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//template<typename T=long long>using pqueue =__gnu_pbds::priority_queue<T, less<T>,rc_binomial_heap_tag>;

typedef long long lint;

typedef long long ll;

typedef long double ldouble;

typedef vector<lint> vec;

typedef vector<vector<lint>> mat;

typedef vector<vector<vector<lint>>> mat3;

typedef vector<double> dvec;

typedef vector<vector<double>> dmat;

typedef vector<vector<vector<double>>> dmat3;

typedef vector<string> svec;

typedef vector<vector<string>> smat;

typedef vector<vector<vector<string>>> smat3;

typedef vector<pair<lint,lint>> pvec;

typedef vector<vector<pair<lint,lint>>> pmat;

typedef vector<vector<vector<pair<lint,lint>>>> pmat3;

#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)

#define irep(i) for(lint i = 0;; i++)

#define irep1(i) for(lint i = 1;; i++)

#define irep2(i) for(lint i = 2;; i++)

#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)

#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)

#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)

#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)

#define all(x) (x).begin(),(x).end()

#define PI 3.141592653589793

#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))

#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"");if(i>INF/2)cout<<"INF";else cout<<i;f=1;}cout<<"\n";}while(0);

#define output2(v) for(auto j:v)output(j);

#define _output(v) do{bool f=0;rep(i,v.size()){cout<<(f?" ":"");if(v[i]>INF/2)cout<<"INF";else cout<<v[i];f=1;}cout<<"\n";}while(0)

#define _output2(v) rep(j,v.size()){_output(v[j]);}

#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];

#define SUM(v) accumulate(all(v),0LL)

#define INF (1LL<<60)

#define IINF (1<<30)

#define EPS (1e-10)

#define LINF 9223372036854775807

//#define MOD 998244353LL

#define MOD 1000000007LL

#define endl "\n"

template<typename T=lint>T in(){return *istream_iterator<T>(cin);}

inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}

template<typename T=lint>inline T lcm(T a,T b){return a/gcd(a,b)*b;}

template<typename T=lint>inline T add(T a,T b){return a+b;}

template<typename T=lint>inline T minq(T a,T b){return min(a,b);}

inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}

inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}

vector<lint> dx={-1,1,0,0,1,1,-1,-1};

vector<lint> dy={0,0,-1,1,1,-1,1,-1};







int main(){

    lint n;

    string s;

    cin>>n>>s;

    lint ans=1;

    rep(i,n-1){

        ans+=(s[i]!=s[i+1]);

    }

    cout<<ans<<endl;

}