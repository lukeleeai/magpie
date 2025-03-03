#include <cstdio>

#include <cstring>



#define N 1001

#define V 2020

#define E 20386

#define F 0x7fffffff



#define MIN(A, B) ((A) < (B) ? (A) : (B))



struct edge {

    int u, v;

    long long w;

    int c, x;

} e[E];



const long long y[2][4] = {{-1, 1, -1, 1}, {-1, -1, 1, 1}};



long long p[2][2][N], d[V];

int h[V], m[2][N], f[V], q[V], l, t, z, n, g;

bool v[V];



inline void adde(int u, int v, long long w, int c) {

    e[z] = edge{u, v, -w, c, h[u]}; h[u] = z++;

    e[z] = edge{v, u, w, 0, h[v]}; h[v] = z++;

}



inline void push(int x) {

    q[t++] = x;

    if (t == V) t = 0;

}



inline int pop() {

    int x = q[l++];

    if (l == V) l = 0;

    return x;

}



bool spfa() {

    memset(d, 0x3f, sizeof d);

    d[0] = 0; push(0); v[0] = true;



    while (l != t) {

        int x = pop();

        v[x] = false;



        for (int i = h[x]; ~i; i = e[i].x) {

            if (e[i].c && d[e[i].v] > d[x] + e[i].w) {

                d[e[i].v] = d[x] + e[i].w; f[e[i].v] = i;

                if (!v[e[i].v]) { push(e[i].v); v[e[i].v] = true; }

            }

        }

    }



    return d[g] != 0x3f3f3f3f3f3f3f3fLL;

}



long long solve() {

    long long c = 0;



    while (spfa()) {

        int w = F;

        for (int u = g; u; u = e[f[u]].u) w = MIN(w, e[f[u]].c);



        for (int u = g; u; u = e[f[u]].u) {

            c += e[f[u]].w * w; e[f[u]].c -= w; e[f[u] ^ 1].c += w;

        }

    }



    return -c;

}



int main() {

    memset(h, -1, sizeof h);

    scanf("%d", &n); g = (n << 1) + 9;

    for (int i = 1; i <= 4; i++) adde((n << 1) + i, (n << 1) + i + 4, 0, F);



    for (int s = 0; s <= 1; s++)

        for (int i = 1; i <= n; i++)

            scanf("%lld%lld%d", &p[s][0][i], &p[s][1][i], &m[s][i]);



    for (int i = 1; i <= n; i++) {

        adde(0, i, 0, m[0][i]); adde(n + i, g, 0, m[1][i]);



        for (int j = 0; j < 4; j++) {

            adde(i, (n << 1) + j + 1, p[0][0][i] * y[0][j] + p[0][1][i] * y[1][j], F);

            adde((n << 1) + 8 - j, n + i, p[1][0][i] * y[0][j] + p[1][1][i] * y[1][j], F);

        }

    }



    printf("%lld\n", solve()); return 0;

}
