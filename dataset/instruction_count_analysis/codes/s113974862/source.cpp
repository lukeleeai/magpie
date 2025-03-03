#include "stdc++.h"

const int INF = 1e9;

const int MOD = 1e9+7;

const long long LINF = 1e18;

#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define rep(i,n) for(int i=0;i<(n);++i)

#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

typedef long long ll;

using namespace std;

typedef pair<ll, ll> P;



template<typename T>

void print(const vector<T> &x) {

    int n = x.size();

    rep(i,n) {

        cout << x[i];

        if (i!=n-1) cout<<" ";

        else cout << endl;

    }

}



template<typename T>

void print(const vector<vector<T>> &x) {

    int n = x.size();

    rep(i,n) {

        rep(j,x[i].size()) {

            cout << x[i][j] << " ";

        }

        cout << endl;

    }

}



template<typename T>

void print(const vector<T> &x, int n) {

    rep(i,n) {

        cout << x[i];

        if (i!=n-1) cout<<" ";

        else cout << endl;

    }

}



template<typename T>

void print(const vector<vector<T>> &x, int n, int m) {

    rep(i,n) {

        rep(j,m) {

            cout << x[i][j] << " ";

        }

        cout << endl;

    }

}



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



void input_init() {

    cin.tie(0); ios::sync_with_stdio(false);

}



ll calc_even(int n, const vector<ll> &a) {

    vector<vector<ll>> dp(3, vector<ll>(n+10, -LINF));

    dp[0][0] = a[0];

    dp[1][1] = a[1];



    rep(i,n) {

        if (i+2 < n) chmax(dp[0][i+2], dp[0][i] + a[i+2]);

        if (i+3 < n) chmax(dp[1][i+3], dp[0][i] + a[i+3]);

        if (i+2 < n) chmax(dp[1][i+2], dp[1][i] + a[i+2]);

    }



    return max(dp[0][n-2], dp[1][n-1]);

}



ll calc_odd(int n, const vector<ll> &a) {

    vector<vector<ll>> dp(3, vector<ll>(n+10, -LINF));

    dp[0][0] = a[0];

    dp[1][1] = a[1];

    dp[2][2] = a[2];



    rep(i,n) {

        if (i+2 < n && i+2 != n-1) chmax(dp[0][i+2], dp[0][i]+a[i+2]);

        if (i+3 < n) chmax(dp[1][i+3], dp[0][i]+a[i+3]);

        if (i+4 < n) chmax(dp[2][i+4], dp[0][i]+a[i+4]);

        if (i+2 < n) chmax(dp[1][i+2], dp[1][i]+a[i+2]);

        if (i+3 < n) chmax(dp[2][i+3], dp[1][i]+a[i+3]);

        if (i+2 < n) chmax(dp[2][i+2], dp[2][i]+a[i+2]);

    }



    return max({dp[0][n-3], dp[1][n-2], dp[2][n-1]});

}



int main(int argc, char const *argv[]) {

    int n; cin>>n;

    vector<ll> a(n);

    rep(i,n) cin>>a[i];



    if (n%2==0) {

        cout << calc_even(n,a) << '\n';

    }

    else {

        cout << calc_odd(n,a) << '\n';

    }



    return 0;

}