#include"stdc++.h"

using namespace std;

#define int long long

#define INF 1LL<<55LL

#define MAX_V 21111

struct edge {

  int to,cap,rev;

  edge(){}

  edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}

};



vector<edge> G[MAX_V];

int level[MAX_V];

int iter[MAX_V];





void add_edge(int from,int to,int cap){

  //cout<<from<<" "<<to<<" "<<cap<<endl;

  G[from].push_back(edge(to,cap,G[to].size()));

  // directed

  G[to].push_back(edge(from,0,G[from].size()-1));

}



void bfs(int s){

  memset(level,-1,sizeof(level));

  queue<int> que;

  level[s]=0;

  que.push(s);

  while(!que.empty()){

    int v=que.front();que.pop();

    for(int i=0;i<(int)G[v].size();i++){

      edge &e = G[v][i];

      if(e.cap>0&&level[e.to]<0){

	level[e.to]=level[v]+1;

	que.push(e.to);

      }

    }

  }

}



int dfs(int v,int t,int f){

  if(v==t) return f;

  for(int &i=iter[v];i<(int)G[v].size();i++){

    edge &e=G[v][i];

    if(e.cap>0&&level[v]<level[e.to]){

      int d = dfs(e.to,t,min(f,e.cap));

      if(d>0){

	e.cap-=d;

	G[e.to][e.rev].cap+=d;

	return d;

      }

    }

  }

  return 0;

}



int max_flow(int s,int t,int lim){

  int flow=0;

  for(;;){

    bfs(s);

    //cout<<level[t]<<" "<<lim<<endl;

    if(level[t]<0||lim==0) return flow;

    memset(iter,0,sizeof(iter));

    int f;

    while((f=dfs(s,t,lim))>0){

      flow+=f;

      lim-=f;

    }

  }

}

int max_flow(int s,int t){

  return max_flow(s,t,INF);

}

typedef pair<int,int> P;

signed main(){

  int h,w;

  cin>>h>>w;

  string a[h];

  for(int i=0;i<h;i++) cin>>a[i];

  int s,t;

  int cnt=0;

  map<P,int> m;

  int sx,sy,tx,ty;

  for(int i=0;i<h;i++){

    for(int j=0;j<w;j++){

      if(a[i][j]=='o') m[P(i,j)]=cnt++;

      if(a[i][j]=='S') s=m[P(i,j)]=cnt++,sy=i,sx=j;

      if(a[i][j]=='T') t=m[P(i,j)]=cnt++,ty=i,tx=j;

    }

  }

  

  //for(auto p:m) cout<<p.first.first<<" "<<p.first.second<<endl;

  

  if(sx==tx||sy==ty){

    cout<<-1<<endl;

    return 0;

  }

  for(int i=0;i<h;i++){

    int j=0;

    while(j<w&&a[i][j]=='.') j++;

    vector<int> v(1,j++);

    while(1){

      while(j<w&&a[i][j]=='.') j++;

      if(j>=w) break;

      v.push_back(j++);

    }

    for(int x=0;x<(int)v.size();x++)

      for(int y=0;y<(int)v.size();y++)

	if(x!=y) add_edge(m[P(i,v[x])]+cnt,m[P(i,v[y])],1LL);

  }

  for(int j=0;j<w;j++){

    int i=0;

    while(i<h&&a[i][j]=='.') i++;

    vector<int> v(1,i++);

    while(1){

      while(i<h&&a[i][j]=='.') i++;

      if(i>=h) break;

      v.push_back(i++);

    }

    for(int x=0;x<(int)v.size();x++)

      for(int y=0;y<(int)v.size();y++)

	if(x!=y) add_edge(m[P(v[x],j)]+cnt,m[P(v[y],j)],1LL);

  }

  for(int i=0;i<cnt;i++){

    if(i==s||i==t) add_edge(i,i+cnt,INF);

    else add_edge(i,i+cnt,1LL);

  }

  //cout<<s<<" "<<t+cnt<<endl;

  cout<<max_flow(s,t+cnt)<<endl;

  return 0;

}
