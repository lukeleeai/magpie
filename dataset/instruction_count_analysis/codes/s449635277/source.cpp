#include "stdc++.h"

using namespace std;

#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)

#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)

#define per(i,N) for(int i=(N)-1;i>=0;--i)

#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)

#define all(arr) (arr).begin(), (arr).end()

#define SP << " " <<

#define SPF << " "

#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);

#define MAX_I INT_MAX //1e9

#define MIN_I INT_MIN //-1e9

#define MAX_UI UINT_MAX //1e9

#define MAX_LL LLONG_MAX //1e18

#define MIN_LL LLONG_MIN //-1e18

#define MAX_ULL ULLONG_MAX //1e19

  typedef long long ll;

  typedef pair<int,int> PII;

  typedef pair<char,char> PCC;

  typedef pair<ll,ll> PLL;

  typedef pair<char,int> PCI;

  typedef pair<int,char> PIC;

  typedef pair<ll,int> PLI;

  typedef pair<int,ll> PIL; 

  typedef pair<ll,char> PLC; 

  typedef pair<char,ll> PCL; 



inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}

inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}

inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}



template< typename Monoid >

struct SegmentTree{

  using F = function< Monoid(Monoid, Monoid) >;

  

  int sz;

  vector< Monoid > seg;



  const F f;

  const Monoid M1;



  //SegmentTree(n,f,M1):サイズnの初期化，fは2つの苦汗の要素をマージする二項演算，M1はモノイドの単位元

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1){

    sz = 1;

    while(sz < n) sz<<=1;

    seg.assign(2*sz,M1);

  }



  //set(k,x):k番目の要素にxを代入

  void set(int k, const Monoid &x){

    seg[k+sz] = x;



  }

  

  //build():segTreeの構築

  void build(){

    for(int k = sz-1; k>0; --k){

      seg[k] = f(seg[2*k+0], seg[2*k+1]);

    }

  }



  //update(k,x):k番目の要素をxに変更

  void update(int k, const Monoid &x){

    k += sz;

    seg[k] = x;

    while(k>>=1) seg[k] = f(seg[2*k+0],seg[2*k+1]);

  }



  //区間[a,b)のMonoidを計算

  Monoid query(int a, int b){

    Monoid L = M1, R = M1;

    for(a += sz, b+=sz; a < b; a>>=1, b>>=1){

      if(a&1) L = f(L,seg[a++]);

      if(b&1) R = f(seg[--b],R);

    }

    return f(L,R);

  }



  //operator[k]:k番目の要素を返す

  Monoid operator[](const int &k) const{

    return seg[k+sz];

  }



};



struct edge{ int f,t; ll c;};

bool comp(const edge& l, const edge& r){

  return l.f < r.f;

}

const int VMAX = 1e5+10;

const int MMAX = 1e5+10;

const ll INF = 1e15;

int V,M;



int main(void){

  SPEEDUP

  cout << setprecision(15);

  cin >> V >> M;

  vector<edge> v(M);

  rep(i,M) cin >> v[i].f >> v[i].t >> v[i].c;

  sort(all(v),comp);

  SegmentTree< ll > minseg(V+1, [](ll a, ll b){ return min(a,b); }, INF);

  minseg.set(1,0);

  minseg.build();

  rep(i,M){

    ll c = minseg.query(v[i].f,v[i].t);

    minseg.update(v[i].t,min(minseg[v[i].t],c+v[i].c));

  }

  if(minseg[V]==INF)cout << -1 << endl;

  else cout << minseg[V] << endl;

  return 0;

}
