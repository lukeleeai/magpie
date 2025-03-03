#include"stdc++.h"

#define INF 1e9

#define llINF 1e18

#define MOD 1000000007

#define pb push_back

#define mp make_pair 

#define F first

#define S second

#define ll long long

#define vi vector<ll>

#define vvi vector<vi>

#define BITLE(n) (1LL<<((ll)n))

#define SHIFT_LEFT(n) (1LL<<((ll)n))

#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))

#define ALL(a) (a).begin(),(a).end()



template<typename T>

struct Dijkstra{

  struct edge{

    int to;

    T cost;

  };

  int V;

  std::vector<std::vector<edge>>Edges;

  const T Inf = 1e9;



  Dijkstra(int V):V(V),Edges(V){}



  void add_edge(int from, int to, T cost){

    Edges[from].push_back({to, cost});

  }

  

  std::vector<T> execution(int s){

    std::vector<T> dist(V,Inf);

    std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<>>que;

    dist[s] = 0;

    que.push(std::make_pair(0, s));

    while(!que.empty()){

      int v = que.top().second;

      T cost = que.top().first;

      que.pop();

      if(dist[v] < cost)continue;

      for(auto e:Edges[v]){

	if(dist[e.to] > dist[v] + e.cost){

	  dist[e.to] = dist[v] + e.cost;

	  que.push(std::make_pair(dist[e.to], e.to));

	}

      }

    }

    return dist;

  }

};



int main(){

  std::cin.tie(0);

  std::ios::sync_with_stdio(false);

  ll v,e,r;std::cin>>v>>e>>r;

  Dijkstra<int>dijkstra(v);

  for(int i=0;i<e;i++){

    ll a,b,c;std::cin>>a>>b>>c;

    dijkstra.add_edge(a,b,c);

  }

  for(auto e:dijkstra.execution(r)){

    if(e == INF)std::cout<<"INF"<<std::endl;

    else std::cout<<e<<std::endl;

    // std::cout<<((e == INF)?e:"INF")<<std::endl;

  }

  return 0;

}


