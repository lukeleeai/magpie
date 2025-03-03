#include "stdc++.h"

#define INF (1e9)

#define MAX_V 2010

#define MAX_N 1010

using namespace std;

int V;

vector<int> G[MAX_V];

int match[MAX_V];

bool used[MAX_V];



void add_edge(int u,int v){

  G[u].push_back(v);

  G[v].push_back(u);

}



bool dfs(int v){

  used[v] = true;

  for(int i=0; i<G[v].size(); i++){

    int u = G[v][i], w = match[u];

    if(w<0 || !used[w] && dfs(w)){

      match[v] = u;

      match[u] = v;

      return true;

    }

  }

  return false;

}



int bipartite_matching(){

  int res=0;

  memset(match, -1, sizeof(match));

  for(int v=0; v<V; v++){

    if(match[v] < 0){

      memset(used,0,sizeof(used));

      if(dfs(v)) res++;

    }

  }

  return res;

}



int main(){

  int n,m,l;

  while(1){

    cin>>n>>m>>l;

    if(!n&&!m&&!l)break;

    vector<vector<int> >g(n,vector<int>(n,INF));

    for(int i=0;i<n;i++) g[i][i]=0;

    for(int i=0;i<l+l+2;i++)G[i].clear();

    

    for(int i=0,a,b,c;i<m;i++)cin>>a>>b>>c,g[a][b]=g[b][a]=c;

    

    for(int k=0;k<n;k++)

      for(int i=0;i<n;i++)

	for(int j=0;j<n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

    

    vector<int>idx(l),tl(l);

    for(int i=0,a,b;i<l;i++)cin>>a>>b,tl[i]=b,idx[i]=a;

    

    for(int i=0;i<l;i++)

      for(int j=0;j<l;j++)

	if(i!=j&&tl[i]+g[idx[i]][idx[j]]<=tl[j])add_edge(i,l+j);

    

    V=l+l;

    cout <<l-bipartite_matching()<<endl;

  }

  return 0;

}