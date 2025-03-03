#include "stdc++.h"

//#pragma GCC optimize("Ofast")



#define fi first

#define se second



const int N = 100100;



using namespace std;



namespace Dinic {



	using F = int;

	const F INF = 1e9+1e8;



	const int N = 220000;

	const int M = 1100000;



	int fst[N], nxt[M], to[M];

	F cap[M];

	int dis[N], q[N], ptr[N];

	int E;



	void init() {

		memset(fst, -1, sizeof fst);

		E = 0;

	}

	inline void add_edge(int u, int v, F c) {

		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;

		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;

	}

	inline bool bfs(int S, int T, int n) {

		memset(dis, -1, sizeof(int) * n);

		int h = 0, t = 0;

		dis[S] = 0, q[t++] = S;

		while (h < t) {

			int u = q[h++];

			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {

				dis[to[e]] = dis[u] + 1, q[t++] = to[e];

				if (to[e] == T) return 1;

			}

		}

		return (dis[T] != -1);

	}

	F dfs(int u, int T, F f) {

		if (u == T) return f;

		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {

			F ret = dfs(to[e], T, min(f, cap[e]));

			if (ret > 0) {

				cap[e] -= ret, cap[e ^ 1] += ret;

				return ret;

			}

		}

		return 0;

	}

	F max_flow(int S, int T, int n) {

		F ret = 0;

		while (bfs(S, T, n)) {

			memcpy(ptr, fst, sizeof(int) * n);

			for (F cur; (cur = dfs(S, T, INF)) > 0; ret += cur);

		}

		return ret;

	}

};



int n;

int p[N];

int q[N];

int A[N];

int B[N];



int main()

{

        //freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);



        ios_base::sync_with_stdio(0);



        cin >> n;

        for(int i = 0; i < n; i++){

                cin >> p[i];

        }

        for(int i = 0; i < n; i++){

                cin >> q[i];

        }

        int G = 0;

        for(int i = 0; i < n; i++){

                if(A[i] == 0){

                        G += 1;

                        A[i] = G;

                        int j = p[i];

                        while(j != i){

                                A[j] = G;

                                j = p[j];

                        }

                }

                if(B[i] == 0){

                        G += 1;

                        B[i] = G;

                        int j = q[i];

                        while(j != i){

                                B[j] = G;

                                j = q[j];

                        }

                }

        }

        G += 1;

        Dinic::init();



        int res = n;

        for(int i = 0; i < n; i++){

                if(p[i] == i && q[i] == i){

                        res -= 1;

                } else if(p[i] == i){

                        Dinic::add_edge(B[i], G, 1);

                } else if(q[i] == i){

                        Dinic::add_edge(0, A[i], 1);

                } else{

                        Dinic::add_edge(B[i], A[i], 1);

                        if(p[i] == q[i]){

                                Dinic::add_edge(A[i], B[i], 1);

                        }

                }

        }

        res -= Dinic::max_flow(0, G, G + 1);



        cout << res << '\n';

}
