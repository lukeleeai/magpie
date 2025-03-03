#include"stdc++.h"

using namespace std;

using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}

template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}





template<typename T,bool directed>

struct Dinic{

  struct edge {

    int to;

    T cap;

    int rev;

    edge(){}

    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}

  };



  vector< vector<edge> > G;

  vector<int> level,iter;



  Dinic(){}

  Dinic(int n):G(n),level(n),iter(n){}



  int add_edge(int from,int to,T cap){

    G[from].emplace_back(to,cap,G[to].size());

    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);

    return G[to].back().rev;

  }



  void bfs(int s){

    fill(level.begin(),level.end(),-1);

    queue<int> que;

    level[s]=0;

    que.emplace(s);

    while(!que.empty()){

      int v=que.front();que.pop();

      for(int i=0;i<(int)G[v].size();i++){

        edge &e=G[v][i];

        if(e.cap>0&&level[e.to]<0){

          level[e.to]=level[v]+1;

          que.emplace(e.to);

        }

      }

    }

  }



  T dfs(int v,int t,T f){

    if(v==t) return f;

    for(int &i=iter[v];i<(int)G[v].size();i++){

      edge &e=G[v][i];

      if(e.cap>0&&level[v]<level[e.to]){

        T d=dfs(e.to,t,min(f,e.cap));

        if(d==0) continue;

        e.cap-=d;

        G[e.to][e.rev].cap+=d;

        return d;

      }

    }

    return 0;

  }



  T flow(int s,int t,T lim){

    T fl=0;

    while(1){

      bfs(s);

      if(level[t]<0||lim==0) break;

      fill(iter.begin(),iter.end(),0);



      while(1){

        T f=dfs(s,t,lim);

        if(f==0) break;

        fl+=f;

        lim-=f;

      }

    }

    return fl;

  }



  T flow(int s,int t){

    return flow(s,t,numeric_limits<T>::max()/2);

  }



  T cut(int s,int t,int x,int a){

    static_assert(directed, "must be directed");

    auto &e=G[x][a];

    int y=e.to;

    T cr=G[y][e.rev].cap;

    if(cr==0) return e.cap=0;

    e.cap=G[y][e.rev].cap=0;

    T cap=cr-flow(x,y,cr);

    if(x!=s&&cap!=0) flow(x,s,cap);

    if(t!=y&&cap!=0) flow(t,y,cap);

    return cap;

  }



  T link(int s,int t,int x,int a,T f){

    auto &e=G[x][a];

    e.cap+=f;

    return flow(s,t,f);

  }

};



//INSERT ABOVE HERE

signed main(){

  int h,w;

  cin>>h>>w;

  vector<string> st(h);

  for(int i=0;i<h;i++) cin>>st[i];



  auto idx=[&](int i,int j,int k){return h+w+(i*w+j)*2+k;};



  const int INF = 1e5;

  Dinic<int, true> G(h*w*2+h+w);

  int S=-1,T=-1;

  for(int i=0;i<h;i++){

    for(int j=0;j<w;j++){

      if(st[i][j]=='.') continue;

      if(st[i][j]=='S') S=idx(i,j,1);

      if(st[i][j]=='T') T=idx(i,j,0);

      G.add_edge(idx(i,j,0),idx(i,j,1),1);

      G.add_edge(idx(i,j,1),0+i,INF);

      G.add_edge(idx(i,j,1),h+j,INF);

      G.add_edge(0+i,idx(i,j,0),INF);

      G.add_edge(h+j,idx(i,j,0),INF);

    }

  }



  assert(~S);

  assert(~T);

  int ans=G.flow(S,T);

  if(ans>=INF) ans=-1;

  cout<<ans<<endl;

  return 0;

}
