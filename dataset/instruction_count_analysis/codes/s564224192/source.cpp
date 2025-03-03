#include "stdc++.h"



using namespace std;



const int maxn = 100010;



typedef long long ll;



priority_queue<ll> pq;

map<ll, int> mp;



int n, l[maxn], dep[maxn], sz[maxn], w[maxn], vis[maxn], e_u[maxn], e_v[maxn], tot, e = 0;

ll D[maxn], S[maxn];



struct Edge {

    int v, x;

} E[maxn];



inline void addEdge(int u, int v) {

    E[e].v = v; E[e].x = l[u]; l[u] = e++;

}



void dfs1(int u) {

    sz[u] = 1;

    for (int p = l[u]; p >= 0; p = E[p].x) {

        int v = E[p].v;

        dep[v] = dep[u] + 1;

        dfs1(v);

        sz[u] += sz[v];

    }

}



void dfs2(int u) {

    for (int p = l[u]; p >= 0; p = E[p].x) {

        int v = E[p].v;

        S[v] = S[u] + n - 2 * sz[v];

        dfs2(v);

    }

}



int main() {

    memset(l, -1, sizeof(l));

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%lld", &D[i]);

    for (int i = 1; i <= n; i++) {

        mp[D[i]] = i;

        pq.push(D[i]);

        w[i] = 1;

    }

    vis[0] = 1;

    while (pq.size() > 1) {

        ll v = pq.top(); pq.pop();

        int u = mp[v];

        vis[u] = 1;

        if (!vis[mp[v + 2 * w[u] - n]]) {

            int t = mp[v + 2 * w[u] - n];

            w[t] += w[u];

            addEdge(t, u);

            ++ tot;

            e_u[tot] = t; e_v[tot] = u;

        } else {

            puts("-1");

            return 0;

        }

    }

    int r = mp[pq.top()];

    dfs1(r);

    for (int i = 1; i <= n; i++) S[r] += dep[i];

    dfs2(r);

    for (int i = 1; i <= 1; i++) {

        if (S[i] != D[i]) {

            puts("-1");

            return 0;

        }

    }

    for (int i = 1; i <= tot; i++) printf("%d %d\n", e_u[i], e_v[i]);

    return 0;

}