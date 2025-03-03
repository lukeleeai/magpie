#include "stdc++.h"



typedef long long LL;



const int MAXN = 1e5 + 5;



int n, m, w[MAXN];



std::multiset<int> st[MAXN];

std::set<std::pair<int, int> > spec;



int fa[MAXN], part;



int Find(int x) {

    return fa[x] == x ? x : fa[x] = Find(fa[x]);

}



void merge(int u, int v) {

    if (Find(u) == Find(v)) return;

    if (st[fa[u]].size() > st[fa[v]].size()) std::swap(u, v);

    --part;

    for (int i: st[fa[u]]) {

        st[fa[v]].insert(i);

    }

    st[fa[u]].clear();

    if (!st[fa[v]].empty()) spec.insert(std::make_pair(st[fa[v]].size(), fa[v]));

    fa[fa[u]] = fa[v];

}



int main() {

    scanf("%d%d", &n, &m); part = n;

    for (int i = 0; i < n; ++i) {

        fa[i] = i;

        scanf("%d", w + i);

        st[i].insert(w[i]);

        spec.insert(std::make_pair(1, i));

    }

    

    for (int i = 1; i <= m; ++i) {

        static int u, v;

        

        scanf("%d%d", &u, &v);

        spec.erase(spec.find(std::make_pair(st[Find(u)].size(), Find(u))));

        spec.erase(spec.find(std::make_pair(st[Find(v)].size(), Find(v))));

        merge(u, v);

    }

    

    LL ans = 0;

    

    while (part > 1) {

        if (spec.size() < 2) {

            puts("Impossible");

            return 0;

        }

        auto x = *--spec.end();

        spec.erase(--spec.end());

        

        auto y = *--spec.end();

        spec.erase(--spec.end());

        

        int u = x.second, v = y.second;

        ans += *st[Find(u)].begin() + *st[Find(v)].begin();

        

        st[Find(u)].erase(st[Find(u)].begin());

        st[Find(v)].erase(st[Find(v)].begin());

        

        merge(u, v);

    }

    

    printf("%lld\n", ans);

    

    return 0;

}