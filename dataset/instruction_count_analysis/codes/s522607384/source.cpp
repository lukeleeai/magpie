#include<cstdio>

#include<algorithm>

using namespace std;

const int maxn = 2007;

int n, k, u[maxn], v[maxn], gra, head[maxn];

struct edge {

    int nxt;

    int to;

} e[2000 << 1];

int tp = 0;

void add(int u, int v) {

    e[++gra].to = v;

    e[gra].nxt = head[u];

    head[u] = gra;

    return ;

}

void dfs(int now, int last, int deep) {

    tp++;

    if(!deep)return;

    for(int v, i = head[now]; i; i = e[i].nxt) {

        v = e[i].to;

        if(v != last) dfs(v, now, deep - 1);

    }

}



int main() {

    scanf("%d%d", &n, &k);

    for(int i=1; i<n;i++) {

        scanf("%d%d", &u[i], &v[i]);

        add(u[i], v[i]);

        add(v[i], u[i]);

    }

    int ans = 0;

    if(k % 2 ) {

        for(int i=1; i<n; i++) {

            tp = 0;

            dfs(u[i], v[i], k / 2);

            dfs(v[i], u[i], k / 2);

            ans = max(ans, tp);

        }

    } else {

        for(int i=1; i<n;i++) {

            tp = 0;

            dfs(i, 0, k / 2);

            ans = max(ans, tp);

        }

    }

    printf("%d", n - ans);

    return 0;

}


