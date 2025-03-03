#include "stdc++.h"

#define LL long long

#define dob complex<double>

#define Abs(a) ((a) < 0 ? (-(a)) : (a))

#define Max(a, b) ((a) > (b) ? (a) : (b))

#define Min(a, b) ((a) < (b) ? (a) : (b))

#define Swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

#define writeln(x) (write(x), putchar('\n'))

#define lowbit(x) ((x)&(-(x)))

using namespace std;

const int N = 100000;

const int yzd = 1e9+7;

void read(int &x) {

    char ch; bool flag = 0;

    for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());

    for (x = 0; isdigit(ch); x = (x<<1)+(x<<3)+ch-48, ch = getchar());

    x *= 1-2*flag;

}

void print(int x) {if (x > 9) print(x/10); putchar(x%10+48); }

void write(int x) {if (x < 0) putchar('-'); print(Abs(x)); }



int n, m, s, t, u, v, c;

struct tt {int to, next, cost; }edge[(N<<2)+5];

int path[N+5], top;

int ans1[N+5], ans2[N+5], vis[N+5], in[N+5];

LL dist1[N+5], dist2[N+5];

queue<int>Q;

vector<int>to[N+5];



void add(int u, int v, int c) {

    edge[++top].to = v, edge[top].cost = c, edge[top].next = path[u], path[u] = top;

}

void SPFA(int s, LL *dist) {

    dist[s] = 0; Q.push(s); vis[s] = 1;

    while (!Q.empty()) {

    int u = Q.front(); Q.pop(); vis[u] = 0;

    for (int i = path[u]; i; i = edge[i].next)

        if (dist[edge[i].to] > dist[u]+edge[i].cost) {

        dist[edge[i].to] = dist[u]+edge[i].cost;

        if (!vis[edge[i].to]) {

            vis[edge[i].to] = 1; Q.push(edge[i].to);

        }

        }

    }

}

void topsort(int s, LL *dist, int *ans) {

    for (int u = 1; u <= n; u++) {

    to[u].clear();

    for (int i = path[u]; i; i = edge[i].next)

        if (dist[edge[i].to] == dist[u]+edge[i].cost) to[u].push_back(edge[i].to), ++in[edge[i].to];

    }

    ans[s] = 1; Q.push(s);

    while (!Q.empty()) {

    int u = Q.front(), size = to[u].size(); Q.pop();

    for (int i = 0; i < size; i++) {

        if (--in[to[u][i]] == 0) Q.push(to[u][i]); (ans[to[u][i]] += ans[u]) %= yzd;

    }

    }

}

void work() {

    read(n), read(m), read(s), read(t);

    for (int i = 1; i <= m; i++) {

    read(u), read(v), read(c); add(u, v, c); add(v, u, c);

    }

    memset(dist1, 127/3, sizeof(dist1));

    SPFA(s, dist1); topsort(s, dist1, ans1);

    memset(dist2, 127/3, sizeof(dist2));

    SPFA(t, dist2); topsort(t, dist2, ans2);

    int ans = 1ll*ans1[t]*ans1[t]%yzd;

    for (int u = 1; u <= n; u++) {

    if (dist1[u] == dist2[u] && dist2[u]*2 == dist1[t]) (ans -= 1ll*ans1[u]*ans1[u]%yzd*ans2[u]%yzd*ans2[u]%yzd) %= yzd;

    for (int i = path[u]; i; i = edge[i].next)

        if (dist1[u]+edge[i].cost+dist2[edge[i].to] == dist1[t] && dist1[u]*2 < dist1[t] && dist2[edge[i].to]*2 < dist1[t])

        (ans -= 1ll*ans1[u]*ans1[u]%yzd*ans2[edge[i].to]%yzd*ans2[edge[i].to]%yzd) %= yzd;

    }

    writeln((ans+yzd)%yzd);

}

int main() {

    work();

    return 0;

}