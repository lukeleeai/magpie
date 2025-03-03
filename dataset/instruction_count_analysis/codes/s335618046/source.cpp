#include<iostream>

#include<cstdio>

#include<queue>

#define INF 100000000

using namespace std;



typedef pair<int,int> P;

typedef pair<P,P> P2;



int main(){

  int w,h;

  char grid[100][50];

  vector<P2> G[2][100][50];

  int d[2][100][50];

  int dy[] = {-2,-1,0,1,2,-1,0,1,0} , dx[] = {1,1,1,1,1,2,2,2,3};



  while(cin >> w >> h , w||h){

    for(int i=0;i<h;i++)

      for(int j=0;j<w;j++)

	scanf(" %c ",&grid[i][j]);



    priority_queue<P2,vector<P2>,greater<P2> > q;



    for(int i=0;i<h;i++)

      for(int j=0;j<w;j++){

	G[0][i][j].clear();

	G[1][i][j].clear();

	if(grid[i][j] == 'S'){

	  d[0][i][j] = d[1][i][j] = 0;

	  q.push(P2(P(0,0),P(i,j)));

	  q.push(P2(P(0,1),P(i,j)));

	}else d[0][i][j] = d[1][i][j] = INF;

      }

    

    for(int i=0;i<h;i++){

      for(int j=0;j<w;j++){

	for(int k=0;k<9;k++){

	  int sy = i+dy[k], sx = j+dx[k];

	  if(sy<0 || sx<0 || h<=sy || w<=sx)continue;

	  if('1'<=grid[sy][sx] && grid[sy][sx]<='9')

	    G[0][i][j].push_back(P2(P(grid[sy][sx]-'0',1),P(sy,sx)));

	  if(grid[sy][sx] == 'S' || grid[sy][sx] == 'T')

	    G[0][i][j].push_back(P2(P(0,1),P(sy,sx)));

	}

	for(int k=0;k<9;k++){

	  int sy = i+dy[k], sx = j-dx[k];

	  if(sy<0 || sx<0 || h<=sy || w<=sx)continue;

	  if('1'<=grid[sy][sx] && grid[sy][sx]<='9')

	    G[1][i][j].push_back(P2(P(grid[sy][sx]-'0',0),P(sy,sx)));

	  if(grid[sy][sx] == 'S' || grid[sy][sx] == 'T')

	    G[1][i][j].push_back(P2(P(0,0),P(sy,sx)));

	}

      }

    }



    while(q.size()){

      P2 p = q.top();q.pop();

      

      int t = p.first.first, f = p.first.second;

      int y = p.second.first, x = p.second.second;



      for(int i=0;i<(int)G[f][y][x].size();i++){

	int tt = G[f][y][x][i].first.first, tf = G[f][y][x][i].first.second;

	int ty = G[f][y][x][i].second.first, tx = G[f][y][x][i].second.second;



	if(d[tf][ty][tx] > t + tt){

	  d[tf][ty][tx] = t+tt;

	  q.push(P2(P(t+tt,tf),P(ty,tx)));

	}

      }

    }

    int ans = INF;

    for(int i=0;i<h;i++)

      for(int j=0;j<w;j++)

	if(grid[i][j] == 'T')

	  ans = min(ans,min(d[0][i][j],d[1][i][j]));

    if(ans ==INF)cout << -1 << endl;

    else cout << ans << endl;

  }

}