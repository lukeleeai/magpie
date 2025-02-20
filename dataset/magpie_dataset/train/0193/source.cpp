#include"stdc++.h"

using namespace std;

struct edge {

  int to, cost;

};

struct edge2 {

  int u, v, cost;

  bool operator<(const edge2& e) const {

    return(cost < e.cost);

  }

};

typedef pair< int, int > Pi;

const int INF = 1 << 30;



struct UnionFind {

  vector< int > data;

  UnionFind(int sz) {

    data.assign(sz, -1);

  }

  inline void Unite(int a, int b) {

    if((a = Root(a)) == (b = Root(b))) return;

    if(data[a] < data[b]) swap(a, b);

    data[b] += data[a];

    data[a] = b;

  }

  inline int Root(int x) {

    return(data[x] < 0 ? x : data[x] = Root(data[x]));

  }

};

struct SegmentTree {

  vector< int > data;

  int sz;

  SegmentTree(int n)

  {

    sz = 1;

    while(sz < n) sz <<= 1;

    data.assign(2 * sz + 1, INF);

  }

  inline void Set(int k, int x)

  {

    data[k + sz - 1] = x;

  }

  inline void Build() 

  {

    for(int i = sz - 2; i >= 0; i--) {

      data[i] = min(data[2 * i + 1], data[2 * i + 2]);

    }

  }

  inline int Query(int a, int b, int k, int l, int r)

  {

    if(a >= r || b <= l) return(INF);

    if(a <= l && r <= b) return(data[k]);

    return(min(Query(a, b, 2 * k + 1, l, (l + r) >> 1), Query(a, b, 2 * k + 2, (l + r) >> 1, r)));

  }

  inline int Query(int a, int b)

  {

    return(Query(a, b, 0, 0, sz));

  }

};



struct Centroid {

  int parIdx, parDepth, Deep;

  vector< int > Idxes;

};



int N, M, K, Q;

vector< edge > graph[100000], MST[100000];

int F[100000];

int min_cost[100000];

vector< edge2 > edges;



int subtree[100000], ptr;

Centroid Centroids[100000];

int nowtreeidx[100000], nowtreedepth[100000];

vector< SegmentTree > RMQs;



inline int sizedfs(int idx, int prev)

{

  subtree[idx] = 1;

  for(int i = 0; i < MST[idx].size(); i++) {

    const edge& e = MST[idx][i];

    if(e.to == prev) continue;

    subtree[idx] += sizedfs(e.to, idx);

  }

  return(subtree[idx]);

}

inline void makedfs(int idx, int prev, int paridx, int pardepth, int deep)

{

  Centroids[paridx].Idxes.push_back(idx);

  nowtreeidx[idx] = paridx;

  nowtreedepth[idx] = pardepth;

  pair< int, int > ret = make_pair(0, 0);

  for(int i = 0; i < MST[idx].size(); i++) {

    const edge& e = MST[idx][i];

    if(e.to == prev) continue;

    ret = max(ret, make_pair(subtree[e.to], i));

  }

  for(int i = 0; i < MST[idx].size(); i++) {

    const edge& e = MST[idx][i];

    if(e.to == prev) continue;

    if(ret.second == i) {

      makedfs(e.to, idx, paridx, pardepth + 1, deep);

    } else {

      Centroids[ptr++] = (Centroid){paridx, pardepth, deep + 1};

      makedfs(e.to, idx, ptr - 1, 0, deep + 1);

    }

  }

}

void CDP()

{

  sizedfs(0, -1);

  Centroids[ptr++] = (Centroid){-1, 0, 0};

  makedfs(0, -1, 0, 0, 0);



  for(int i = 0; i < ptr; i++) {

    RMQs.push_back(SegmentTree(Centroids[i].Idxes.size()));

    for(vector< int >::iterator it = Centroids[i].Idxes.begin(); it != Centroids[i].Idxes.end(); it++) {

      RMQs[i].Set(it - Centroids[i].Idxes.begin(), min_cost[*it]);

    }

    RMQs[i].Build();

  }

}

int getCost(int a, int b)

{

  int nowTreeIdxA = nowtreeidx[a], nowTreeDepthA = nowtreedepth[a];

  int nowTreeIdxB = nowtreeidx[b], nowTreeDepthB = nowtreedepth[b];

  int ret = INF;

  while(nowTreeIdxA != nowTreeIdxB) {

    if(Centroids[nowTreeIdxA].Deep > Centroids[nowTreeIdxB].Deep) {

      ret = min(ret, RMQs[nowTreeIdxA].Query(0, nowTreeDepthA + 1));

      nowTreeDepthA = Centroids[nowTreeIdxA].parDepth;

      nowTreeIdxA   = Centroids[nowTreeIdxA].parIdx;

    } else {

      ret = min(ret, RMQs[nowTreeIdxB].Query(0, nowTreeDepthB + 1));

      nowTreeDepthB = Centroids[nowTreeIdxB].parDepth;

      nowTreeIdxB   = Centroids[nowTreeIdxB].parIdx;

    }

  }

  if(nowTreeDepthA > nowTreeDepthB) swap(nowTreeDepthA, nowTreeDepthB);

  return(min(ret, RMQs[nowTreeIdxA].Query(nowTreeDepthA, nowTreeDepthB + 1)));

}



void MakeTree()

{

  UnionFind unionfind(N);

  for(int i = 0; i < edges.size(); i++) {

    edge2& e = edges[i];

    e.cost = min(min_cost[e.u], min_cost[e.v]);

  }

  sort(edges.rbegin(), edges.rend());

  

  for(int i = 0; i < edges.size(); i++) {

    const edge2& e = edges[i];

    if(unionfind.Root(e.u) == unionfind.Root(e.v)) continue;

    unionfind.Unite(e.u, e.v);

    MST[e.u].push_back((edge){e.v, e.cost});

    MST[e.v].push_back((edge){e.u, e.cost});

  }

}



void Dijkstra()

{

  priority_queue< Pi, vector< Pi >, greater< Pi > > Que;

  fill_n(min_cost, N, INF);

  for(int i = 0; i < K; i++) {

    Que.push(make_pair(0, F[i]));

    min_cost[F[i]] = 0;

  }

  while(!Que.empty()) {

    Pi p = Que.top(); Que.pop();

    if(min_cost[p.second] < p.first) continue;

    for(int i = 0; i < graph[p.second].size(); i++) {

      const edge& e = graph[p.second][i];

      if(min_cost[e.to] <= e.cost + p.first) continue;

      min_cost[e.to] = e.cost + p.first;

      Que.push(make_pair(min_cost[e.to], e.to));

    }

  }

}



int main()

{

  scanf("%d %d %d %d", &N, &M, &K, &Q);

  for(int i = 0; i < M; i++) {

    int a, b, l;

    scanf("%d %d %d", &a, &b, &l);

    --a, --b;

    graph[a].push_back((edge){b, l});

    graph[b].push_back((edge){a, l});

    edges.push_back((edge2){a, b, l});

  }

  for(int i = 0; i < K; i++) {

    scanf("%d", &F[i]);

    --F[i];

  }

  Dijkstra();

  MakeTree();

  CDP();

  while(Q--) {

    int a, b;

    scanf("%d %d", &a, &b);

    --a, --b;

    printf("%d\n", getCost(a, b));

  }

}