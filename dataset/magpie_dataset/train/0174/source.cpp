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

  int x,y;

  int cost;

  int ch;

}mouse;



int maxch[1000][1000];



main(){

  int h,w,n;

  cin>>h>>w>>n;

  char ku[h][w];

  rep(i,h)cin>>ku[i];



  int sx,sy;

  rep(i,h)rep(j,w)if(ku[i][j]=='S')sx=i,sy=j;



  queue<mouse> Q;

  memset(maxch,-1,sizeof(maxch));



  Q.push((mouse){sx,sy,0,0});

  maxch[sx][sy]=0;





  int ans=0;

  while(!Q.empty()){

    //    cout<<Q.size()<<endl;

    mouse t=Q.front();Q.pop();

    int cx=t.x,cy=t.y,cost=t.cost;

    int ch=t.ch;

    if(ch==n){

      ans=cost;

      break;

    }







    rep(i,4){

      int nx=cx+dx[i],ny=cy+dy[i];

      if(nx<0 || nx>=h || ny<0 || ny>=w)continue;

	 if(ku[nx][ny]=='X')continue;

	 int nch=ch;

	 if(ku[nx][ny]<='9' && ku[nx][ny]>='1'){

	   int num=ku[nx][ny]-'0';

	   if(num==t.ch+1){

	     nch=ch+1;

	   }

	 }

	 if(maxch[nx][ny]>=nch)continue;

	 maxch[nx][ny]=nch;



	 Q.push((mouse){nx,ny,cost+1,nch});

    }

  }

  cout<<ans<<endl;

}