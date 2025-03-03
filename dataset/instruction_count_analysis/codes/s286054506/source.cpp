#include "stdc++.h"



using namespace std;



struct FlowEdge

{

	int u, v;

	long long c, f = 0;

	FlowEdge(){}

	FlowEdge(int _u,int _v,long long _c)

	{

		u = _u; v = _v; c = _c;

	}

};



struct Template_Dinic

{

	const long long flow_INF = 1e18;	

	vector<FlowEdge> Edges;

	vector<vector<int>> AdjList;

	int n, s, t, m = 0;

	vector<int> d, ptr;

	queue<int> q;



	void init(int _n,int _s,int _t)

	{

		n = _n, s = _s, t = _t;

		AdjList.resize(n + 1); 

		d.resize(n + 1);

		ptr.resize(n + 1);

	}



	void add_edge(int u,int v,long long c)

	{

		Edges.push_back(FlowEdge(u,v,c));

		Edges.push_back(FlowEdge(v,u,c));

		AdjList[u].push_back(m);

		AdjList[v].push_back(m + 1);

		m += 2;

	}



	bool bfs()

	{

		while(!q.empty())

		{

			int u = q.front();

			q.pop();

			for (int i=0;i<AdjList[u].size();i++)

			{

				int id = AdjList[u][i];

				if (Edges[id].f < Edges[id].c && d[Edges[id].v] == -1)

				{

					d[Edges[id].v] = d[u] + 1;

					q.push(Edges[id].v);

				}

			}

		}

		return d[t] != -1;

	}



	long long dfs(int u, long long cur)

	{

		if (cur == 0) return 0;

		if (u == t) return cur;

		for (int& cid = ptr[u];cid < AdjList[u].size();cid++)

		{

			int id = AdjList[u][cid];

			int v = Edges[id].v;

			if (d[u] + 1 == d[v] && Edges[id].f < Edges[id].c)

			{

				long long nxt = dfs(v, min(cur,Edges[id].c - Edges[id].f));

				if (!nxt) continue;

				Edges[id].f += nxt;

				Edges[id ^ 1].f -= nxt;

				return nxt;

			}

		}

		return 0;

	}



	long long flow()

	{

		long long res = 0;

		while(1)

		{

			for (int i=0;i<d.size();i++) d[i] = -1;

			d[s] = 0;

			q.push(s);

			if (!bfs())

				break;

			for (int i=0;i<ptr.size();i++) ptr[i] = 0;

			while(long long cur = dfs(s, flow_INF))

				res += cur; 	

		}

		return res;

	}

}Dinic;



int h,w;



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);



	cin >> h >> w;

	Dinic.init(500,0,201);

	for (int i=1;i<=h;i++)

		for (int j=1;j<=w;j++)	

		{

			char c; cin >> c;

			if (c == 'S')

			{

				Dinic.add_edge(0,i,1e9);

				Dinic.add_edge(0,j+100,1e9);	

			}

			else if (c == 'T')

			{

				Dinic.add_edge(i,201,1e9);

				Dinic.add_edge(j+100,201,1e9);

			}

			else if (c == 'o')

				Dinic.add_edge(i,j+100,1);

		}

	long long res = Dinic.flow();

	if (res >= 1e9) cout << -1;

	else cout << res;

}