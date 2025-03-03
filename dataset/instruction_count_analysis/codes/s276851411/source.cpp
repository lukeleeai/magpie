#define _USE_MATH_DEFINES

#include "stdc++.h"

using namespace std;



//template

#define rep(i,a,b) for(int i=(a);i<(b);i++)

#define rrep(i,a,b) for(int i=(a);i>(b);i--)

#define ALL(v) (v).begin(),(v).end()

typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;

template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }

template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }

//template end



int mod=998244353;

struct Mint {

    int val;

    Mint inv() const{

        int tmp,a=val,b=mod,x=1,y=0;

        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);

        return Mint(x);

    }

public:

    Mint():val(0){}

    Mint(ll x){if((val=x%mod)<0)val+=mod;}

    Mint pow(ll t){Mint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}

    Mint& operator+=(const Mint& x){if((val+=x.val)>=mod)val-=mod;return *this;}

    Mint& operator-=(const Mint& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}

    Mint& operator*=(const Mint& x){val=(ll)val*x.val%mod; return *this;}

    Mint& operator/=(const Mint& x){return *this*=x.inv();}

    Mint operator+(const Mint& x) const{return Mint(*this)+=x;}

    Mint operator-(const Mint& x) const{return Mint(*this)-=x;}

    Mint operator*(const Mint& x) const{return Mint(*this)*=x;}

    Mint operator/(const Mint& x) const{return Mint(*this)/=x;}

};

struct factorial {

    vector<Mint> Fact, Finv;

public:

    factorial(int maxx){

        Fact.resize(maxx+1),Finv.resize(maxx+1); Fact[0]=Mint(1); rep(i,0,maxx)Fact[i+1]=Fact[i]*(i+1);

        Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*i;

    }

    Mint fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}

    Mint nPr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[n-r];}

    Mint nCr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[r]*Finv[n-r];}

};



int sz,bit[200010];

void init(int _n){

    sz=_n; rep(i,0,sz+1)bit[i]=0;

}

void add(int i,int x){

    i++;

    while(i<=sz){

        bit[i]+=x; i+=(i&-i);

    }

}

ll sum(int i){

    i++; ll res=0;

    while(i){

        res+=bit[i]; i-=(i&-i);

    }return res;

}



int cnt[200010][4]={};



int main(){

    int n; scanf("%d",&n);

    vector<int> x(n),y(n);

    rep(i,0,n)scanf("%d%d",&x[i],&y[i]);

    vector<int> val=x;

    sort(ALL(val)); val.erase(unique(ALL(val)),val.end());

    rep(i,0,n)x[i]=lower_bound(ALL(val),x[i])-val.begin();

    val=y; sort(ALL(val)); val.erase(unique(ALL(val)),val.end());

    rep(i,0,n)y[i]=lower_bound(ALL(val),y[i])-val.begin();

    vector<int> ord(n); iota(ALL(ord),0);

    sort(ALL(ord),[&](int i,int j){return x[i]<x[j];});

    int cur=0; init(n);

    for(int i:ord){

        cnt[i][0]=sum(y[i]); cnt[i][1]=cur-sum(y[i]);

        cur++; add(y[i],1);

    }

    init(n); reverse(ALL(ord)); cur=0;

    for(int i:ord){

        cnt[i][2]=sum(y[i]); cnt[i][3]=cur-sum(y[i]);

        cur++; add(y[i],1);

    }

    Mint base=2,ans=base.pow(n-1)*Mint(n);

    rep(i,0,n){

        ans+=base.pow(cnt[i][0])*base.pow(cnt[i][3])*(base.pow(cnt[i][1])-1)*(base.pow(cnt[i][2])-1);

        ans+=base.pow(cnt[i][1])*base.pow(cnt[i][2])*(base.pow(cnt[i][0])-1)*(base.pow(cnt[i][3])-1);

        ans-=(base.pow(cnt[i][0])-1)*(base.pow(cnt[i][3])-1)*(base.pow(cnt[i][1])-1)*(base.pow(cnt[i][2])-1);

    }

    printf("%d\n",ans.val);

    return 0;

}