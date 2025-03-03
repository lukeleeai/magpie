#include "bits/stdc++.h"

using namespace std;

///////////////////////////////////////////

const long long int INF = 1LL<<60;

const long long int Mod = 1000000007;

using ll = long long int; using ci = const int;

using vi = vector<int>;  using Vi = vector<long long int>;

using P = pair<int, int>;  using PLL = pair<ll, ll>;

using matrix = vector<vector<ll>>;

#define pb(x) push_back(x)

#define mp(x,y) make_pair(x,y)

#define all(x) (x).begin(),(x).end()

#define rep(i,N) for(ll i = 0; i < (ll)N; i++)

#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)

template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }

template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }

template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;

#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート

template<class T> inline void princ(T x){cout<<x<<" ";}; 

template<class T> inline void print(T x){cout<<x<<"\n";};

template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }

template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }

///////////////////////////////////////////////////////////////////////////////////



ll n;

Vi a;



int main(){

    cin.tie(0);ios::sync_with_stdio(false);

    std::cout<<std::fixed<<std::setprecision(30);

    cin>>n;

    a.resize(n);

    ll inp;

    ll tmp = 0;

    rep(i,n){

        cin>>inp;

        a[i] = inp - i-1;

        tmp += a[i];

        //princ(a[i]);

    }

    sort(all(a));

    ll b = a[a.size()/2],b2 = a[a.size()/2+1];

    ll ans = 0,Ans = INF;

    rep(i,n){

        ans += abs(a[i]-b);

    }

    chmin(Ans,ans);

    ans = 0;

    rep(i,n){

        ans += abs(a[i]-b2);

    }

    chmin(Ans,ans);

    print(Ans);

    return 0;

}