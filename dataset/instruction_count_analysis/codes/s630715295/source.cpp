#include "stdc++.h"

using namespace std;



const int N = 3010;



typedef long long LL;



struct edge {

    int to, next, w, c;

} e[N * 10];



int head[N], ecnt = 1;



inline void adde(int from, int to, int w, int c) {

    e[++ecnt] = (edge){to, head[from], w, -c}, head[from] = ecnt;

    e[++ecnt] = (edge){from, head[to], 0, c}, head[to] = ecnt;

}



int vis[N], cur[N]; LL dis[N];



inline bool SPFA(int s, int t) {

    memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis));

    queue<int> q; q.push(t), vis[t] = 1, dis[t] = 0;

    while (!q.empty()) {

        int u = q.front(); q.pop(), vis[u] = 0;

        for (int i = head[u]; i; i = e[i].next)

            if (e[i ^ 1].w && dis[e[i].to] > dis[u] - e[i].c) {

                dis[e[i].to] = dis[u] - e[i].c;

                if (!vis[e[i].to]) q.push(e[i].to), vis[e[i].to] = 1;

            }

    }

    return dis[s] < 1e17;

}



LL ans;



int DFS(int u, int t, int f) {

    if (u == t || !f) return f;

    int res = 0; vis[u] = 1;

    for (int &i = cur[u], tmp; i; i = e[i].next)

        if (!vis[e[i].to] && e[i].w && dis[u] - e[i].c == dis[e[i].to] && 

            (tmp = DFS(e[i].to, t, min(f, e[i].w)))) {

                res += tmp, f -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp, ans += (LL)tmp * e[i].c;

                if (!f) break;

            }

    return res;

}



inline LL dinic(int s, int t) {

    while (SPFA(s, t)) memcpy(cur, head, sizeof(head)), DFS(s, t, 1e9);

    return ans;

}



int main() {

    int n, s, t; scanf("%d", &n), s = n * 2 + 5, t = s + 1;

    for (int i = 1; i <= n; i++) {

        int x, y, c; scanf("%d%d%d", &x, &y, &c);

        adde(s, i, c, 0);

        adde(i, 2 * n + 1, 1e9, -x - y), adde(i, 2 * n + 2, 1e9, x + y);

        adde(i, 2 * n + 3, 1e9, y - x), adde(i, 2 * n + 4, 1e9, x - y);

    }

    for (int i = 1; i <= n; i++) {

        int x, y, c; scanf("%d%d%d", &x, &y, &c);

        adde(i + n, t, c, 0);

        adde(2 * n + 1, i + n, 1e9, x + y), adde(2 * n + 2, i + n, 1e9, -x - y);

        adde(2 * n + 3, i + n, 1e9, x - y), adde(2 * n + 4, i + n, 1e9, y - x);

    }

    printf("%lld\n", -dinic(s, t));

    return 0;

}//