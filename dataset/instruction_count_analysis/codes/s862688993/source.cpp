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

  int d[2][100][50];

  int dy[] = {-2,-1,0,1,2,-1,0,1,0} , dx[] = {1,1,1,1,1,2,2,2,3};



  while(scanf("%d%d",&w,&h), w||h){

    for(int i=0;i<h;i++)

      for(int j=0;j<w;j++)

	scanf(" %c ",&grid[i][j]);



    priority_queue<P2,vector<P2>,greater<P2> > q;



    for(int i=0;i<h;i++)

      for(int j=0;j<w;j++){

	if(grid[i][j] == 'S'){

	  d[0][i][j] = d[1][i][j] = 0;

	  q.push(P2(P(0,0),P(i,j)));

	  q.push(P2(P(0,1),P(i,j)));

	}else d[0][i][j] = d[1][i][j] = INF;

      }



    while(q.size()){

      P2 p = q.top();q.pop();

      int t = p.first.first, f = p.first.second;

      int y = p.second.first, x = p.second.second;



      if(grid[y][x] == 'T'){

	q.push(p);

	cout << t << endl;

	break;

      }



      for(int k=0;k<9;k++){

	int ty = y+dy[k], tx = !f?(x+dx[k]):(x-dx[k]);

	if(ty<0 || tx<0 || h<=ty || w<=tx)continue;

	if(d[1-f][ty][tx]<INF)continue;



	int tt;

	if('1'<=grid[ty][tx] && grid[ty][tx]<='9')tt = grid[ty][tx]-'0';

	else if(grid[ty][tx] == 'T')tt = 0;

	else tt = -1;



	if(tt>=0){

	  if(d[1-f][ty][tx] > t + tt){

	    d[1-f][ty][tx] = t+tt;

	    q.push(P2(P(t+tt,1-f),P(ty,tx)));

	  }

	}

      }

    }

    if(q.empty())cout << -1 << endl;

  }

}