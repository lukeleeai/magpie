#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

struct E {

  int v;

  bool vis;

  E *next, *rev;

};



const int N = 100010;



int n, m;

bool vis[N], par[N];

E* g[N];



E* adde(int u, int v) {

  static E pool[N * 2], *p = pool;

  ++p;

  p->v = v;

  p->next = g[u];

  g[u] = p;

  return p;

}



void dfs(int u) {

  vis[u] = true;

  for (E* p = g[u]; p; p = p->next)

    if (!p->vis) {

      p->vis = p->rev->vis = true;

      if (!vis[p->v]) {

        dfs(p->v);

        if (par[p->v]) {

          printf("%d %d\n", p->v, u);

        } else {

          printf("%d %d\n", u, p->v);

          par[u] ^= 1;

        }

      } else {

        printf("%d %d\n", u, p->v);

        par[u] ^= 1;

      }

    }

}



int main() {

  scanf("%d%d", &n, &m);

  if (m % 2) {

    puts("-1");

    return 0;

  }

  while (m--) {

    int u, v;

    scanf("%d%d", &u, &v);

    E *p = adde(u, v), *q = adde(v, u);

    p->rev = q;

    q->rev = p;

  }

  dfs(1);

  return 0;

}