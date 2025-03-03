#include"stdc++.h"

#define r(i,n) for(int i=0;i<n;i++)

using namespace std;

#define MAX_V 1000

#define INF 1<<29

using namespace std;

 

 

//  geometry

 

 

typedef double D;

typedef complex<D> P;

const D EPS = 1e-9;

#define X real()

#define Y imag()

 

//  flow

 

 

struct edge{int to,cap,rev;};

vector<edge>G[MAX_V];

int level[MAX_V];

int iter[MAX_V];

void add_edge(int from,int to,int cap){

  G[from].push_back((edge){to,cap,G[to].size()});

  G[to].push_back((edge){from,0,G[from].size()-1});

}

void bfs(int s){

  memset(level,-1,sizeof(level));

  queue<int>q;

  level[s]=0;

  q.push(s);

  while(!q.empty()){

    int v=q.front();q.pop();

    for(int i=0;i<G[v].size();i++){

      edge &e=G[v][i];

      if(e.cap>0&&level[e.to]<0){

    level[e.to]=level[v]+1;

    q.push(e.to);

      }

    }

  }

}

int dfs(int v,int t,int f){

  if(v==t)return f;

  for(int &i=iter[v];i<G[v].size();i++){

    edge &e=G[v][i];

    if(e.cap>0&&level[v]<level[e.to]){

      int d=dfs(e.to,t,min(f,e.cap));

      if(d>0){

    e.cap-=d;

    G[e.to][e.rev].cap+=d;

    return d;

      }

    }

  }

  return 0;

}

int max_flow(int s,int t){

  int flow=0;

  while(1){

    bfs(s);

    if(level[t]<0)return flow;

    memset(iter,0,sizeof(iter));

    int f;

    while((f=dfs(s,t,INF))>0){

      flow+=f;

    }

  }

}

 

void init(){

  r(i,MAX_V)G[i].clear();

  r(i,MAX_V)level[i]=0;

  r(i,MAX_V)iter[i]=0;

}

 

int n,m;

double xx,yy,vv[101];

double di[101][101];

vector<P>v,vp;

 

int main(){

  while(cin>>n>>m,n){

    vp.clear();

    v.clear();

    r(i,n){

      cin>>xx>>yy>>vv[i];

      v.push_back(P(xx,yy));

    }

    r(i,m){

      cin>>xx>>yy;

      P pt=P(xx,yy);

      vp.push_back(pt);

    }

    r(i,n)r(j,m)di[i][j]=abs(vp[j]-v[i])/vv[i];

    D l=0,r=1e9;

    r(i,77){

       

      init();

      D mid=(l+r)/2;

       

      r(j,n)r(k,m)if(di[j][k]<=mid){

        add_edge(j+1,k+201,1);

      }

      r(j,n)add_edge(0,j+1,1);

      r(j,m)add_edge(j+201,500,1);

 

      int ans=max_flow(0,500);

 

      if(ans==m)r=mid;

      else l=mid;

    }

    printf("%.8f\n",l);

  }

}