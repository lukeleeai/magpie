#include "stdc++.h"

using namespace std;

typedef long long int ll;

const int S = 100010;



struct UnionFind {

  vector<int> node;

  vector<ll> weight;

  UnionFind() : node(S, -1), weight(S, 0) {}

  void unite(int u, int v, ll w) {

    int ov = v, ou = u;

    u = find(u), v = find(v);

    int wa = weight[ov], wb = weight[ou];

    if(u == v) return;

    

    // (v ??????) ??? (u ??????) ???????????????

    node[u] += node[v];

    node[v] = u;

    weight[v] += w + wb - wa;

  }

  

  int find(int u) {

    if(node[u] < 0) return u;

    int par = node[u], root = find(node[u]);

    weight[u] += weight[par];

    return node[u] = root;

  }

};



int main() {

  int N, M;

  while(cin >> N >> M, N) {

    UnionFind uf;

    for(int i=0; i<M; i++) {

      char c; cin >> c;

      if(c == '!') {

	int a, b, d; cin >> a >> b >> d;

	a--; b--;

	uf.unite(a, b, d);

      }

      else {

	int a, b; cin >> a >> b;

	a--; b--;

	if(uf.find(a) != uf.find(b)) cout << "UNKNOWN" << endl;

	else {

	  ll wa = uf.weight[a];

	  ll wb = uf.weight[b];

	  cout << wb - wa << endl;

	}

      }

    }

  }

  return 0;

}