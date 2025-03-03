#include "stdc++.h"

#define INF (1e9)

#define MAX_V 2010

#define MAX_N 1010

using namespace std;

struct edge{int to, cap, rev;};

vector<edge> G[MAX_V]; //??°???????????£??\?????????

bool used[MAX_V];      //DFS??§?????§??????????????????????????°

//from??????to??????????????????cap???????????°?????????????????????

void add_edge(int from,int to,int cap){

  G[from].push_back((edge){to,cap,G[to].size()});

  G[to].push_back((edge){from,0,G[from].size()-1});  

}



//?¢?????????????DFS??§??¢???

int dfs(int v,int t,int f){

  if(v == t)return f;

  used[v]=true;

  for(int i=0; i<G[v].size() ;i++){

    edge &e = G[v][i];

    if(!used[e.to] && e.cap > 0){

      int d = dfs(e.to ,t , min(f,e.cap));

      if(d > 0){

	e.cap -= d;

	G[e.to][e.rev].cap += d;

	return d;

      }

    }

  }

  return 0;

}



//s??????t???????????§???????±???????

int max_flow(int s,int t){

  int flow = 0;

  for(;;){

    memset(used,0,sizeof(used));

    int f = dfs(s, t, INF);

    if(f == 0)return flow;

    flow += f;

  }

}



bool can[MAX_N][MAX_N]; //can[i][j]:=???????????\??????i?????????j??????????????????

int Biparite_Matching(int N,int K){

  int s = N+K, t = s+1;

  for(int i=0; i<N; i++) add_edge(s,i,1);

  for(int i=0; i<K; i++) add_edge(N+i,t,1);

  

  for(int i=0;i<N;i++)

    for(int j=0;j<K;j++)

      if(can[i][j]) add_edge(i, N+j , 1);

  return max_flow(s,t);

}







int main(){

  int n,m,l;

  while(1){

    cin>>n>>m>>l;

    if(!n&&!m&&!l)break;

    vector<vector<int> >g(n,vector<int>(n,INF));

    for(int i=0;i<n;i++) g[i][i]=0;

    for(int i=0;i<MAX_V;i++)G[i].clear();

    

    for(int i=0,a,b,c;i<m;i++)cin>>a>>b>>c,g[a][b]=g[b][a]=c;

    

    for(int k=0;k<n;k++)

      for(int i=0;i<n;i++)

	for(int j=0;j<n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

    

    vector<int>idx(l),tl(l);

    for(int i=0,a,b;i<l;i++)cin>>a>>b,tl[i]=b,idx[i]=a;

    

    

  memset(can,0,sizeof(can));

  for(int i=0;i<l;i++)

    for(int j=0;j<l;j++)

      if(i!=j&&tl[i]+g[idx[i]][idx[j]]<=tl[j])can[i][j]=1;

  cout <<l-Biparite_Matching(l,l)<<endl;

  }

  return 0;

}