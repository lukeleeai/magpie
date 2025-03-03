#include <algorithm>

#include <cstdio>

#include <cstring>

#include <vector>



using namespace std;



const int N = 1e4 + 5;



struct flag {

    int pos, idx;

    inline bool operator < (const flag& a) const { return pos < a.pos; }

    inline flag(int p = 0, int id = 0) : pos(p), idx(id) { }

} f[N << 1];

int n;



const int V = N << 3;

int vc, refer[V];

vector<int> G[V];

int dfn[V], low[V], timer;

int stk[V], top; bool inS[V];

int cmp[V], scc;



inline void addEdge(int fr, int to) {

    G[fr].push_back(to);

}



#define mid ((l + r) >> 1)

#define op(x) ((x) <= n ? (x) + n : (x) - n)

void build(int l, int r, int x) {

    refer[x] = ++vc;

    if (l == r)

        return addEdge(refer[x], op(f[l].idx));

    build(l, mid, x << 1);

    addEdge(refer[x], refer[x << 1]);

    build(mid + 1, r, x << 1 | 1);

    addEdge(refer[x], refer[x << 1 | 1]);

}

#undef op



void link(int l, int r, int x, int ql, int qr, int p) {

    if (ql <= l && r <= qr) return addEdge(p, refer[x]);

    if (ql <= mid) link(l, mid, x << 1, ql, qr, p);

    if (qr > mid) link(mid + 1, r, x << 1 | 1, ql, qr, p);

}

#undef mid



void tarjan(int x) {

    dfn[x] = low[x] = ++timer;

    inS[stk[++top] = x] = 1;

    for (auto y : G[x]) {

        if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);

        else if (inS[y]) low[x] = min(low[x], dfn[y]);

    }

    if (low[x] == dfn[x]) {

        ++scc;

        for (; ; ) {

            int k = stk[top--];

            cmp[k] = scc, inS[k] = 0;

            if (k == x) break;

        }

    }

}



#define CLR(x, v) memset(x, v, sizeof(x))

bool judge(int d) {

    for (int i = 1; i < n * 7; i++) G[i].clear();

    CLR(dfn, 0), CLR(low, 0), CLR(cmp, 0);

    CLR(stk, 0), CLR(inS, 0);

    timer = top = scc = 0, CLR(refer, 0);



    vc = n * 2, build(1, n * 2, 1);

    for (int i = 1; i <= n * 2; i++) {

        int l = upper_bound(f + 1, f + 1 + n * 2, flag(f[i].pos - d)) - f;

        int r = upper_bound(f + 1, f + 1 + n * 2, flag(f[i].pos + d - 1)) - f - 1;

        if (l < i) link(1, n * 2, 1, l, i - 1, f[i].idx);

        if (i < r) link(1, n * 2, 1, i + 1, r, f[i].idx);

    }



    for (int i = 1; i <= n * 2; i++)

        if (!dfn[i]) tarjan(i);

    for (int i = 1; i <= n; i++)

        if (cmp[i] == cmp[i + n]) return 0;

    return 1;

}

#undef CLR



signed main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d%d", &f[i].pos, &f[i + n].pos);

        f[i].idx = i, f[i + n].idx = i + n;

    }

    sort(f + 1, f + 1 + n * 2);



    int lb = 0, ub = f[n * 2].pos - f[1].pos + 1, ans = 0;

    while (lb <= ub) {

        int mid = (lb + ub) >> 1;

        if (judge(mid)) ans = mid, lb = mid + 1;

        else ub = mid - 1;

    }



    printf("%d\n", ans);

    return 0;

}