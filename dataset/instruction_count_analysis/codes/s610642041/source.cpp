#include"stdc++.h"



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)   FOR(i,0,n)

const int INF = 1e9 + 7;



using namespace std;



#define MAX_V 100

struct edge{

  int to,cost;

};

struct inp{

  int a,b,c;

};

typedef pair<int,int> P;

int V;

vector<edge> G[MAX_V];

int d[MAX_V];



void dijkstra(int s){

  priority_queue<P,vector<P>,greater<P>> que;

  fill(d,d+V,INF);

  d[s] = 0;

  que.push(P(0,s));



  while(!que.empty()){

    P p = que.top(); que.pop();

    int v = p.second;

    if(d[v] < p.first) continue;

    REP(i,G[v].size()){

      edge e = G[v][i];

      if(d[e.to] > d[v] + e.cost){

        d[e.to] = d[v] + e.cost;

        que.push(P(d[e.to],e.to));

      }

    }

  }

}



int main(){

  int e;

  bool used[1000];



  scanf("%d%d",&V,&e);

  vector<inp> iedge(e);

  REP(i,e){

    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    --a;--b;

    edge e1 = {b,c}, e2 = {a,c};

    G[a].push_back(e1);

    G[b].push_back(e2);

    inp e3 = {a,b,c};

    iedge[i] = e3;

  }

  REP(i,e) used[i] = false;



  REP(i,V){

    dijkstra(i);

    REP(j,e){

      if(used[j]) continue;

      if(d[iedge[j].a] + iedge[j].c == d[iedge[j].b]) used[j] = true;

    }

  }



  int ans=0;

  REP(i,e) if(!used[i]) ++ans;

  printf("%d\n",ans);

  return 0;

}
