#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <cstring>

using namespace std;



class Edge

{

public:

	int src,dst,cst;

	Edge(int src, int dst, int cst)

	:src(src),dst(dst),cst(cst)

	{}

};



class State

{

public:

	int p,c,d;

	State(int p, int c, int d)

	:p(p),c(c),d(d)

	{}

	

	bool operator<(const State& s) const {

		if(c != s.c) return c > s.c;



		return d > s.d;

	}

};



typedef vector<vector<Edge> > Graph;



int N,M,C,S,G;

int COST[10001][20];

int P[20], Q[20][51], R[20][51];

int ct[100][100];

bool vis[100];



void dijkstra(int Start, int com, Graph& graph)

{

	memset(vis, 0, sizeof(vis));



	priority_queue<State> q;

	q.push(State(Start, 0, 0));



	while(!q.empty()) {

		State s=q.top(); q.pop();

		if(vis[s.p]) continue;

		vis[s.p] = 1;



		if(ct[Start][s.p] == -1) ct[Start][s.p] = s.c;

		else ct[Start][s.p] = min(ct[Start][s.p], s.c);



		for(int i=0; i<graph[s.p].size(); i++) {

			Edge& e = graph[s.p][i];



			int td = s.d + e.cst;

			int nc = 0;

			if(td > Q[com][P[com] - 1]) {

				nc = COST[Q[com][P[com] - 1]][com] + abs(td - Q[com][P[com]-1]) * R[com][P[com]-1];

			}

			else nc = COST[td][com];



			if(vis[e.dst]) continue;

			q.push(State(e.dst, nc, td));

		} 

	}

}



int solve(int Start, int Goal, Graph& graph)

{

	memset(vis, 0, sizeof(vis));

	

	priority_queue<State> q;

	q.push(State(Start, 0, 0));



	while(!q.empty()) {

		State s=q.top(); q.pop();

		if(vis[s.p]) continue;

		vis[s.p] = 1;



		if(s.p == Goal) return s.c;



		for(int i=0; i<graph[s.p].size(); i++) {

			Edge& e = graph[s.p][i];



			if(vis[e.dst]) continue;

			q.push(State(e.dst, s.c + e.cst, 0));

		}

	}



	return -1;

}



int main()

{

	std::ios::sync_with_stdio(false);



	while(cin >> N >> M >> C >> S >> G, (N||M||C||S||G)) {

		S--; G--;



		vector<Graph> graph(C);

		for(int i=0; i<C; i++)

			graph[i].resize(N);



		for(int i=0; i<M; i++) {

			int a,b,c,d;

			cin >> a >> b >> d >> c;

			a--; b--; c--;



			graph[c][a].push_back(Edge(a,b,d));

			graph[c][b].push_back(Edge(b,a,d));

		}



		for(int i=0; i<C; i++)

			cin >> P[i];



		for(int i=0; i<C; i++) {

			Q[i][0] = 0;



			for(int j=1; j<P[i]; j++)

				cin >> Q[i][j];

			

			for(int j=0; j<P[i]; j++)

				cin >> R[i][j];

		}



		for(int i=0; i<C; i++)

			COST[0][i] = 0;



		for(int i=0; i<C; i++)

		for(int j=1; j<P[i]; j++)

		for(int k=Q[i][j-1]+1; k<=Q[i][j]; k++) 

			COST[k][i] = COST[k-1][i] + R[i][j - 1];





		memset(ct, -1, sizeof(ct));

		for(int k=0; k<C; k++) 

		for(int i=0; i<N; i++) 

			dijkstra(i, k, graph[k]);





		Graph final(N);

		for(int i=0; i<N; i++)

		for(int j=i+1; j<N; j++) {

			if(ct[i][j] == -1) continue;

			final[i].push_back(Edge(i,j,ct[i][j]));

			final[j].push_back(Edge(j,i,ct[j][i]));

		}



		cout <<  solve(S, G, final) << endl;

	}

}