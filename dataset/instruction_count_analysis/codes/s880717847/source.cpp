#include<algorithm>

#include<iostream>

#include<cstring>

#include<cstdio>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 10;

 

int n, m, ecnt, h[maxn], col[maxn];

ll cnt[5];

struct enode{

  int v, n, w;

  enode() {}

  enode(int _v, int _n, int _w):v(_v), n(_n), w(_w) {}

}e[maxn << 1];

 

inline void addedge(int u, int v, int w) {

  ecnt ++; e[ecnt] = enode(v,h[u],w); h[u] = ecnt;

}

 

int flag = 0;

void dfs(int u) {

  cnt[col[u]] ++;

  for(int i = h[u];~ i;i = e[i].n) {

    if(e[i].w == 1) cnt[3] ++;

    int v = e[i].v, tmp = (col[u] + e[i].w) % 3;

    if(col[v] == -1) {

      col[v] = tmp;

      dfs(v);

    }

    else if(col[v] != tmp) flag = 1;

  }

}

 

int main() {

  scanf("%d%d", &n, &m); ecnt = 0;

  memset(h,-1,sizeof(h));

  for(int i = 1;i <= m;i ++) {

    int u, v;

    scanf("%d%d", &u, &v);

    addedge(u,v,1);

    addedge(v,u,2);

  }

  ll ans = 0;

  memset(col,-1,sizeof(col));

  for(int i = 1;i <= n;i ++) {

    if(~ col[i]) continue;

    cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;

    col[i] = 0;

    flag = 0;

    dfs(i);

    if(flag) {

      ll tmp = cnt[0] + cnt[1] + cnt[2];

      ans = ans + 1LL * tmp * tmp;

      continue;

    }

    if(cnt[0] && cnt[1] && cnt[2]) {

      ans = ans + cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];

      continue;

    }

    // printf("--------%lld\n", cnt[3]);

    ans = ans + cnt[3];

  }

  printf("%lld\n", ans);

  return 0;

}
