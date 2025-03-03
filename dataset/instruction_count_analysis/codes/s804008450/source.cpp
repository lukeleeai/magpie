#include "stdc++.h"

using namespace std;

using ll = long long;

using ii = pair<int, int>;

using iii = pair<ii, int>;

#define vt vector

#define pq priority_queue

#define pb push_back

#define mp make_pair

#define fi first

#define se second

const int MOD = 1e9 + 7;

const int INF = 2e9;

const int N = 1e5 + 5;



int n, m, a, b, ans;

int par[N];

bool vis[N];



void init() {

    for(int i = 1; i <= n; i++) par[i] = i;

}



int root(int x) {

    return par[x] == x ? x : par[x] = root(par[x]);

}



void join(int x, int y) {

    par[root(x)] = root(y);

}



void solve() {

    int T = 1;

    // cin >> T;

    for(int tc = 1; tc <= T; tc++) {

        cin >> n >> m;

        init();

        while(m--) {

            cin >> a >> b;

            join(a, b);

        }

        for(int i = 1; i <= n; i++) {

            if(!vis[root(i)]) {

                vis[root(i)] = true;

                ans++;

            }

        }

        cout << ans - 1 << "\n";

    }

}



int main() {

 

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    

    solve();

    

}