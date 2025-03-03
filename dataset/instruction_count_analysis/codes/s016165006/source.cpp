#include "stdc++.h"



using namespace std;



using int64 = long long;

const int64 INF = 1LL << 62;



struct UnionFind

{

  vector< int > data;



  UnionFind(int sz)

  {

    data.assign(sz, -1);

  }



  bool unite(int x, int y)

  {

    x = find(x), y = find(y);

    if(x == y) return (false);

    if(data[x] > data[y]) swap(x, y);

    data[x] += data[y];

    data[y] = x;

    return (true);

  }



  int find(int k)

  {

    if(data[k] < 0) return (k);

    return (data[k] = find(data[k]));

  }



  int size(int k)

  {

    return (-data[find(k)]);

  }

};



int main()

{

  int N, M, A[100000], B[100000];



  cin >> N >> M;

  UnionFind uf(N);

  for(int i = 0; i < M; i++) {

    cin >> A[i] >> B[i];

    --A[i], --B[i];

    uf.unite(A[i], B[i]);

  }



  bitset< 100001 > dp;

  dp[uf.size(0)] = true;

  for(int i = 2; i < N; i++) {

    if(uf.find(i) == uf.find(1)) continue;

    if(uf.find(i) == uf.find(0)) continue;

    if(uf.find(i) != i) continue;

    dp |= dp << uf.size(i);

  }



  int64 ret = -INF;

  for(int64 i = 1; i < N; i++) {

    if(dp[i]) {

      int64 j = N - i;

      ret = max(ret, i * (i - 1) / 2 + j * (j - 1) / 2);

    }

  }



  cout << ret - M << endl;

}