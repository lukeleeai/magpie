#include <iostream>

#include <cstdio>

#include <cmath>

#include <string>

#include <cstring>

#include <algorithm>

#include <limits>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <bitset>

#include <unordered_map>

#include <unordered_set>

#define lowbit(x) ( x&(-x) )

#define pi 3.141592653589793

#define e 2.718281828459045

#define INF 0x3f3f3f3f

#define HalF (l + r)>>1

#define lsn rt<<1

#define rsn rt<<1|1

#define Lson lsn, l, mid

#define Rson rsn, mid+1, r

#define QL Lson, ql, qr

#define QR Rson, ql, qr

#define myself rt, l, r

#define pii pair<int, int>

#define MP(a, b) make_pair(a, b)

using namespace std;

typedef unsigned long long ull;

typedef unsigned int uit;

typedef long long ll;

const int maxN = 1e4 + 7;

int N, a[maxN][2], _UP, l, r, lim, ans;

vector<int> same[maxN << 1];

pii lsan[maxN << 1];

namespace Graph

{

    const int maxP = (maxN << 3) + (maxN << 2);

    vector<int> E[maxP], NE[maxP];

    int root, tot, lc[maxP], rc[maxP];

    void build(int &rt, int fa, int l, int r)

    {

        rt = ++tot;

        if(fa) E[fa].push_back(rt);

        if(l == r) return;

        int mid = HalF;

        build(lc[rt], rt, l, mid);

        build(rc[rt], rt, mid + 1, r);

    }

    void Insert(int rt, int l, int r, int qx, int id)

    {

        if(l == r)

        {

            E[rt].push_back(id);

            return;

        }

        int mid = HalF;

        if(qx <= mid) Insert(lc[rt], l, mid, qx, id);

        else Insert(rc[rt], mid + 1, r, qx, id);

    }

    void update(int rt, int l, int r, int ql, int qr, int fid)

    {

        if(ql <= l && qr >= r)

        {

            NE[fid].push_back(rt);

            return;

        }

        int mid = HalF;

        if(qr <= mid) update(lc[rt], l, mid, ql, qr, fid);

        else if(ql > mid) update(rc[rt], mid + 1, r, ql, qr, fid);

        else { update(lc[rt], l, mid, ql, qr, fid); update(rc[rt], mid + 1, r, ql, qr, fid); }

    }

    int dfn[maxP], low[maxP], tim, Stap[maxP], Stop, Belong[maxP], Bcnt;

    bool instack[maxP];

    inline int another(int x) { return (x & 1) ? x + 1 : x - 1; }

    void Tarjan(int u)

    {

        dfn[u] = low[u] = ++tim;

        Stap[++Stop] = u;

        instack[u] = true;

        for(int v : E[u])

        {

            if(!dfn[v])

            {

                Tarjan(v);

                low[u] = min(low[u], low[v]);

            }

            else if(instack[v]) low[u] = min(low[u], dfn[v]);

        }

        for(int v : NE[u])

        {

            if(!dfn[v])

            {

                Tarjan(v);

                low[u] = min(low[u], low[v]);

            }

            else if(instack[v]) low[u] = min(low[u], dfn[v]);

        }

        if(u <= (N << 1))

        {

            int id = ceil(1. * u / 2), op = !(u & 1), val = a[id][op];

            for(int v : same[val])

            {

                if(another(v) == u) continue;

                if(!dfn[v])

                {

                    Tarjan(v);

                    low[u] = min(low[u], low[v]);

                }

                else if(instack[v]) low[u] = min(low[u], dfn[v]);

            }

        }

        if(dfn[u] == low[u])

        {

            Bcnt++;

            int v;

            do

            {

                v = Stap[Stop--];

                instack[v] = false;

                Belong[v] = Bcnt;

            } while(u ^ v);

        }

    }

    inline bool check()

    {

        for(int i=1; i<=tot; i++)

        {

            NE[i].clear();

            dfn[i] = 0;

            instack[i] = false;

        }

        for(int i=1, ql, qr; i<=N; i++)

        {

            ql = (int)(upper_bound(lsan + 1, lsan + _UP + 1, MP(lsan[a[i][0]].first - lim, INF)) - lsan);

            qr = (int)(lower_bound(lsan + 1, lsan + _UP + 1, MP(lsan[a[i][0]].first + lim, 0)) - lsan - 1);

            if(ql < a[i][0]) update(root, 1, _UP, ql, a[i][0] - 1, 2 * i - 1);

            if(qr > a[i][0]) update(root, 1, _UP, a[i][0] + 1, qr, 2 * i - 1);

            ql = (int)(upper_bound(lsan + 1, lsan + _UP + 1, MP(lsan[a[i][1]].first - lim, INF)) - lsan);

            qr = (int)(lower_bound(lsan + 1, lsan + _UP + 1, MP(lsan[a[i][1]].first + lim, 0)) - lsan - 1);

            if(ql < a[i][1]) update(root, 1, _UP, ql, a[i][1] - 1, 2 * i);

            if(qr > a[i][1]) update(root, 1, _UP, a[i][1] + 1, qr, 2 * i);

        }

        tim = Stop = Bcnt = 0;

        for(int i=1; i<=(N << 1); i++) if(!dfn[i]) Tarjan(i);

        for(int i=1; i<=(N << 1); i += 2)

        {

            if(Belong[i] == Belong[i + 1]) return false;

        }

        return true;

    }

    void G_init()

    {

        root = 0;

        tot = N << 1;

        build(root, 0, 1, _UP);

        for(int i=1; i<=N; i++)

        {

            Insert(root, 1, _UP, a[i][0], 2 * i);

            Insert(root, 1, _UP, a[i][1], 2 * i - 1);

        }

    }

};

using namespace Graph;

int main()

{

    scanf("%d", &N);

    _UP = 0;

    for(int i=1; i<=N; i++) { scanf("%d%d", &a[i][0], &a[i][1]); lsan[++_UP] = MP(a[i][0], i * 2 - 1); lsan[++_UP] = MP(a[i][1], i * 2); }

    sort(lsan + 1, lsan + _UP + 1);

    for(int i=1; i<=N; i++)

    {

        a[i][0] = (int)(lower_bound(lsan + 1, lsan + _UP + 1, MP(a[i][0], i * 2 - 1)) - lsan);

        same[a[i][0]].push_back(2 * i);

        a[i][1] = (int)(lower_bound(lsan + 1, lsan + _UP + 1, MP(a[i][1], i * 2)) - lsan);

        same[a[i][1]].push_back(2 * i - 1);

    }

    G_init();

    l = 1; r = 1e9;

    ans = 0;

    while(l <= r)

    {

        lim = HalF;

        if(check())

        {

            l = lim + 1;

            ans = lim;

        }

        else r = lim - 1;

    }

    printf("%d\n", ans);

    return 0;

}
