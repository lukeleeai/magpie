#include "stdc++.h"



using namespace std;



const int INF = 1001001001;



struct Edge {

	int to, cost, cost2;

	Edge(int to, int cost, int cost2 = 0) : to(to), cost(cost), cost2(cost2){}

	Edge(){}

	bool operator > (const Edge &a) const {

		return (cost > a.cost);

	}

};



int main()

{

	int n, m, c;



	while (scanf("%d %d %d", &n, &m, &c) && n){

		vector<Edge> G[128];



		for (int i = 0; i < m; i++){

			int f, t, cst;

			scanf("%d %d %d", &f, &t, &cst);

			G[f - 1].push_back(Edge(t - 1, cst));

		}



		bool vis[128][128];

		memset(vis, 0, sizeof(vis));



		priority_queue< Edge, vector<Edge>, greater<Edge> > pq;

		pq.push(Edge(0, 0));



		int ans = n;

		while (pq.size()){

			Edge e = pq.top(); pq.pop();

			if (vis[e.to][e.cost2]) continue;

			vis[e.to][e.cost2] = true;



			if (e.to == n - 1){

				ans = min(ans, e.cost2);

				continue;

			}



			for (int i = 0; i < G[e.to].size(); i++){

				Edge nxt = G[e.to][i];

				if (e.cost + nxt.cost <= c && !vis[nxt.to][e.cost2]) pq.push(Edge(nxt.to, e.cost + nxt.cost, e.cost2));

				if (e.cost2 < n && !vis[nxt.to][e.cost2 + 1]) pq.push(Edge(nxt.to, e.cost, e.cost2 + 1));

			}

		}



		printf("%d\n", ans);

	}



	return (0);

}