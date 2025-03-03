#include"stdc++.h"

#define fi first

#define se second

#ifdef CX_TEST

#define Debug printf

#else

#define Debug(...)

#endif

#define LL long long

using namespace std;

typedef pair<int, int> P;

const int maxn = 1e5 + 5;



int a[maxn], b[maxn], c[maxn], p[maxn];

LL s[maxn], d[maxn];

bool vis[maxn];

vector<int> g[maxn];



bool cmp(const int x, const int y) {

    return a[x] < a[y];

}



int ff(int x) {

    if(p[x] != x) p[x] = ff(p[x]);

    return p[x];

}



int main() {

#ifdef CX_TEST

    freopen("E:\\program--GG\\test_in.txt", "r", stdin);

#endif

    int n, m, i, j, u, v;

    scanf("%d%d", &n, &m);

    for(i = 1;i <= n; i++) {

        scanf("%d%d", &a[i], &b[i]);

        a[i] = max(a[i] - b[i], 0);

        s[i] = b[i];

        d[i] = a[i];

    }

    for(i = 0;i < m; i++) {

        scanf("%d%d", &u, &v);

        g[u].push_back(v);

        g[v].push_back(u);

    }

    for(i = 1;i <= n; i++) c[i] = i;

    for(i = 1;i <= n; i++) p[i] = i;

    sort(c + 1, c + n + 1, cmp);

    for(i = 1;i <= n; i++) {

        j = c[i];

        vis[j] = 1;

        for(auto e:g[j]) {

            if(vis[e]) {

                u = ff(j), v = ff(e);

                if(u != v) {

                    s[u] += s[v];

                    p[v] = u;

                    d[u] = min(d[u], d[v] + max(0LL, a[u] - d[v] - s[v]));

                }

            }

        }

    }

    cout << s[c[n]] + d[c[n]] << endl;

    return 0;

}
