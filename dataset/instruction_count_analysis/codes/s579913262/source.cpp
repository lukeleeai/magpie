#include"stdc++.h"

#define int long long

#define rint register int

using namespace std;



template<typename tp> inline void read(tp &x) {

  x = 0; char c = getchar(); int f = 0;

  for (; c < '0' || c > '9'; f |= c == '-', c = getchar());

  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());

  if (f) x = -x;

}

int n;

vector<int> g[233333];



inline int dfs(int u, int fat) {

  int now = 0;

  for (int v : g[u])

    if (v != fat)

      now ^= 1 + dfs(v, u);

  return now;

}



main(void) {

  read(n);

  for (int i = 2; i <= n; i ++) {

    int x, y; read(x); read(y);

    g[x].push_back(y); g[y].push_back(x);

  }

  puts( dfs(1, 0) ? "Alice" : "Bob" );

}
