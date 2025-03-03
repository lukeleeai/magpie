#define _USE_MATH_DEFINES

#include "stdc++.h"

using namespace std;



//template

#define rep(i,a,b) for(int i=(a);i<(b);i++)

#define rrep(i,a,b) for(int i=(a);i>(b);i--)

#define ALL(v) (v).begin(),(v).end()

typedef long long int ll; typedef pair<ll, ll> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}

const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;

//template end



struct RMQ{

    int n; vector<ll> dat,laz;

    RMQ(){}

    RMQ(int n_){init(n_);}

    void init(int n_){

        n=1; while(n<n_) n*=2;

        dat.clear(); dat.resize(2*n-1,INF);

        laz.clear(); laz.resize(2*n-1,-INF);

    }

    inline void eval(int len,int k){

        if(laz[k]==-INF) return;

        if(k*2+1<n*2-1)laz[k*2+1]=laz[k],laz[k*2+2]=laz[k];

        dat[k]=laz[k];laz[k]=-INF;

    }

    ll update(int a,int b,ll x,int k,int l,int r){

        eval(r-l,k);

        if(r<=a||b<=l) return dat[k];

        if(a<=l&&r<=b) return laz[k]=x;

        eval(r-l,k);

        dat[k]=min(update(a,b,x,k*2+1,l,(l+r)/2),

        update(a,b,x,k*2+2,(l+r)/2,r));

        return dat[k];

    }

    void update(int a,int b,ll x){update(a,b,x,0,0,n);}

    ll query(int a,int b,int k,int l,int r){

        eval(r-l,k);

        if(r<=a||b<=l) return INF;

        if(a<=l&&r<=b) return dat[k];

        return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));

    }

    ll query(int a,int b){return query(a,b,0,0,n);}

};



int main(){

    int n,k; scanf("%d%d",&n,&k);

    vector<int> a(n);

    rep(i,0,n)scanf("%d",&a[i]);

    RMQ seg1(n),seg2(n);

    rep(i,0,n){

        seg1.update(i,i+1,a[i]);

        seg2.update(i,i+1,-a[i]);

    }

    int sum[200010]={};

    rep(i,0,n-1)sum[i+1]=(a[i]>a[i+1]);

    rep(i,0,n)sum[i+1]+=sum[i];

    int ans=0; bool f=0;

    rep(i,0,n-k+1){

        if(sum[i]==sum[i+k-1]){

            f=1; continue;

        }

        if(i&&seg1.query(i-1,i+k-1)==a[i-1]&&seg2.query(i,i+k)==-a[i+k-1])continue;

        ans++;

    }

    printf("%d",ans+f);

    return 0;

}