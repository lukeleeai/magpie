#include "stdc++.h"

#define f first

#define s second

#define pb push_back

#define ENDL '\n'

#define all(a) begin(a),end(a)

#define sz(a) (int)(a.size())

#define deb(a) cout << #a << ": " << a << ENDL

#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)

#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



using namespace std;



typedef long long lli;

typedef long double ld;

typedef pair<lli, lli> ii;

typedef vector<lli> vi;



vector<vector<lli>> graph;

vector<lli> sol;

vector<lli> down;



lli m;



lli ddfs(int u, int pr) {

    lli ans = 1;

    for(auto it : graph[u]) {

        if(it == pr) continue;

        ans = (ans * (1LL + ddfs(it, u))) % m;

    }

    down[u] = ans;

    return ans;

}



lli dfs(int u, int pr, lli up) {

    int sz = sz(graph[u]);

    vector<lli> v(sz);

    fore(i, 0, sz) {

        if(graph[u][i] == pr) {

            v[i] = 1;

            continue;

        }

        v[i] = down[graph[u][i]] + 1;

    }

    vector<lli> prefix(sz);

    vector<lli> suffix(sz);

    prefix[0] = v[0];

    fore(i, 1, sz) prefix[i] = (prefix[i - 1] * v[i]) % m;

    suffix[sz - 1] = v[sz - 1];

    for(int i = sz - 2; i >= 0; --i) suffix[i] = (suffix[i + 1] * v[i]) % m;

    sol[u] = ((up + 1) * suffix[0]) % m;

    fore(i, 0, sz) {

        if(graph[u][i] == pr) continue;

        lli param = (up + 1) % m;

        if(sz == 1) {

            dfs(graph[u][0], u, param);

            break;

        }

        if(i == 0) param = (param * suffix[1]) % m;

        else if(i == (sz - 1)) param = (param * prefix[sz - 2]) % m;

        else param = (((param * prefix[i - 1]) % m) * suffix[i + 1]) % m;

        dfs(graph[u][i], u, param);

    }

    return sol[u];

}



int main()

{   _

    lli n, u, v; cin >> n >> m;

    graph.resize(n);

    sol.resize(n);

    down.resize(n);

    fore(i, 1, n) {

        cin >> u >> v;

        graph[u - 1].pb(v - 1);

        graph[v - 1].pb(u - 1);

    }

    if(n == 1) {

        cout << 1 << ENDL;

        return 0;

    }

    ddfs(0, -1);

    dfs(0, -1, 0);

    fore(i, 0, n) cout << sol[i] << ENDL;

    return 0;

}
