#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<ll,ll> P;

typedef pair<int,int> Pi;

#define rep(i,n) for(ll i=0;i<n;i++)

#define FOR(i,a,b) for(ll i=a;i<b;i++)

#define fi first

#define se second

#define endl "\n"



template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}

template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}

template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}

template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}

template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}

template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}

template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}



const ll mod=1'000'000'007;

const ll inf=1'000'000'000'000'000'00;

const int INF=1'000'000'000;

const double EPS=1e-10;

const double PI=acos(-1);



int main(){

    cin.tie(0);ios::sync_with_stdio(false);

    ll n,k;

    cin>>n>>k;

    vector<ll> a(n),f(n);

    rep(i,n){

        cin>>a[i];

    }

    rep(i,n){

        cin>>f[i];

    }

    sort(begin(a),end(a));

    sort(begin(f),end(f),greater<ll>());

    auto solve=[&](ll x){

        ll cnt=0;

        rep(i,n){

            if(a[i]*f[i]<=x) continue;

            cnt+=a[i]-x/f[i];

        }

        return cnt<=k;

    };

    ll ok=inf,ng=-1,mid;

    while(ok-ng>1){

        mid=(ok+ng)/2;

        if(solve(mid)) ok=mid;

        else ng=mid;

    }

    cout<<ok<<endl;

}