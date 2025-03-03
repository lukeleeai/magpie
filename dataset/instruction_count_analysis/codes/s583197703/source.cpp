#include "stdc++.h"

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)

#define SIZE 200005

#define INF 1000000005LL

#define MOD 1000000007



using namespace std;

typedef long long int ll;

typedef pair <int,int> P;

int h,w;

string s[55];

int d[55][55];

vector<P> to[55][55];

int c;



void Push_back(int x,int y,int i,int j){

  if(i>=0 && j>=0 && i<h && j<w){

    if(s[x][y] == '.' && s[i][j] == '.'){

      to[x][y].push_back(P(i,j));

    }

  }

}



void bfs(){

  queue<P> q;

  q.push(P(0,0));

  d[0][0] = 1;

  while(!q.empty()){

    P t = q.front();q.pop();

    for(P nt : to[t.first][t.second]){

      int x=nt.first,y=nt.second;

      if(d[x][y]==-1 && s[x][y]=='.'){

        d[x][y] = d[t.first][t.second]+1;

        q.push(P(x,y));

      }

    }

  }

}



int main(){

  rep(i,0,55) rep(j,0,55) d[i][j]=-1;

  cin >> h >> w;

  rep(i,0,h) {

    cin >> s[i];

  }

  rep(i,0,h) rep(j,0,w){

    if(s[i][j] == '.')c++;

    Push_back(i,j,i-1,j);

    Push_back(i,j,i+1,j);

    Push_back(i,j,i,j+1);

    Push_back(i,j,i,j-1);

  }



  bfs();

  if(d[h-1][w-1]==-1)cout << -1 << endl;

  else cout << c-d[h-1][w-1] << endl;



  return 0;

}
