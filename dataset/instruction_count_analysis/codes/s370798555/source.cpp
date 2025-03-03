#include "stdc++.h"

#define REP(i,s,e) for(int i=(s); i<(e);i++)

#define rep(i,n) REP(i,0,n)

#define rep1(i,n) REP(i,1,n)

#define repe(i,n) for(auto &&i:n)

#define all(v) (v).begin(),(v).end()

#define decimal fixed<<setprecision(20)

#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

//#define int long long

using LL = long long;

using namespace std;

using Graph = vector<vector<int>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

const LL LLINF = 1e16;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};



int ct[2019];



signed main(){

    fastcin();



    string s;

    cin >> s;

    int n = s.size();

    reverse(all(s));

    int now = 0, pow = 1;

    ct[0] = 1;

    rep(i, n){

        now += (s[i]-'0')*pow;

        now %= 2019;

        ct[now]++;

        pow *= 10;

        pow %= 2019;

    }

    LL ans = 0;

    rep(i, 2019){

        ans += ct[i]*(ct[i]-1)/2;

    }

    cout << ans << endl;

}
