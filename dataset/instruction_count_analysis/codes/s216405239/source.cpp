# include "stdc++.h"



using namespace std;



const int N = 101;





int a, b, u[N][N], v[N][N], n = 70, m = 70;

bool flag;



void dfs(int x, int y){

      v[x][y] = 1;

      if(u[x][y + 1] == u[x][y] && !v[x][y + 1] && y + 1 <= m)

            dfs(x, y + 1);

      if(u[x][y - 1] == u[x][y] && !v[x][y - 1] && y - 1 >= 1)

            dfs(x, y - 1);

      if(u[x + 1][y] == u[x][y] && !v[x + 1][y] && x + 1 <= n)

            dfs(x + 1, y);

      if(u[x - 1][y] == u[x][y] && !v[x - 1][y] && x - 1 >= 1)

            dfs(x - 1, y);

}



int main(){

      cin >> a >> b;

      a --, b --;

      int x = 1, y = 1;



      while(a > 0){

            u[x][y] = 1;

            a --;

            y += 2;

            if(y > m){

                  x += 2;

                  y = 1;

            }

      }



      for(int i = n / 2; i <= n; i ++)

            for(int j = 1; j <= m; j ++)

                  u[i][j] = 1;



      x = n, y = m;

      while(b > 0){

            u[x][y] = 0;

            b --;

            y -= 2;

            if(y <= 0){

                  y = m;

                  x -= 2;

            }

      }



      int cnt = 0, cn = 0;



      for(int i = 1; i <= n; i ++){

            for(int j = 1; j <= m; j ++){

                  if(v[i][j] == 0 && u[i][j] == 1){

                        dfs(i, j), cnt ++;

                  }

            }

      }



      for(int i = 1; i <= n; i ++){

            for(int j = 1; j <= m; j ++){

                  if(v[i][j] == 0 && u[i][j] == 0){

                        flag = 1;

                        dfs(i, j), cn ++;

                        flag = 0;

                  }

            }

      }



//      cout << cnt << " " << cn << endl;

      cout << n << " " << m << endl;



      for(int i = 1; i <= n; i ++){

            for(int j = 1; j <= m; j ++)

                  if(u[i][j])

                        cout << '.';

                  else

                        cout << '#';

            cout << endl;

      }

}
