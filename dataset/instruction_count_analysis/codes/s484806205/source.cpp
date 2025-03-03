#include "stdc++.h"

using namespace std;



int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {

        int a, b;

        cin >> a >> b;

        a--, b--;

        adj[a].push_back(b);

        adj[b].push_back(a);

    }



    vector<bool> visited(n);



    function<void(int)> dfs = [&](int v) {

        visited[v] = true;

        for (int a : adj[v]) {

            if (!visited[a]) {

                dfs(a);

            }

        }

    };



    int cnt1 = 0, cnt2 = 0;

    dfs(0);

    for (int i = 0; i < n; i++) {

        if (visited[i]) cnt1++;

    }

    dfs(1);

    for (int i = 0; i < n; i++) {

        if (visited[i]) cnt2++;

    }

    cnt2 -= cnt1;

    int rem = n - (cnt1 + cnt2);

    (cnt1 >= cnt2 ? cnt1 : cnt2) += rem;

    long long es = 1ll * cnt1 * (cnt1 - 1) / 2 + 1ll * cnt2 * (cnt2 - 1) / 2;

    cout << es - m << endl;

}