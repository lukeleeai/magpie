// by newbiechd

#include <algorithm>

#include <cassert>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <vector>



// Delete the debugging information!

#define debug(x) std::cerr << #x << " = " << (x) << std::endl



const int N_MAX = 100003, M_MAX = 200003;

int h[N_MAX], cntEdge;

struct Edge {

  int tar, nxt;

  Edge() {}

  Edge(int tar, int nxt) : tar(tar), nxt(nxt) {}

}ed[M_MAX];



int col[N_MAX], cntNode, tub[3];

int dfs(int x) {

  ++cntNode, ++tub[col[x]];

  bool ext[2] = {0, 0};

  int state = 0;

  for (int i = h[x]; i; i = ed[i].nxt) {

    ++cntEdge, ext[i & 1] = 1;

    int y = ed[i].tar, temp = col[x] - 1 - (i & 1);

    temp += (temp >> 31) & 3;

    if (col[y] > 2)

      col[y] = temp, state |= dfs(y);

    else

      if (col[y] != temp)

        state |= 2;

  }

  return state | (ext[0] & ext[1]);

}



int main() {

  int n, m;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; ++i) {

    int x, y;

    scanf("%d%d", &x, &y);

    ed[++cntEdge] = Edge(y, h[x]), h[x] = cntEdge;

    ed[++cntEdge] = Edge(x, h[y]), h[y] = cntEdge;

  }

  

  long long ans = 0;

  memset(col + 1, 0x3f, sizeof(int) * n);

  for (int i = n; i; --i)

    if (col[i] > 2) {

      cntNode = cntEdge = tub[0] = tub[1] = tub[2] = 0, col[i] = 2;

      int state = dfs(i);

      if (state & 2)

        ans += 1ll * cntNode * cntNode;

      else

        if (state & 1)

          ans += 1ll * tub[0] * tub[1] + 1ll * tub[1] * tub[2] +

            1ll * tub[2] * tub[0];

        else

          ans += cntEdge >> 1;

    }

  printf("%lld\n", ans);

  return 0;

}
