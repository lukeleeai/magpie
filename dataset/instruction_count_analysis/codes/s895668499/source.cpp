#include <iostream>

#include <cstring>

#include <cstdio>

#include <queue>

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

const int maxn = 1e6+5;



struct Node {

	int to, next;

	ll w;

}edge[maxn<<1];

int head[maxn], cnt;

ll dis[maxn];

ll dist[maxn];

bool vis[maxn];



void init(int n) {

	cnt = 0;

	memset(dis, INF, sizeof(dis));

	memset(head, -1, sizeof(head));

}



void addEdge(int from, int to, ll w) {

	edge[cnt].to = to;

	edge[cnt].w = w;

	edge[cnt].next = head[from];

	head[from] = cnt++;

}



void spfa(int s) {

    dis[s] = 0;

    queue<int> q;

    q.push(s);

	vis[s] = 1;

	while (!q.empty()) {

		

		int num = q.front(); q.pop();

		vis[num] = 0;

		for (int i = head[num]; i != -1; i = edge[i].next) {

			Node e = edge[i];

		//	cout << e.w << "  --  ";

			if (dis[e.to] > dis[num] + e.w) {

				dis[e.to] = dis[num] + e.w;

				if (!vis[e.to]) {

					vis[e.to] = 1;

					q.push(e.to);

				}

			}

		}

	}

}





void dij(int s, int e, int n) {

    memset(vis, 0, sizeof(vis));

    int mina, k;

    memset(dist, INF, sizeof(dist));

    for (int i = 0, j = 0; ~i; i = edge[i].next, j++) {

        dist[j] = edge[i].w;

    }

    

    for (int i = 1; i < n; i++) {

        mina = INF, k =0;

        for (int j = 0; j < n; j++) {

            if (!vis[j] && dist[j] < mina) {

                mina = dist[j];

                k = j;

            }

        }

        vis[k] = 1;

        for (int j = 0, s = 0; ~j; j = edge[j].next, s++) {

            if (!vis[s] && dist[s] > edge[j].w + dist[k]) {

                dist[s] = edge[j].w + dist[k];

            }

        }

    }

    

}





int main(void) {

    int t;

    scanf("%d", &t);

    init(t);

    for (int i = 0; i < t-1; i++) {

        int v, u, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);

        addEdge(v, u, w);

    }

    

    int q, k;

    scanf("%d %d", &q, &k);

    spfa(k);

    for (int i = 1; i <= t; i++) {

       // cout << dis[i] << "  **  " ;

    }

    for (int i = 0; i < q; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        //dij(u, k, t);

        printf("%lld\n", dis[u]+dis[v]);

    }

    

}