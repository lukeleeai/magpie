#include "stdc++.h"

#define N 1000021

using namespace std;

int w,h;

int par[N],Rank[N];

char mp[1001][1001];



void init(){

  for(int i=0;i<N;i++) par[i]=i,Rank[i]=0;

}



int find(int x){

  if(par[x]==x)return x;

  return par[x]=find(par[x]);

}



void unite(int x,int y){

  x=find(x),y=find(y);

  if(x==y)return;

  if(Rank[x]<Rank[y])par[x]=y;

  else par[y]=x,Rank[x]+=(Rank[x]==Rank[y]);

}



bool same(int x,int y){return find(x)==find(y);}

int Pos(int x,int y){return w*y+x;}



int dx[]={0,0,-1,1};

int dy[]={1,-1,0,0};

void umeru(){

  for(int i=0;i<h;i++)

    for(int j=0;j<w;j++)

      for(int k=0;k<4;k++){

	int ni=i+dy[k],nj=j+dx[k];

	if(mp[i][j]=='#')continue;

	if(ni<0||nj<0||ni>=h||nj>=w||mp[ni][nj]=='#')continue;

	unite(Pos(j,i),Pos(nj,ni));

      }

}



void umeru2(int x,int y){

  for(int i=0;i<4;i++){

    int ny=y+dy[i],nx=x+dx[i];

    if(ny<0||nx<0||ny>=h||nx>=w||mp[ny][nx]=='#')continue;

    unite(Pos(x,y),Pos(nx,ny));

  }

}



int main(){

  init();

  cin>>w>>h;

  int t;

  for(int i=0;i<h;i++)

    for(int j=0;j<w;j++){

      cin>>mp[i][j];

      if(mp[i][j]=='t')t=Pos(j,i);

    }

  umeru();

 

  int n,ans=-1;

  if(same(0,t)) ans=0;

  cin>>n;

  for(int i=1,a,b;i<=n;i++){

    cin>>a>>b;

    umeru2(a,b);

    mp[b][a]='.';

    if(same(0,t)&&ans==-1)ans=i;

  }

  cout <<ans<<endl;

  return 0;

}