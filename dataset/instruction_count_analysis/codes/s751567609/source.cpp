// D - Coloring Edges on Tree

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

using vvi = vector<vi>;

#define rp(i,s,e) for(int i=(s);i<(e);++i)

#define eb emplace_back

#define NMAX 100000



int K = 1;

vvi tree(NMAX);

vi colors(NMAX), visited(NMAX);



void dfs(int p, int p_color){

	K = max(K, (int)tree[p].size());

	int color = 1;

	for(int c:tree[p]){

		if(visited[c]) continue;

		visited[c] = true;

		colors[c] = color==p_color? ++color: color;

		dfs(c, color++);

	}

}



int main(){

	int N; cin>>N;

	vi C(N-1);

	rp(i, 0, N-1){

		int p,c; cin>>p>>c; p--,c--;

		tree[p].eb(c); tree[c].eb(p);

		C[i] = c;

	}

	visited[0] = true;

	dfs(0, -1);

	cout<< K <<endl;

	for(auto c:C) cout<< colors[c] <<endl;

}