#include "stdc++.h"

using namespace std;



using ll = long long;

using ii = pair<int, int>;

using vi = vector<int>;

#define all(v) begin(v), end(v)

#define fi first

#define se second



const int N = 302 * 2;



vector<ii> dir[2];

int n, d1, d2;

bool inside(int x, int y) {

  return 0 <= x and x < n and 0 <= y and y < n;

}

int col[2][N][N], vis[N][N];

int layer;



void dfs(int x, int y) {

  vis[x][y] = 1;

  for(ii d : dir[layer]) {

    int xx = x + d.fi;

    int yy = y + d.se;

    if(inside(xx, yy) && !vis[xx][yy]) {

      col[layer][xx][yy] = col[layer][x][y] ^ 1;

      dfs(xx, yy);

    }

  }

}



int sq(int x) { return x * x; }

int dist2(ii a, ii b) {

  return sq(a.fi - b.fi) + sq(a.se - b.se);

}



int main(int argc, char const *argv[])

{

#ifdef LOCAL

  freopen("in", "r", stdin);

#endif

  cin >> n >> d1 >> d2;

  n *= 2;

  for(int i = -n+1; i < n; ++i) {

    for(int j = -n+1; j < n; ++j) {

      if(i*i + j*j == d1) {

        dir[0].emplace_back(i, j);

      }

      if(i*i + j*j == d2) {

        dir[1].emplace_back(i, j);

      }

    }

  }



  for(layer = 0; layer < 2; layer++) {

    memset(vis, 0, sizeof vis);

    for(int i = 0; i < n; ++i) {

      for(int j = 0; j < n; ++j) {

        if(!vis[i][j]) {

          dfs(i, j);

        }

      }

    }

  }

  vi cnt(4);

  for(int i = 0; i < n; ++i) {

    for(int j = 0; j < n; ++j) {

      cnt[(col[1][i][j] << 1) | (col[0][i][j])]++;

    }

  }

  ii opt = {-1, 0};

  for(int i = 0; i < 4; ++i) {

    opt = max(opt, {cnt[i], i});

  }

  int c0 = opt.se & 1;

  int c1 = opt.se >> 1 & 1;

  vector<ii> S;

  for(int i = 0; i < n; ++i) {

    for(int j = 0; j < n; ++j) {

      if(col[0][i][j] == c0 && col[1][i][j] == c1) {

        S.emplace_back(i, j);

      }

    }

  }

  while((int)S.size() > n * n / 4) S.pop_back();

  for(ii& p : S) {

    cout << p.fi << ' ' << p.se << '\n';

  }

  return 0;

  for(int i = 0; i < (int)S.size(); ++i) {

    for(int j = i+1; j < (int)S.size(); ++j) {

      int x = dist2(S[i], S[j]);

      assert(x != d1 and x != d2);

      /*if(!(x != d1 and x != d2)) {

        cout << ">#$%" << endl;

        cout << S[i].fi << ' ' << S[i].se << endl;

        cout << S[j].fi << ' ' << S[j].se << endl;

        exit(0);

      }*/

    }

  }

  return 0;

}