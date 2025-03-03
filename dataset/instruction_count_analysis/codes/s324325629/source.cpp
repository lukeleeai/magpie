#include<iostream>

#include<algorithm>

#include<queue>

#include<cstring>

using namespace std;

#define INF 1 << 29

typedef pair< int , int > Pi;

int h, w;

char mas[50][50];

int graph[11][11];

int min_cost[50][50];

Pi gomi[11];

int gomi_size, uoo;

int memo[12][1 << 11];

const int dy[] = { 1, 0, 0, -1}, dx[] = { 0, 1, -1, 0};



int rec(int idx, int used)

{

  if(used == (1 << gomi_size) - 1) return 0;

  if(memo[idx][used]) return memo[idx][used];



  int ret = INF;

  for(int i = 0; i < gomi_size; i++){

    if(!(used & (1 << i)) && graph[idx][i] != -1){

      ret = min(ret, rec(i, used | (1 << i)) + graph[idx][i]);

    }

  }



  return memo[idx][used] = ret;

}





int bfs(Pi a, Pi b)

{

  memset( min_cost, -1, sizeof(min_cost));

  queue< Pi > que;

  que.push(a);

  min_cost[a.first][a.second] = 0;

  while(!que.empty()){

    Pi p = que.front(); que.pop();

    if(p == b) return min_cost[p.first][p.second];

    for(int i = 0; i < 4; i++){

      int ny = p.first + dy[i], nx = p.second + dx[i];

      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

      if(mas[ny][nx] != 'x' && min_cost[ny][nx] == -1){

        min_cost[ny][nx] = min_cost[p.first][p.second] + 1;

        que.push( Pi( ny, nx));

      }

    }

  }

  return -1;

}



int main()

{

  while(cin >> w >> h, w){

gomi_size = 0;

  for(int i = 0; i < h; i++){

    for(int j = 0; j < w; j++){

      cin >> mas[i][j];

      if(mas[i][j] == '*' || mas[i][j] == 'o'){

        gomi[gomi_size++] = Pi( i, j);

        if(mas[i][j] == 'o') uoo = gomi_size - 1;

      }

    }

  }

  for(int i = 0; i < gomi_size; i++){

    for(int j = i + 1; j < gomi_size; j++){

      graph[i][j] = graph[j][i] = bfs(gomi[i], gomi[j]);

    }

  }



  //巡回セールスマン！！

  //さのぴーさんよろしく

memset( memo, 0, sizeof(memo));

  int ret = rec( uoo, 1 << uoo);



  if(ret != INF) cout << ret << endl;

  else cout << -1 << endl;

}

  return(0);

}