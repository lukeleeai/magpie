#include <iostream>

#include <vector>

#include <queue>



using namespace std;



const int kMaxN = 1001;



struct E {

  int x, y;

};



int n, m, x, y, h, w;

vector<vector<int>> a(kMaxN, vector<int>(kMaxN, -1));



queue<E> q, e;



int ne[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};



void Change(int i, int j, int v) {

  a[i][j] = v;

  E note = {i, j};

  q.push(note);

  e.push(note);

}



int main() {

  cin >> n >> m >> x >> y >> h >> w;

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= m; j++) {

      char c;

      cin >> c;

      if (c == '#') {

        a[i][j] = -2;

      }

    }

  }

  Change(x, y, 0);

  while (!q.empty()) {

    while (!q.empty()) {

      x = q.front().x, y = q.front().y;

      e.push(q.front());

      q.pop();

      for (int i = 0; i < 4; i++) {

        int nx = x + ne[i][0], ny = y + ne[i][1];

        if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == -1) {

          Change(nx, ny, a[x][y]);

        }

      }

    }

    while (!e.empty()) {

      x = e.front().x, y = e.front().y;

      e.pop();

      for (int i = -2; i <= 2; i++) {

        for (int j = -2; j <= 2; j++) {

          int nx = x + i, ny = y + j;

          if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == -1) {

            a[nx][ny] = a[x][y] + 1;

            E note = {nx, ny};

            q.push(note);

          }

        }

      }

    }

  }

  cout << a[h][w];

  return 0;

}