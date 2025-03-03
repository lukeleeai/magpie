#include "stdc++.h"

using namespace std;

using i64 = int64_t;

using vi = vector<i64>;

using vvi = vector<vi>;



int main() {

    int n, m;

    cin >> n >> m;

    vvi adj(n + m);

    for (int i = 0; i < n; i++) {

        int k;

        cin >> k;

        for (int j = 0; j < k; j++) {

            int a;

            cin >> a;

            a--;

            adj[i].push_back(n + a);

            adj[n + a].push_back(i);

        }

    }



    vi visited(n + m);

    function<void(int, int)> dfs = [&](int v, int p) {

        visited[v] = 1;

        for (int s : adj[v]) {

            if (s != p && !visited[s]) {

                dfs(s, v);

            }

        }

    };



    dfs(0, -1);



    int ok = 1;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            ok = 0;

            break;

        }

    }

    cout << (ok ? "YES" : "NO") << endl;

}