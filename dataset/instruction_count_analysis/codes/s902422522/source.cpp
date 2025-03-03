#include<queue>

#include<cstdio>

#include<vector>

#include<cstring>

#include<algorithm>

using namespace std;

const int MAXM = 200000;

const int MAXN = 300000;

struct edge{

	int u, v, c;

}edges[MAXM + 5];

bool operator < (edge a, edge b) {

	return a.c < b.c;

}

vector<int>G[MAXN + 5];

void addedge(int u, int v) {

	G[u].push_back(v);

	G[v].push_back(u);

}

int vcnt, fa[MAXN + 5], con[MAXN + 5], vis[MAXN + 5];

int Find(int x) {

	if( fa[x] == x ) return x;

	return fa[x] = Find(fa[x]);

}

void Union(int x, int y) {

	int fx = Find(x), fy = Find(y);

	if( fx != fy ) fa[fx] = fy;

}

int dis[MAXN + 5];

void bfs(int s) {

	memset(dis, -1, sizeof dis);

	queue<int>que; que.push(s);

	dis[s] = 0;

	while( !que.empty() ) {

		int f = que.front(); que.pop();

		for(int i=0;i<G[f].size();i++) {

			if( dis[G[f][i]] == -1 ) {

				dis[G[f][i]] = dis[f] + 1;

				que.push(G[f][i]);

			}

		}

	}

}

int main() {

	int N, M;

	scanf("%d%d", &N, &M);

	for(int i=1;i<=M;i++)

		scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].c);

	sort(edges+1, edges+M+1);

	vcnt = N; int lst = 1;

	for(int i=2;i<=M+1;i++) {

		if( edges[i].c != edges[i-1].c ) {

			for(int j=lst;j<i;j++) {

				fa[edges[j].u] = edges[j].u;

				fa[edges[j].v] = edges[j].v;

				con[edges[j].u] = con[edges[j].v] = 0;

				vis[edges[j].u] = vis[edges[j].v] = false; 

			}

			for(int j=lst;j<i;j++)

				Union(edges[j].u, edges[j].v);

			for(int j=lst;j<i;j++) {

				if( fa[edges[j].u] == edges[j].u )

					if( con[edges[j].u] == 0 )

						con[edges[j].u] = (++vcnt);

				if( fa[edges[j].v] == edges[j].v )

					if( con[edges[j].v] == 0 )

						con[edges[j].v] = (++vcnt);	

			}

			for(int j=lst;j<i;j++) {

				if( !vis[edges[j].u] ) {

					addedge(edges[j].u, con[Find(edges[j].u)]);

					vis[edges[j].u] = true;

				}

				if( !vis[edges[j].v] ) {

					addedge(edges[j].v, con[Find(edges[j].v)]);

					vis[edges[j].v] = true;

				}

			}

			lst = i;

		}

	}

	bfs(1);

	if( dis[N] == -1 ) puts("-1");

	else printf("%d\n", dis[N] / 2);

}