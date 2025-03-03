#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#define rep2(i, x, n) for(int i = x; i <= n; i++)

#define rep3(i, x, n) for(int i = x; i >= n; i--)

#define elif else if

#define sp(x) fixed << setprecision(x)

#define pb push_back

#define eb emplace_back

#define all(x) x.begin(), x.end()

#define sz(x) (int)x.size()

using ll = long long;

using ld = long double;

using pii = pair<int, int>;

using pil = pair<int, ll>;

using pli = pair<ll, int>;

using pll = pair<ll, ll>;

const ll MOD = 1e9+7;

//const ll MOD = 998244353;

const int inf = (1<<30)-1;

const ll INF = (1LL<<60)-1;

const ld EPS = 1e-10;

template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};

template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};



const int MAX_V = 150000;

vector<int> es[MAX_V];

ld dp1[MAX_V], dp2[MAX_V];



ld dfs1(int now, int pre){

    dp1[now] = 0.0;

    ld cnt = 0.0;

    for(auto &e: es[now]){

        if(e == pre) continue;

        cnt += 1.0;

        dp1[now] += dfs1(e, now)+1.0;

    }

    if(cnt > EPS) dp1[now] /= cnt;

    return dp1[now];

}



void dfs2(int now, int pre){

    if(pre == -1) dp2[now] = 0.0;

    elif(pre == 0){

        ld n = sz(es[pre]);

        if(abs(n-1.0) < EPS) dp2[now] = 1.0;

        else dp2[now] = 2.0 + (dp1[pre]-dp1[now]/n-1.0)*n/(n-1);

    }

    else{

        ld n = sz(es[pre])-1;

        dp2[now] = 2.0 + (dp1[pre]-dp1[now]/n-1.0) + (dp2[pre]-1.0)/n;

    }

    for(auto &e: es[now]){

        if(e != pre) dfs2(e, now);

    }

}



int main(){

    int N;

    cin >> N;

    rep(i, N-1){

        int u, v; cin >> u >> v; u--, v--;

        es[u].pb(v), es[v].pb(u);

    }

    dfs1(0, -1), dfs2(0, -1);

    rep(i, N){

        ld ans;

        if(i == 0) ans = dp1[i];

        else{

            ld n = sz(es[i]);

            ans = ((n-1)*dp1[i]+dp2[i])/n;

        }

        cout << sp(10) << ans << endl;

    }

}