#include <cstdlib>

#include <cmath>

#include <climits>

#include <cfloat>

#include <map>

#include <utility>

#include <set>

#include <iostream>

#include <memory>

#include <string>

#include <vector>

#include <algorithm>

#include <functional>

#include <sstream>

#include <deque>

#include <complex>

#include <stack>

#include <queue>

#include <cstdio>

#include <cctype>

#include <cstring>

#include <ctime>

#include <iterator>

#include <bitset>

#include <numeric>

#include <list>

#include <iomanip>

#include <cassert>

using namespace std;



const int INF = 1e6;



int n, m;

struct edge { int d, w; };

vector<edge> g[110];

int W[10010];



int dfs(int u, int l, int r, int *vis) {

    int res = 1;

    vis[u] = true;

    for (int i = 0; i < (int)g[u].size(); ++i) {

        edge &e = g[u][i];

        if (!vis[e.d] && l <= e.w && e.w <= r) {

            res += dfs(e.d, l, r, vis);

        }

    }

    return res;

}



bool check(int l, int r) {

    int vis[110];

    memset(vis, 0, sizeof vis);

    return dfs(0, l, r, vis) == n;

}



int main() {

    srand(958270938);

    while (cin >> n && n) {

        cin >> m;

        for (int i = 0; i < n; i++) {

            g[i].clear();

        }

        for (int i = 0; i < m; i++) {

            int a, b, w;

            cin >> a >> b >> w;

            --a; --b;

            g[a].push_back({ b,w });

            g[b].push_back({ a,w });

            W[i] = w;

        }



        sort(W, W + m);

        const int k = unique(W, W + m) - W;

        random_shuffle(W, W + k);



        int ans = INF;

        if (check(0, INF)) {

            for (int i = 0; i < k; ++i) {

                if (!check(W[i], W[i] + ans - 1)) continue;

                int lo = W[i] - 1;

                int hi = INF;

                while (lo + 1 < hi) {

                    int mid = (lo + hi) / 2;

                    if (check(W[i], mid)) {

                        hi = mid;

                    } else {

                        lo = mid;

                    }

                }

                ans = min(ans, hi - W[i]);

            }

        }

        if (ans == INF) ans = -1;

        cout << ans << '\n';

    }

}