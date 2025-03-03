#include "stdc++.h"

#define REP(i,a,b) for(int i=(a);i<(b);i++)

#define RREP(i,a,b) for(int i=(a);i>=(b);i--)

#define pq priority_queue

#define P pair<int,int>

#define P2 pair<int,P>

#define P3 pair<int,P2>

typedef long long ll; typedef long double ld;

using namespace std;

const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};

const int vx[]={1,0,-1,0}, vy[]={0,1,0,-1};

const ll LINF=1e18;

const ld PI=abs(acos(-1));



int dp[100010], h[100010];

vector<int> g[100010];



struct UnionFind{

	vector<int> data;

	

	UnionFind(int sz){

		data.assign(sz, -1);

	}

	

	void unite(int x, int y){

		x = find(x); y = find(y);

		if(x == y) return ;

		if(data[x] > data[y]) swap(x, y);

		data[x] += data[y];

		data[y] = x;

	}

	

	int find(int k){

		if(data[k] < 0) return k;

		return data[k] = find(data[k]);

	}

	

	bool same(int x, int y){

		x = find(x); y = find(y);

		if(x == y) return true;

		else return false;

	}

};



int solve(int p, int par = -1){

	if(dp[p]) return dp[p];

	

	int c = !(h[p] % 2);

	for(auto e:g[p]){

		if(e == par) continue;

		c += solve(e, p);

	}

	

	return c;

}



int main(){

	int n, m; cin >> n >> m;

	UnionFind uf(n);

	REP(i,0,m){

		int a, b; cin >> a >> b; a--; b--;

		if(uf.same(a, b)){

			g[a].push_back(b);

			g[b].push_back(a);

			uf.unite(a, b);

			h[a]++; h[b]++;

		}else{

			h[a]++; h[b]++;

		}

	}

	

	REP(i,0,n) if(h[i] % 2){cout << "NO" << endl; return 0;}

	cout << "YES" << endl;

	return 0;

}
