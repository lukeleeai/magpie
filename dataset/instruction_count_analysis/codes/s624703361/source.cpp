#include "stdc++.h"



using namespace std;



template <typename T>

struct Edge {

    int rev, from, to;

    T cap, icap;

    Edge(int rev, int from, int to, T cap)

        : rev(rev), from(from), to(to), cap(cap), icap(cap) {}

};



template <typename T>

struct Graph {

    vector<vector<Edge<T>>> list;

    Graph(int n = 0) : list(n) {}

    void init(int n = 0) {

        list.clear();

        list.resize(n);

    }

    inline vector<Edge<T>> &operator[](int i) { return list[i]; }

    inline const size_t size() const { return list.size(); }

    inline Edge<T> &redge(Edge<T> e) {

        if (e.from != e.to) return list[e.to][e.rev];

        else return list[e.to][e.rev + 1];

    }



    void addEdge(int from, int to, T cap) {

        list[from].push_back(Edge<T>((int)list[to].size(), from, to, cap));

        list[to].push_back(Edge<T>((int)list[from].size() - 1, to, from, 0));

    }

};



template <typename T>

struct Dinic {

    const T INF = 1 << 30;

    vector<int> level, iter;



    Dinic() {}

    void bfs(Graph<T> &graph, int s) {

        level.assign((int)graph.size(), -1);

        level[s] = 0;

        queue<int> que;

        que.push(s);

        while (!que.empty()) {

            int v = que.front();

            que.pop();

            for (int i = 0; i < graph[v].size(); i++) {

                Edge<T> &e = graph[v][i];

                if (level[e.to] < 0 && e.cap > 0) {

                    level[e.to] = level[v] + 1;

                    que.push(e.to);

                }

            }

        }

    }



    T dfs(Graph<T> &graph, int v, int t, T f) {

        if (v == t) return f;

        for (int &i = iter[v]; i < graph[v].size(); i++) {

            Edge<T> &e = graph[v][i], &re = graph.redge(e);

            if (level[v] < level[e.to] && e.cap > 0) {

                T d = dfs(graph, e.to, t, min(f, e.cap));

                if (d > 0) {

                    e.cap -= d;

                    re.cap += d;

                    return d;

                }

            }

        }

        return 0;

    }

    T solve(Graph<T> &graph, int s, int t) {

        level.assign((int)graph.size(), -1);

        iter.assign((int)graph.size(), 0);

        T res = 0;

        for (;;) {

            bfs(graph, s);

            if (level[t] < 0) return res;

            for (int i = 0; i < (int)iter.size(); i++) iter[i] = 0;

            T flow = 0;

            while ((flow = dfs(graph, s, t, INF)) > 0) {

                res += flow;

            }

        }

    }

};



int main() {

    int V, E;

    cin >> V >> E;

    Graph<int> graph(V);

    for (int i = 0; i < E; i++) {

        int u, v, c;

        cin >> u >> v >> c;

        graph.addEdge(u, v, c);

    }

    Dinic<int> dinic;

    int s = 0, t = V - 1;

    cout << dinic.solve(graph, s, t) << endl;

    return 0;

}
