#include"stdc++.h"

#define mx 100005

using namespace std;

typedef pair<int, int> P;

long long ans;



int h, w, wh[405][405], dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};

char s[405];



int main(){

  scanf("%d %d\n", &h, &w);

  for(int i = 0; i < h; i++){

    scanf("%s", s);

    for(int j = 0; j < w; j++) wh[i][j] = s[j] == '.';

  }

  for(int i = 0; i < h; i++){

    for(int j = 0; j < w; j++){

      if(wh[i][j] == 2) continue;

      stack<P> st;

      long long nm[2] = {};

      st.push(P(i, j));

      while(!st.empty()){

        P it = st.top(); st.pop();

        for(int k = 0; k < 4; k++){

          int x = it.first + dx[k], y = it.second + dy[k];

          if(0 <= x && x < h && 0 <= y && y < w && wh[x][y] + wh[it.first][it.second] == 1){

            st.push(P(x,y));

          }

        }

        nm[wh[it.first][it.second]]++;

        wh[it.first][it.second] = 2;

      }

      ans += nm[0]*nm[1];

    }

  }

  printf("%lld\n", ans);

}