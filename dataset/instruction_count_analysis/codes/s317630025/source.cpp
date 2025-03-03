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

using pii = pair<int, int>;

using pil = pair<int, ll>;

using pli = pair<ll, int>;

using pll = pair<ll, ll>;

const int MOD = 1000000007;

//const int MOD = 998244353;

const int inf = (1<<30)-1;

const ll INF = (1LL<<60)-1;

const double pi = acos(-1.0);

const double EPS = 1e-10;

template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};

template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};



struct Graph{

    vector<vector<int>> es;

    vector<double> ex, up, ans;

    vector<int> cnt;

    const int n;



    Graph(int n) : n(n){

        es.resize(n);

        ex.resize(n), up.resize(n), ans.resize(n), cnt.resize(n);

    }



    void add_edge(int from, int to, bool directed = false){

        es[from].pb(to);

        if(!directed) es[to].pb(from);

    }



    double dfs1(int now, int pre){

        ex[now] = 0.0, cnt[now] = 0;

        for(auto &e: es[now]){

            if(e == pre) continue;

            cnt[now]++;

            ex[now] += dfs1(e, now);

        }

        if(cnt[now] == 0) return ex[now];

        return ex[now] = 1.0+ex[now]/cnt[now];

    }



    void dfs2(int now, int pre){

        for(auto &e: es[now]){

            if(e == pre) continue;

            if(pre == -1){

                if(cnt[now] == 1) up[e] = 0.0;

                else up[e] = 1.0+((ex[now]-1.0)*cnt[now]-ex[e])/(cnt[now]-1);

            }

            else{

                up[e] = 1.0+((ex[now]-1.0)*cnt[now]-ex[e]+up[now])/cnt[now];

            }

            dfs2(e, now);

        }

    }



    void solve(int root = 0){

        dfs1(root, -1), dfs2(root, -1);

        rep(i, n){

            if(i == root) ans[i] = ex[i];

            else ans[i] = 1.0+((ex[i]-1.0)*cnt[i]+up[i])/(cnt[i]+1);

        }

        rep(i, n) cout << sp(10) << ans[i] << endl;

    }

};



int main(){

    int N;

    cin >> N;

    Graph G(N);

    rep(i, N-1){

        int u, v; cin >> u >> v; u--, v--;

        G.add_edge(u, v);

    }

    G.solve();

}