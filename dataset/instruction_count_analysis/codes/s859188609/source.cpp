#include <iostream>



using namespace std;



const int kMaxN = 1001;

const int kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};



int n, m, x, y, dx, dy, t = 1, h = 1;

int s[kMaxN][kMaxN];



struct Queue {

  int x, y;

} q[kMaxN * kMaxN];



void Check(int nx, int ny, int v) {

  if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] != -1) {

    return ;

  }

  s[nx][ny] = v;

  q[t++] = {nx, ny};

}



int main() {

  cin >> n >> m >> x >> y >> dx >> dy;

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= m; j++) {

      char c;

      cin >> c;

      s[i][j] = c == '#' ? -2 : -1;

    }

  }

  Check(x, y, 0);

  for (int t_; h < t; ) {

    for (int i = h; i < t; i++) {

      for (int d = 0; d < 4; d++) {

        Check(q[i].x + kD[d][0], q[i].y + kD[d][1], s[q[h].x][q[h].y]);

      }

    }

    for (t_ = t; h < t_; h++) {

      for (int d1 = -2; d1 <= 2; d1++) {

        for (int d2 = -2; d2 <= 2; d2++) {

          Check(q[h].x + d1, q[h].y + d2, s[q[h].x][q[h].y] + 1);

        }

      }

    }

  }

  cout << s[dx][dy];

  return 0;

}