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

#include <array>

#include <tuple>

#include <initializer_list>

#include <unordered_set>

#include <unordered_map>

#include <forward_list>

using namespace std;



const int INF = 1e6;



int read() {

    int x = 0;

    char k;

    while (1) {

        if (isdigit(k = getchar())) { x = k - '0'; break; }

    }

    while (1) {

        if (!isdigit(k = getchar())) break;

        x = x * 10 + k - '0';

    }

    return x;

}



void write(int x) {

    int sz = 0;

    char buf[10];

    char m = 0;

    if (x < 0) m = 1, x = -x;

    while (x) buf[sz++] = x % 10 + '0', x /= 10;

    if (m) buf[sz++] = '-';

    if (!sz) buf[sz++] = '0';

    while (sz--) putchar(buf[sz]);

    putchar('\n');

}



int n, m;

struct edge { int d, w; };

vector<edge> g[110];

int W[10010];



int l, r, vis[10010];



int dfs(int u) {

    int res = 1;

    vis[u] = true;

    for (int i = 0; i < (int)g[u].size(); ++i) {

        edge &e = g[u][i];

        if (!vis[e.d] && l <= e.w && e.w <= r) {

            res += dfs(e.d);

        }

    }

    return res;

}



bool check(int l, int r) {

    memset(vis, 0, sizeof vis);

    ::l = l;

    ::r = r;

    int cnt = dfs(0);

    return cnt == n;

}



int main() {

    srand(time(0));

    while (n = read()) {

        m = read();

        for (int i = 0; i < n; i++) {

            g[i].clear();

        }

        for (int i = 0; i < m; i++) {

            int a = read() - 1, b = read() - 1, w = read();

            g[a].push_back({ b,w });

            g[b].push_back({ a,w });

            W[i] = w;

        }



        sort(W, W + m);

        const int k = unique(W, W + m) - W;

        random_shuffle(W, W + k);



        if (!check(0, INF)) {

            write(-1);

        } else {

            int ans = INF;

            for (int i = 0; i < k; ++i) {

                if (!check(W[i], W[i] + ans)) continue;

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

            write(ans);

        }

    }

}