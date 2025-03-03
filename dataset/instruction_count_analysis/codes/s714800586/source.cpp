#include "stdc++.h"

using namespace std;

using ll = long long;

using ld = long double;

using vi = vector<int>;

using vvi = vector<vi>;

using vvvi = vector<vvi>;

using vll = vector<ll>;

using vvll = vector<vll>;

using vvvll = vector<vvll>;

using vs = vector<string>;

using pll = pair<ll, ll>;

using vp = vector<pll>;

#define rep(i, n) for(ll i = 0; i < (n); i++)

#define repr(i, a, b) for(ll i = (a); i < (b); i++)

#define ALL(a) (a).begin(), (a).end()

#define SZ(x) ((ll)(x).size())

const ll MOD = 1000000007;

inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }

inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }

inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }

inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }

template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

#ifdef OJ_LOCAL

#include "dump.hpp"

#else

#define dump(...) ((void)0)

#endif



struct edge{

    int to, cap, rev;

};



const int MAX_V = 5010;

const int INF = 1000000000;



// 入力

int N, R;

vector<edge> G[MAX_V];  // グラフの隣接リスト表現

bool used[MAX_V];       // DFSですでに調べたかのフラグ



// fromからtoへ向かう容量capの辺をグラフに追加する

void add_edge(int from, int to, int cap){

    G[from].push_back((edge){to, cap, G[to].size()});

    G[to].push_back((edge){from, 0, int(G[from].size())-1});

}



// 増加パスをDFSで探す

int dfs(int v, int t, int f){

    if(v == t) return f;

    used[v] = true;

    for(int i = 0; i < int(G[v].size()); i++){

        edge &e = G[v][i];

        if(!used[e.to] && e.cap > 0){

            int d = dfs(e.to, t, min(f, e.cap));

            if(d > 0){

                e.cap -= d;

                G[e.to][e.rev].cap += d;

                return d;

            }

        }

    }

    return 0;

}



// sからtへの最大流を求める

// O(FE) 小さい定数倍

int max_flow(int s, int t){

    int flow = 0;

    for(;;){

        memset(used, 0, sizeof(used));

        int f = dfs(s, t, INF);

        if(f == 0) return flow;

        flow += f;

    }

}





int main(){

    cin.tie(0); ios::sync_with_stdio(false);

    cout << fixed << setprecision(15);

    ll n;

    cin >> n;

    vll a(n), b(n);

    rep(i, n){

        cin >> a[i] >> b[i];

    }

    vll c(n), d(n);

    rep(i, n){

        cin >> c[i] >> d[i];

    }

    

    // 二部マッチング

    rep(i, n)rep(j, n){

        if(a[i] < c[j] && b[i] < d[j]){

            add_edge(i, 5*n+j, 1);

        }

    }

    rep(i, n){

        add_edge(122, i, 1);

    }

    rep(i, n){

        add_edge(5*n+i, 800, 1);

    }

    rep(i, MAX_V){

        for(auto&& e: G[i]){

            //cout << e.to << " " << e.cap << " " << e.rev << endl;

        }

    }

    cout << max_flow(122, 800) << endl;

    return 0;

}