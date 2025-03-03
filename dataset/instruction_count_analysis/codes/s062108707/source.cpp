#include "stdc++.h"



using namespace std;

#define int long long



struct UnionFind

{

  vector< int > data;



  UnionFind(int sz)

  {

    data.assign(sz, -1);

  }



  void unite(int x, int y)

  {

    x = find(x), y = find(y);

    if(x != y) {

      if(data[x] > data[y]) swap(x, y);

      data[x] += data[y];

      data[y] = x;

    }

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



int N, R, s, t;

int a[100000], b[100000];

UnionFind tree(100000);

int ret[100000];

const int INF = 1LL << 59;



void ask(int v)

{

  map< int, vector< pair< int, int > > > backet;

  for(int i = 0; i < N; i++) {

    backet[a[i]].push_back(make_pair(b[i], i));

  }

  for(auto &obj : backet) {

    vector< pair< int, int > > &cc = obj.second;

    sort(begin(cc), end(cc));

    for(int j = 1; j < cc.size(); j++) {

      //tree.unite(cc[j - 1].second, cc[j].second);

    }

  }

  for(int i = 0; i < N; i++) {

    if(!backet.count(a[i] - R)) continue;

    auto &cc = backet[a[i] - R];



    auto p = lower_bound(begin(cc), end(cc), make_pair(b[i] - R - v, +INF));

    auto q = lower_bound(begin(cc), end(cc), make_pair(b[i] + R + v, -INF));

    ret[i] += q - p;

    if(p != q) tree.unite(i, p->second);

  }

  for(int i = 0; i < N; i++) {

    if(!backet.count(a[i] + R)) continue;

    auto &cc = backet[a[i] + R];

    auto p = lower_bound(begin(cc), end(cc), make_pair(b[i] - R - v, +INF));

    auto q = lower_bound(begin(cc), end(cc), make_pair(b[i] + R + v, -INF));

    ret[i] += q - p;

    if(p != q) tree.unite(i, p->second);

  }

}



signed main()

{

  cin >> N >> s >> t;

  for(int i = 0; i < N; i++) {

    int x, y;

    cin >> x >> y;

    a[i] = x + y;

    b[i] = x - y;

  }

  --s, --t;

  R = max(abs(a[s] - a[t]), abs(b[s] - b[t]));

  ask(false);

  for(int i = 0; i < N; i++) swap(a[i], b[i]);

  ask(true);



  tree.unite(s, t);

  long long res = 0;

  for(int i = 0; i < N; i++) {

    if(tree.find(i) == tree.find(s)) res += ret[i];

  }

  cout << res / 2 << endl;

}