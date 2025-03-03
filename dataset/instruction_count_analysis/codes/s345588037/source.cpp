#include "stdc++.h"

using namespace std;

#define repr(i,a,b) for(int i=a;i<b;i++)

#define rep(i,n) for(int i=0;i<n;i++)

#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)

#define reprev(i,n) reprrev(i,0,n)

typedef long long ll;

typedef unsigned long long ull;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



const ll mod = 1e9+7;



void chmod(ll &M){

    if(M >= mod) M %= mod;

    else if(M < 0){

        M += (abs(M)/mod + 1)*mod;

        M %= mod;

    }

}



ll modpow(ll x, ll n){

    if(n==0) return 1;

    ll res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;

    else return res*res%mod*x%mod;

}



int getl(int i, int N) { return i==0? N-1:i-1; };

int getr(int i, int N) { return i==N-1? 0:i+1; };



// 線分 ab の偏角 返り値は[-π, π]

double argument(const pair<double, double> &a, const pair<double, double> &b){

    double ax=a.first, ay=a.second, bx=b.first, by=b.second;

    return atan2(by-ay, bx-ax);

}



// get<K>(tuple型の変数)



/* <-----------------------------------------------------------------------------------> */

/* <-----------------------------------------------------------------------------------> */

/* <-----------------------------------------------------------------------------------> */

/* <-----------------------------------------------------------------------------------> */





const long double pi = acos(-1);

const long double eps = 0.000000001;



long double a, b, x;



long double f(long double theta){

    if(theta > pi / 2.0 - eps) return 0;

    if(a*tan(theta) <= b) return a * a * b - a * a * a * tan(theta) / 2;

    else return a * b * b / tan(theta) / 2;

}



void input(){

    cin >> a >> b >> x;

}



void solve(){

    input();

    long double ok = pi / 2.0;

    long double ng = 0.0;

    for(int _=0; _<100000; ++_){

        long double mid = (ok + ng) / 2.0;

        (f(mid) < x? ok:ng) = mid;

    }

    cout << setprecision(13) << ok * 180 / pi << endl;

}



int main(){

    cin.tie(nullptr);

    ios::sync_with_stdio(false);



    solve();

    

    return 0;

}