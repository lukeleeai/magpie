#include<iostream>

#include<iomanip>

#include<vector>

#include<map>

#include<algorithm>

#include<string>

#include<cstring>

#include<queue>

#include<cctype>

using namespace std;

#define fr first

#define sc second

typedef pair<int,int> Pt;

typedef pair<Pt ,int> P;

Pt ST,GL;

int h,w,c,used[20][20][1 << 10],d[]={0,1,0,-1};

char mas[20][20];

int bfs();

int main(){

  while(cin >> w >> h && w){

    c = 0;

    for(int i=0;i<h;i++){

      for(int j=0;j<w;j++){

        cin >> mas[i][j];

        if(mas[i][j] == 'o') ST = Pt(i,j);

        else if(mas[i][j] == '*') mas[i][j] = c++;

      }

    }

    cout << bfs() << endl;

  }

}

int bfs(){

  memset(used,-1,sizeof(used));

  queue<P> que;

  que.push(P(ST,0));

  used[ST.fr][ST.sc][0] = 0;

  while(!que.empty()){

    P p = que.front();

    que.pop();

    if(p.sc==(1<<c)-1) return used[p.fr.fr][p.fr.sc][p.sc];

    int log = used[p.fr.fr][p.fr.sc][p.sc];

    for(int i=0;i<4;i++){

      int nx = d[i] + p.fr.fr,ny = d[3-i] + p.fr.sc;

      int bits = p.sc;

      if(nx>=0&&nx<h&&ny>=0&&ny<w){

        if(mas[nx][ny] == 'x') continue;

        if(mas[nx][ny] >= 0 && mas[nx][ny] < 10){

          bits |= 1<<mas[nx][ny] ;

        }

        if(used[nx][ny][bits] != -1) continue;

        que.push(P(Pt(nx,ny),bits));

        used[nx][ny][bits] = log + 1;

      }

    }

  }

  return -1;

}