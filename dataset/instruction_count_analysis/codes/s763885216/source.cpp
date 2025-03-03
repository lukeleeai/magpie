#include"stdc++.h"

#define MAX_V 100000

#define INF 1<<29

using namespace std;

struct edge{int to,cap,rev;};

vector<edge>G[MAX_V];

int level[MAX_V];

int iter[MAX_V];

void add_edge(int from,int to,int cap){

  G[from].push_back((edge){to,cap,(int)G[to].size()});

  G[to].push_back((edge){from,0,(int)G[from].size()-1});

}

void bfs(int s){

  memset(level,-1,sizeof(level));

  queue<int>q;

  level[s]=0;

  q.push(s);

  while(!q.empty()){

    int v=q.front();q.pop();

    for(int i=0;i<(int)(G[v].size());i++){

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

  for(int &i=iter[v];i<(int)(G[v].size());i++){

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

int main(){

  int x,y,n,s,t;

  vector<pair<int,int>> A,B;

  cin>>n;

  x=n;

  y=n;

  for(int i=0;i<n;i++){

  	cin>>s>>t;

  	A.push_back({s,t});

  }

  for(int i=0;i<n;i++){

  	cin>>s>>t;

  	B.push_back({s,t});

  }

  for(int i=0;i<n;i++){

  	for(int j=0;j<n;j++){

  		if(A[i].first<B[j].first&&A[i].second<B[j].second){

  			add_edge(i+1,n+j+1,1);

  		}

  	}

  }

  for(int i=0;i<y;i++){

  	add_edge(x+i+1,x+y+1,1);

  }

  for(int i=0;i<x;i++){

  	add_edge(0,i+1,1);

  }

  cout<<max_flow(0,x+y+1)<<endl;

}
