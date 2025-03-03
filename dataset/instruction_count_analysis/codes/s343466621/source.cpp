#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <climits>

#include <cfloat>

#include <map>

#include <utility>

#include <set>

#include <iostream>

#include <memory>

#include <string>

#include <vector>

#include <algorithm>

#include <functional>

#include <sstream>

#include <complex>

#include <stack>

#include <queue>

#include <cstring>

#include <sstream>

#include <cassert>

using namespace std;

static const double EPS = 1e-10;

typedef long long ll;

typedef pair<int,int> PI;

#define rep(i,n) for(int i=0;i<(int)n;++i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

#define mp(a,b) make_pair(a,b)

#define pb(a) push_back(a)

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};



typedef struct{

  short x,y;

  int cost;

  short ch;

}mouse;





mouse t;

short cx,cy,nx,ny,ch,nch,h,w,n;

int cost;



main(){

  scanf("%d%d%d",&h,&w,&n);

  short maxch[h][w];

  char ku[h][w];

  

  rep(i,h)scanf("%s",ku[i]);





  rep(i,h)rep(j,w){

    if(ku[i][j]=='S')cx=i,cy=j;

    maxch[i][j]=-1;

  }



  queue<mouse> Q;



  Q.push((mouse){cx,cy,0,0});

  maxch[cx][cy]=0;



  while(!Q.empty()){

    //cout<<Q.size()<<endl;

    t=Q.front();Q.pop();

    cx=t.x,cy=t.y,cost=t.cost;

    ch=t.ch;



    rep(i,4){

      nx=cx+dx[i],ny=cy+dy[i];

      if(nx<0 || nx>=h || ny<0 || ny>=w)continue;

      if(ku[nx][ny]=='X')continue;

      nch=ch;

      if(ku[nx][ny]<='9' && ku[nx][ny]>='1' && ku[nx][ny]-'0'==t.ch+1){

        nch=ch+1;

      }



      if(maxch[nx][ny]>=nch)continue;

      if(nch==n){

        printf("%d\n",cost+1);

        return 0;

      }

      maxch[nx][ny]=nch;

      Q.push((mouse){nx,ny,cost+1,nch});

    }

  }

}