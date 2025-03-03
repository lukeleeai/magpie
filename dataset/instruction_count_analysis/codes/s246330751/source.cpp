#include"stdc++.h"

using namespace std;

#define int long long

vector< vector< int > > graph;



struct SegmentTree

{

  vector< int > data, add;

  int sz;

  SegmentTree(int n)

  {

    sz = 1;

    while(sz < n) sz <<= 1;

    data.assign(2 * sz - 1, 0);

    add.assign(2 * sz - 1, 0);

  }

  inline void Push(int k)

  {

    add[2 * k + 1] += add[k] / 2;

    add[2 * k + 2] += add[k] / 2;

    add[k] = 0;

    Merge(k);

  }

  inline void Merge(int k)

  {

    data[k] = data[2 * k + 1] + data[2 * k + 2] + add[2 * k + 1] + add[2 * k + 2];

  }

  inline void RangeAdd(int a, int b, int x, int k, int l, int r)

  {

    if(a >= r || b <= l) return;

    if(a <= l && r <= b) {

      add[k] += x * (r - l);

      return;

    }

    Push(k);

    RangeAdd(a, b, x, 2 * k + 1, l, (l + r) >> 1);

    RangeAdd(a, b, x, 2 * k + 2, (l + r) >> 1, r);

    Merge(k);

  }

  inline void RangeAdd(int a, int b, int x)

  {

    RangeAdd(a, b, x, 0, 0, sz);

  }

  inline int RangeSum(int a, int b, int k, int l, int r)

  {

    if(a >= r || b <= l) return(0);

    if(a <= l && r <= b) return(data[k] + add[k]);

    Push(k);

    int LL = RangeSum(a, b, 2 * k + 1, l, (l + r) >> 1);

    int RR = RangeSum(a, b, 2 * k + 2, (l + r) >> 1, r);

    return(LL + RR);

  }

  inline int RangeSum(int a, int b)

  {

    return(RangeSum(a, b, 0, 0, sz));

  }

  inline int size()

  {

    return(sz);

  }

};



struct CentroidPathDecomposition

{

  struct Centroid

  {

    int ParIndex, ParDepth, Deep;

    vector< int > node;

    inline int size()

    {

      return(node.size());

    }

    inline int &operator[](int k)

    {

      return(node[k]);

    }

    inline pair< int, int > Up()

    {

      return(make_pair(ParIndex, ParDepth));

    }

  };



  vector< int > SubTreeSize, NextPath;

  vector< int > TreeIndex, TreeDepth;

  vector< Centroid > Centroids;

    

  void BuildSubTreeSize()

  {

    stack< pair< int, int > > s;

    s.push({0, -1});

    while(!s.empty()) {

      auto p = s.top(); s.pop();

      if(~SubTreeSize[p.first]) {

        NextPath[p.first] = -1;

        for(auto& to : graph[p.first]) {

          if(p.second == to) continue;

          SubTreeSize[p.first] += SubTreeSize[to];

          if(NextPath[p.first] == -1 || SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {

            NextPath[p.first] = to;

          }

        }

      } else {

        s.push(p);

        SubTreeSize[p.first] = 1;

        for(auto& to : graph[p.first]) {

          if(p.second != to) s.push({to, p.first});

        }

      }

    }

  }

  void BuildPath()

  {

    stack< pair< int, int > > s;

    Centroids.push_back((Centroid){-1, -1, 0});

    s.push({0, -1});

    TreeIndex[0] = 0;

    while(!s.empty()) {

      auto p = s.top(); s.pop();

      TreeDepth[p.first] = Centroids[TreeIndex[p.first]].size();

      for(auto& to : graph[p.first]) {

        if(p.second != to) {

          if(to == NextPath[p.first]) { // Centroid-Path

            TreeIndex[to] = TreeIndex[p.first];

          } else {                  // Not Centroid-Path

            TreeIndex[to] = Centroids.size();

            Centroids.push_back((Centroid){TreeIndex[p.first], TreeDepth[p.first], Centroids[TreeIndex[p.first]].Deep + 1});

          }

          s.push({to, p.first});

        }

      }

      Centroids[TreeIndex[p.first]].node.push_back(p.first);

    }

  }

  void AddEdge(int x, int y)

  {

    graph[x].push_back(y);

    graph[y].push_back(x);

  }

  void Build()

  {

    BuildSubTreeSize();

    BuildPath();

  }

    

  inline int size()

  {

    return(Centroids.size());

  }

  inline pair< int, int > Information(int idx)

  {

    return(make_pair(TreeIndex[idx], TreeDepth[idx]));

  }

  inline Centroid &operator[](int k)

  {

    return(Centroids[k]);

  }

  inline int LCA(int a, int b) // ??????????????¨??????

  {

    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;

    tie(TreeIdxA, TreeDepthA) = Information(a);

    tie(TreeIdxB, TreeDepthB) = Information(b);

    while(TreeIdxA != TreeIdxB) {

      if(Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {

        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();

      } else {

        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();

      }

    }

    if(TreeDepthA > TreeDepthB) swap(TreeDepthA, TreeDepthB);

    return(Centroids[TreeIdxA][TreeDepthA]);

  }

 

  CentroidPathDecomposition(int SZ)

  {

    graph.resize(SZ);

    SubTreeSize.assign(SZ, -1);

    NextPath.resize(SZ);

    TreeIndex.resize(SZ);

    TreeDepth.resize(SZ);

  }

};



CentroidPathDecomposition tree(150000);

vector< SegmentTree > segs;



void addChild(int k, int c)

{

  int TreeIdx, TreeDepth;

  tie(TreeIdx, TreeDepth) = tree.Information(k);

  segs[TreeIdx].RangeAdd(TreeDepth, segs[TreeIdx].size(), c);

}



int getDist(int k)

{

  int ret = 0, sub = 0;

  int TreeIdx, TreeDepth;

  tie(TreeIdx, TreeDepth) = tree.Information(k);

  while(TreeIdx > 0){

    sub += TreeDepth + 1;

    ret += segs[TreeIdx].RangeSum(0, TreeDepth);

    tie(TreeIdx, TreeDepth) = tree[TreeIdx].Up();

    ret += segs[TreeIdx].RangeSum(TreeDepth, TreeDepth + 1) * sub;

  }

  ret += segs[TreeIdx].RangeSum(0, TreeDepth);

  return(ret);

}





signed main()

{

  int N, Q;

  scanf("%lld %lld", &N, &Q);



  for(int i = 0; i < N - 1; i++) {

    int A, B;

    scanf("%lld %lld", &A, &B);

    tree.AddEdge(A, B);

  }

  tree.Build();

  for(int i = 0; i < tree.size(); i++) {

    segs.push_back(SegmentTree(tree[i].size()));

  }

  while(Q--) {

    int a, b, c;

    scanf("%lld %lld %lld", &a, &b, &c);

    if(a == 0) {

      printf("%lld\n", getDist(b) + getDist(c) - 2 * getDist(tree.LCA(b, c)));

    } else {

      addChild(b, c);

    }

  }

}