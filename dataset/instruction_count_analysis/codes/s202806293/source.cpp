#include"stdc++.h"

using namespace std;

using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}

template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}





template <typename T>

struct SegmentTree{

  using F = function<T(T,T)>;

  int n;

  F f;

  T ti;

  vector<T> dat;

  SegmentTree(){};

  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){    

    n=1;

    while(n<n_) n<<=1;

    dat.assign(n<<1,ti);

  }

  void build(const vector<T> &v){

    int n_=v.size();

    init(n_);

    for(int i=0;i<n_;i++) dat[n+i]=v[i];

    for(int i=n-1;i;i--)

      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);

  }

  void set_val(int k,T x){

    dat[k+=n]=x;

    while(k>>=1)

      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);    

  }

  T query(int a,int b){

    T vl=ti,vr=ti;

    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {

      if(l&1) vl=f(vl,dat[l++]);

      if(r&1) vr=f(dat[--r],vr);

    }

    return f(vl,vr);

  }

};





struct FastIO{

  FastIO(){

    cin.tie(0);

    ios::sync_with_stdio(0);

  }

}fastio_beet;





template<typename T,T MOD = 1000000007>

struct Mint{

  T v;

  Mint():v(0){}

  Mint(signed v):v(v){}

  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}



  Mint pow(long long k){

    Mint res(1),tmp(v);

    while(k){

      if(k&1) res*=tmp;

      tmp*=tmp;

      k>>=1;

    }

    return res;

  }

  

  Mint inv(){return pow(MOD-2);}

  

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}

  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}

  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}

  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  

  Mint operator+(Mint a) const{return Mint(v)+=a;};

  Mint operator-(Mint a) const{return Mint(v)-=a;};

  Mint operator*(Mint a) const{return Mint(v)*=a;};

  Mint operator/(Mint a) const{return Mint(v)/=a;};



  Mint operator-(){return v?MOD-v:v;}



  bool operator==(const Mint a)const{return v==a.v;}

  bool operator!=(const Mint a)const{return v!=a.v;}

  bool operator <(const Mint a)const{return v <a.v;}

};

//INSERT ABOVE HERE

signed main(){

  int n,q;

  cin>>n>>q;

  vector<int> p(n);  

  for(int i=0;i<n;i++) cin>>p[i],p[i]--;



  using ll = long long;

  using M = Mint<int>;

  using P = pair<M, ll>;

  auto mlcm=[&](ll a,ll b){return a/__gcd(a,b)*b;};

  auto f=[&](P a,P b){

           P c;

           c.second=mlcm(a.second,b.second);

           c.first+=a.first*M(c.second/a.second);

           c.first+=b.first*M(c.second/b.second);

           return c;

         };

  P ti(M(0),1);

  SegmentTree<P> seg(f,ti);

  vector<P> vp(n,ti);

  for(int i=0;i<n;i++){

    ll sum=i+1,cnt=1,pos=p[i];

    while(pos!=i){

      sum+=pos+1;

      cnt++;

      pos=p[pos];

    }

    vp[i].first=M(sum);

    vp[i].second=cnt;

  }

  seg.build(vp);

  

  for(int i=0;i<q;i++){

    int l,r;

    cin>>l>>r;

    l--;

    cout<<seg.query(l,r).first.v<<"\n";   

  }

  cout<<flush;

  return 0;

}


