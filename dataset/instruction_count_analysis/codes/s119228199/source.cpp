#include "stdc++.h"



using namespace std;

#define pb push_back

#define sz(x) ((int)x.size())

#define all(x) x.begin(), x.end()

#define se second

#define fi first



using ll=long long;



using pii=pair<ll, ll>;

const int mn = 2e5 + 5;

const int mod = 1e9 + 7;

int n, h, w;



struct node {

    int x, y, value;



    bool operator<(const node &p) const {

        return value > p.value;

    }

};



namespace Union_find_set {

    int f[mn];

    int sz[mn];// 并查集 i 的大小



    void init(int n) { // 初始化

        for (int i = 1; i <= n; i++) {

            f[i] = i;

            sz[i] = 1;

        }

    }



    int sf(int x) { // 找爸爸

        if (f[x] == x) return x;

        if (sf(f[x]) != f[x]) {

            f[x] = sf(f[x]);

        }

        return f[x];

    }



    void Union(int u, int v) { // 合并

        u = sf(u), v = sf(v);

        if (u != v) {

            f[u] = v;// 把 u 接到 v 尾部

            sz[v] += sz[u];

            sz[u] = 0;

        }

    }



    int getSize(int x) {

        return sz[sf(x)];

    }

}

using namespace Union_find_set;



int main() {

    //cin.sync_with_stdio(0);

#ifdef trote

    freopen("../1.txt", "r", stdin);

#endif

    scanf("%d%d%d", &n, &h, &w);

    init(h + w);

    vector<node> g;

    for (int i = 1; i <= n; i++) {

        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        g.pb({a, b, c});

    }

    sort(all(g));

    ll ans = 0;

    for (auto &&p:g) {

        if (sf(p.x) == sf(p.y + h)) {

            if (getSize(p.x) < 1) {

                continue;

            } else {

                sz[sf(p.x)]--;

                ans += p.value;

            }

        } else {

            if (getSize(p.x) + getSize(p.y + h) < 1) {

                continue;

            } else {

                ans += p.value;

                Union(p.x, p.y + h);

                sz[sf(p.x)]--;

            }

        }

    }

    printf("%lld\n", ans);



}