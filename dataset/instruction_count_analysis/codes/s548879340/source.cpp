#include "stdc++.h"

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

#define all(x) (x).begin(),(x).end()

#define fi first

#define se second

#define mp make_pair

#define si(x) int(x.size())

const int mod=1000000007,MAX=200005;

const ll INF=1LL<<60;



template<typename T,typename E>

struct LazySegmentTree{

    using F=function<T(T,T)>;

    using G=function<T(T,E)>;

    using H=function<E(E,E)>;

    

    int n;

    vector<T> dat;

    vector<E> lazy;

    F f;

    G g;

    H h;

    T ti;

    E ei;

    

    LazySegmentTree(int n_,F f,G g,H h,T ti,E ei) :f(f),g(g),h(h),ti(ti),ei(ei){

        n=1;

        while(n<n_) n*=2;

        dat.assign(2*n-1,ti);

        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);

        

        lazy.assign(2*n-1,ei);

    }

    

    LazySegmentTree(int n_,vector<T> &v,F f,G g,H h,T ti,E ei) :f(f),g(g),h(h),ti(ti),ei(ei){

        n=1;

        while(n<n_) n*=2;

        dat.assign(2*n-1,ti);

        

        for(int i=n-1;i-(n-1)<v.size();i++) dat[i]=v[i-(n-1)];

        

        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);

        

        lazy.assign(2*n-1,ei);

    }

    

    inline void eval(int k,int l,int r){

        

        if(lazy[k]==ei) return;

        

        dat[k]=g(dat[k],lazy[k]);

        

        if(r-l>1){

            lazy[k*2+1]=h(lazy[k*2+1],lazy[k]);

            lazy[k*2+2]=h(lazy[k*2+2],lazy[k]);

        }

        

        lazy[k]=ei;

    }

    

    void update_(int a,int b,E x,int k,int l,int r){

        

        eval(k,l,r);

        

        if(r<=a||b<=l) return;

        

        if(a<=l&&r<=b){

            lazy[k]=h(lazy[k],x);

            eval(k,l,r);

        }

        

        else{

            update_(a,b,x,2*k+1,l,(l+r)/2);

            update_(a,b,x,2*k+2,(l+r)/2,r);

            dat[k]=f(dat[2*k+1],dat[2*k+2]);

        }

        

    }

    

    void update(int a,int b,E x){

        return update_(a,b,x,0,0,n);

    }

    

    T query_(int a,int b,int k,int l,int r){

        

        eval(k,l,r);

        

        if(r<=a||b<=l) return ti;

        if(a<=l&&r<=b) return dat[k];

        

        T vl=query_(a,b,2*k+1,l,(l+r)/2);

        T vr=query_(a,b,2*k+2,(l+r)/2,r);

        return f(vl,vr);

    }

    

    T query(int a,int b){

        return query_(a,b,0,0,n);

    }

    

    void set(int k,T x){

        dat[n-1+k]=x;

    }

    

    void built(){

        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);

    }

    

};



vector<pair<int,ll>> S[MAX];



int main(){

    

    std::ifstream in("text.txt");

    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);

    ios::sync_with_stdio(false);

    

    int N,M;cin>>N>>M;

    

    vector<ll> def(N,0);

    

    LazySegmentTree<ll,ll> seg(N,

                               def,

                               [](ll a,ll b){return max(a,b);},

                               [](ll a,ll b){return a+b;},

                               [](ll a,ll b){return a+b;},

                               -INF,

                               0);

    

    for(int i=0;i<M;i++){

        int l,r,a;cin>>l>>r>>a;

        l--;r--;

        S[r].push_back(mp(l,a));

    }

    

    for(int i=0;i<N;i++) sort(all(S[i]));

    

    for(int i=0;i<N;i++){

        seg.update(i,i+1,max(0LL,seg.query(0,i)));

        for(auto x:S[i]){

            seg.update(x.fi,i+1,x.se);

        }

    }

    

    cout<<max(0LL,seg.query(0,N))<<endl;

}


