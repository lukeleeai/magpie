#include <cstdio>

#include <queue>

#include <vector>

#include <algorithm>

#include <utility>

#include <functional>

using namespace std;



typedef pair<int,int> pii;



int main(){

	int n, m, k, u;

	scanf("%d%d%d", &n, &m, &k);



	vector<int> a(m), b(m), L(m);

	vector<vector<pii> > G(n + 1);

	for(int i = 0; i < m; ++i){

		scanf("%d%d%d", &a[i], &b[i], &L[i]);

		G[a[i]].push_back(pii(L[i], b[i]));

		G[b[i]].push_back(pii(L[i], a[i]));

	}



	priority_queue<pii,vector<pii>,greater<pii> > pq;

	vector<int> d(n + 1, 500000000);

	for(int i = 0; i < k; ++i){

		scanf("%d", &u);

		d[u] = 0;

		pq.push(pii(0, u));

	}



	while(!pq.empty()){

		int e = pq.top().first;

		u = pq.top().second;

		pq.pop();

		if(d[u] != e){ continue; }

		for(size_t i = 0; i < G[u].size(); ++i){

			int v = G[u][i].second;

			int f = e + G[u][i].first;

			if(d[v] > f){

				d[v] = f;

				pq.push(pii(f, v));

			}

		}

	}



	int ans = 0;

	for(int i = 0; i < m; ++i){

		int e = d[a[i]];

		int f = d[b[i]];

		int r = max(max(e, f), e + (f - e + L[i] + 1) / 2);

		ans = max(ans, r);

	}

	printf("%d\n", ans);

}