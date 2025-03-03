#include "stdc++.h"

using namespace std;



#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)

#define REP(i, n) FOR(i, 0, n)



struct Edge {

    int src, dst, capacity;

    Edge(int src, int dst, int capacity): src(src), dst(dst), capacity(capacity) {}

};

using Vertex = vector<Edge>;

using Graph = vector<Vertex>;



void add_edge(Graph& graph, int src, int dst, int capacity) {

    graph[src].emplace_back(src, dst, capacity);

    graph[dst].emplace_back(dst, src, 0);

}



int edmonds_karp(Graph& graph, int source, int sink) {

    vector<vector<int>> flow(graph.size(), vector<int>(graph.size()));

    Edge dummy(-1, -1, -1);

    int total = 0;

    for (;;) {

        // find path

        queue<int> Q; Q.push(source);

        vector<Edge*> prev(graph.size()); prev[source] = &dummy;

        while (!Q.empty() && prev[sink] == nullptr) {

            int u = Q.front(); Q.pop();

            for (auto& e : graph[u]) {

                if (prev[e.dst] == nullptr && e.capacity - flow[e.src][e.dst] > 0) {

                    prev[e.dst] = &e;

                    Q.push(e.dst);

                }

            }

        }

        if (prev[sink] == nullptr) return total;



        // augment flow

        int f = INT_MAX;

        for (int u = sink; prev[u] != &dummy; u = prev[u]->src) {

            Edge* e = prev[u];

            f = min(f, e->capacity - flow[e->src][e->dst]);

        }

        for (int u = sink; prev[u] != &dummy; u = prev[u]->src) {

            Edge* e = prev[u];

            flow[e->src][e->dst] += f;

            flow[e->dst][e->src] -= f;

        }

        total += f;

    }

}



int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }



int main() {

    cin.tie(0); ios_base::sync_with_stdio(false);



    int m, n;

    while (cin>>m>>n, m|n) {

        vector<int> blue(m), red(n);

        REP(i, m) cin >> blue[i];

        REP(i, n) cin >> red[i];



        Graph graph(m+n+2);

        REP(i, m) REP(j, n) {

            if (gcd(blue[i], red[j]) > 1)

                add_edge(graph, i, m+j, 1);

        }

        REP(i, m) add_edge(graph, m+n, i, 1);

        REP(j, n) add_edge(graph, m+j, m+n+1, 1);



        cout << edmonds_karp(graph, m+n, m+n+1) << '\n';

    }

}