#include "stdc++.h"

using namespace std;



typedef pair<long long, int> pli;



const int N = 1e5 + 10;

int h[N], n, cnt[N], par[N];

long long d[N], check;

vector<pli> di;

vector<int> child[N];

map<long long, int> mp;



void dfs(int v, int p){

	h[v] = h[p] + 1;

	for (int u : child[v])

		dfs(u, v);

}



int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);cout.tie(0);

	

	cin >> n;

	for (int i = 0; i < n; i++){

		cin >> d[i];

		di.push_back({d[i], i});

		mp[d[i]] = i + 1;

	}

	

	sort(di.begin(), di.end());

	reverse(di.begin(), di.end());

	

	for (int i = 0; i < n; i++)

		cnt[i] = 1;

	for (int i = 0; i < n - 1; i++){

		int v = di[i].second;

		long long dis = di[i].first,

				  par_dis = dis + (2 * cnt[v]) - n;

		

		if(mp[par_dis] == 0)

			return cout << -1, 0;

		

		int ver_par = mp[par_dis] - 1;

		cnt[ver_par] += cnt[v];

		par[v] = ver_par;

		child[par[v]].push_back(v);

	}

	

	int root = di[n - 1].second;

	h[root] = -1;

	par[root] = root;

	dfs(root, root);

	

	for (int i = 0; i < n; i++)

		check += h[i];

	

	if(check != d[root])

		return cout << -1, 0;

	

	for (int i = 0; i < n; i++)

		if(par[i] != i)

			cout << par[i] + 1 << ' ' << i + 1 << endl;

}