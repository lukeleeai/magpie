#include "stdc++.h"



#define reg register

#define pr std::pair<ll, int>

#define fi first

#define se second

#define FIN(s) freopen(s, "r", stdin)

#define FOUT(s) freopen(s, "w", stdout)

#define debug(...) fprintf(stderr, __VA_ARGS__)

#define rep(i, l, r) for (int i = l; i <= r; ++i)

#define lep(i, l, r) for (int i = l; i < r; ++i)

#define irep(i, r, l) for (int i = r; i >= l; --i)

#define ilep(i, r, l) for (int i = r; i > l; --i)

#define Rep(i, n) rep(i, 1, n)

#define Lep(i, n) lep(i, 1, n)

#define IRep(i, n) irep(i, n, 1)

#define ILep(i, n) ilep(i, n, 1)

typedef long long ll;

typedef long double ld;



namespace modular {

    const int MOD = 1000000007;

    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }

    inline void inc(int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }

    inline int mul(int x, int y) { return 1LL * x * y % MOD; }

    inline int qpow(int x, int y) {

        int ans = 1;

        for (; y; y >>= 1, x = mul(x, x))

            if (y & 1)

                ans = mul(ans, x);

        return ans;

    }

}; // namespace modular



namespace Base {

    template <typename Tp> inline Tp input() {

        Tp x = 0, y = 1;

        char c = getchar();

        while ((c < '0' || '9' < c) && c != EOF) {

            if (c == '-')

                y = -1;

            c = getchar();

        }

        if (c == EOF)

            return 0;

        while ('0' <= c && c <= '9')

            x = x * 10 + c - '0', c = getchar();

        return x *= y;

    }

    template <typename Tp> inline void read(Tp &x) { x = input<Tp>(); }

    template <typename Tp> inline void chmax(Tp &x, Tp y) { x < y ? x = y : 0; }

    template <typename Tp> inline void chmin(Tp &x, Tp y) { x > y ? x = y : 0; }

}; // namespace Base

using namespace Base;

/*----------------------------------------------------------------------------*/



#define MAX_N 200007

#define V std::vector



int N;

int sz[MAX_N];

ll d[MAX_N];

pr a[MAX_N];

V<int> G[MAX_N];

std::map<ll, int> mp;



void dfs1(int x, int las) {

    sz[x] = 1;

    for (int y : G[x])

        if (y != las) {

            dfs1(y, x);

            sz[x] += sz[y];

            d[x] += d[y] + sz[y];

        }

}



bool dfs2(int x, int las) {

    if (mp[d[x]] != x)

        return false;

    for (int y : G[x])

        if (y != las) {

            d[y] = d[x] + N - 2 * sz[y];

            if (!dfs2(y, x))

                return false;

        }

    return true;

}



void solve() {

    std::sort(a + 1, a + N + 1);

    Rep(i, N) sz[i] = 1, mp[a[i].fi] = a[i].se;

    ILep(i, N) {

        int u = a[i].se, s = N - 2 * sz[u], v;

        if (mp.count(a[i].fi - s)) {

            v = mp[a[i].fi - s];

            sz[v] += sz[u];

            G[u].push_back(v);

            G[v].push_back(u);

        } else

            return puts("-1"), void();

    }

    dfs1(1, 0);

    if (!dfs2(1, 0))

        return puts("-1"), void();

    Rep(i, N) {

        for (int j : G[i])

            if (i < j)

                printf("%d %d\n", i, j);

    }

}



int main() {

#ifdef LOCAL

    FIN("in");

#endif

    read(N);

    Rep(i, N) read(a[i].fi), a[i].se = i;

    solve();

    return 0;

}
