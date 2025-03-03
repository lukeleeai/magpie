#include <cstdio>

#include <algorithm>

#include <cstring>

using namespace std;



#define clear(x) memset(x, 0, sizeof(x))

#define op(x) ((x) <= n ? (x) + n : (x) - n)

#define mid ((l + r) / 2)

#define ls now * 2

#define rs now * 2 + 1



const int N = 4e4 + 10, M = N * 20;



int hd[N * 5], nxt[M], t[M], ec;

void addEdge(int u, int v) {

    t[++ec] = v;

    nxt[ec] = hd[u];

    hd[u] = ec;

}

struct Flag {

    int pos, id;

    bool operator<(const Flag& f) const { return pos < f.pos; }

    Flag(int pos = 0): pos(pos) {}

} flgs[N * 2];



int n;

int cnt;

int id[N * 5];



void build(int now, int l, int r) {

    id[now] = ++cnt;

    if (l == r) {

        addEdge(id[now], op(flgs[l].id));

        return;

    }

    build(ls, l, mid);

    build(rs, mid + 1, r);

    addEdge(id[now], id[ls]);

    addEdge(id[now], id[rs]);

}



void link(int now, int l, int r, int x, int y, int point) {

    if (y < x) return;

    if (l == x && y == r) addEdge(point, id[now]);

    else if (y <= mid) link(ls, l, mid, x, y, point);

    else if(x > mid) link(rs, mid + 1, r, x, y, point);

    else link(ls, l, mid, x, mid, point), link(rs, mid + 1, r, mid + 1, y, point);

}



#undef mid



int dfn[N * 5], low[N * 5], tim;

int stk[N * 5], tp;

int scc[N * 5], sc;

bool in[N * 5];



void dfs(int u) {

    in[u] = 1;

    dfn[u] = low[u] = ++tim;

    stk[++tp] = u;

    int v;

    for (int i = hd[u]; i; i = nxt[i]) {

        if (!dfn[v = t[i]]) dfs(v), low[u] = min(low[u], low[v]);

        else if (in[v]) low[u] = min(low[u], dfn[v]);

    }

    if (dfn[u] == low[u]) {

        ++sc;

        do {

            scc[v = stk[tp--]] = sc;

            in[v] = 0;

        } while (v != u);

    }

}



bool check(int v) {

    tp = tim = ec = 0;

    clear(hd), clear(dfn), clear(low);

    build(1, 1, cnt = 2 * n);

    int l, r;

    for (int i = 1; i <= 2 * n; i++) {

        l = upper_bound(flgs + 1, flgs + 1 + 2 * n, Flag(flgs[i].pos - v)) - flgs;

        r = upper_bound(flgs + 1, flgs + 1 + 2 * n, Flag(flgs[i].pos + v - 1)) - flgs - 1;

        link(1, 1, 2 * n, l, i - 1, flgs[i].id), link(1, 1, 2 * n, i + 1, r, flgs[i].id);

    }

    for (int i = 1; i <= 2 * n; i++) if (!dfn[i]) dfs(i);

    for (int i = 1; i <= n; i++) if(scc[i] == scc[i + n]) return 0;

    return 1;

}



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d%d", &flgs[i].pos, &flgs[i + n].pos);

        flgs[i].id = i, flgs[i + n].id = i + n;

    }



    sort(flgs + 1, flgs + n * 2 + 1);

    

    int l = 0, r = flgs[2 * n].pos - flgs[1].pos + 1, mid, ans;

    while (l <= r) {

        mid = (l + r) / 2;

        if (check(mid)) l = mid + 1, ans = mid;

        else r = mid - 1;

    }



    printf("%d", ans);

}