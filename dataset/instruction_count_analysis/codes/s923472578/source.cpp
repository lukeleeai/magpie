#include "stdc++.h"

#define int long long

using namespace std;



struct point {

    int x, y, id;

} p[100001];



struct edge_list {

    int w, u, v;

    bool operator < (const edge_list &o) const {

        return w < o.w;

    }

};



int n, ans = 0, up[100001];

vector <edge_list> edge;



int union_find(int u) {

    if(u == up[u]) {

        return u;

    }

    return up[u] = union_find(up[u]);

}



void union_merge(int u, int v) {

    if(union_find(u) != union_find(v)) {

        up[union_find(u)] = union_find(v);

    }

}



signed main() {

    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {

        up[i] = i;

    }

    for(int i = 1; i <= n; i++) {

        scanf("%lld %lld", &p[i].x, &p[i].y);

        p[i].id = i;

    }

    sort(p + 1, p + n + 1, [](point a, point b) {

        return a.x < b.x;

    });

    for(int i = 1; i < n; i++) {

        edge.push_back({p[i + 1].x - p[i].x, p[i].id, p[i + 1].id});

    }

    sort(p + 1, p + n + 1, [](point a, point b) {

        return a.y < b.y;

    });

    for(int i = 1; i < n; i++) {

        edge.push_back({p[i + 1].y - p[i].y, p[i].id, p[i + 1].id});

    }

    sort(edge.begin(), edge.end());

    for(auto x : edge) {

        int u = x.u, v = x.v, w = x.w;

        if(union_find(u) != union_find(v)) {

            union_merge(u, v);

            ans += w;

        }

    }

    printf("%lld\n", ans);

}