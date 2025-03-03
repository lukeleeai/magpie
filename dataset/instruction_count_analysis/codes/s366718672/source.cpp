// D - Friend Suggestions

// UnionFinde version (None rank)

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

#define rp(i,s,e) for(int i=(s);i<(e);++i)



class UnionFind{//union-find class (None rank)

	vector<int> parent;//parent number

	public:

	UnionFind(int n){

		parent.resize(n);

		init();

	}

	void init(){//initialize all parent to root

		for(int v=0; v<parent.size(); ++v) parent[v] = v;

	}

	int root(int v){//get root

		if(parent[v]==v) return v;//root

		return parent[v] = root(parent[v]);//path compression

	}

	void unite(int v, int u){

		v = root(v); u = root(u);

		if(v==u) return;

		parent[v] = u;

	}

	bool same(int v, int u){return root(v)==root(u);}//v & u the same set

};



int main(){

	int N,M,K; scanf("%d%d%d",&N,&M,&K);

	UnionFind uf(N+1);

	vi C(N+1), gid(N+1);

	int s,t;

	rp(i,0,M){

		scanf("%d%d",&s,&t);

		uf.unite(s,t);

		C[s]++; C[t]++;

	}

	rp(i,0,K){

		scanf("%d%d",&s,&t);

		if(uf.root(s) == uf.root(t)) C[s]++, C[t]++;

	}

	vi cnt(N+1); rp(i,1,N+1) cnt[uf.root(i)]++;

	rp(i,1,N+1) printf("%d ", cnt[uf.root(i)]-C[i]-1);

}