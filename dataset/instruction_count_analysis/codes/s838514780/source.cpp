#include <algorithm>

#include <iostream>

#include <vector>

#include <queue>

using namespace std;



//---------------------------------------------------------------

// ------ graph ------ //

using Weight = int;

using Flow = int;

struct Edge {

    int src, dst;

    Weight weight;

    Flow cap;

    Edge() : src(0), dst(0), weight(0) { }

    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) { }

};

bool operator < (const Edge &e, const Edge &f) {

    return e.weight != f.weight ? e.weight > f.weight : // pqが降順のため

        e.src != f.src ? e.src < f.src : e.dst < f.dst;

}

using Edges = vector<Edge>;

struct Graph {

    vector<Edges> adj;

    Graph(int n) : adj(n) { }

    int size() { return adj.size(); }

    Edges operator [] (int v) { return adj[v]; }

    void add_edge(int a, int b, Weight w = 1) { // graph

        adj[a].emplace_back(a, b, w);

        adj[b].emplace_back(b, a, w);

    }

    void add_arc(int a, int b, Weight w = 1) {  // digraph

        adj[a].emplace_back(a, b, w);

    }

};

using Array = vector<Weight>;

using Matrix = vector<Array>;



// ------ Topological Sort (Kahn) ------ //

vector<int> tsort(Graph &g) {

    int n = g.size(), k = 0;

    vector<int> ord(n), in(n);

    for (int i = 0; i < n; i++) for (Edge &e : g[i]) in[e.dst]++;

    queue<int> q;

    for (int i = 0; i < n; i++) if (in[i] == 0) q.push(i);

    while (!q.empty()) {

        int v = q.front(); q.pop();

        ord[k++] = v;

        for (Edge &e : g[v]) if (--in[e.dst] == 0) q.push(e.dst);

    }

    return *max_element(in.begin(), in.end()) == 0 ? ord : vector<int>();

}

//---------------------------------------------------------------



int main() {

    int V, E; cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {

        int s, t; cin >> s >> t;

        g.add_arc(s, t);

    }

    vector<int> ord = tsort(g);

    for (int i = 0; i < V; i++) cout << ord[i] << endl;

    return 0;

}
