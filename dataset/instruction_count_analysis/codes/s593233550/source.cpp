#include <iostream>

#include <cstdio>

#include <cassert>

#include <cstring>

#include <vector>

#include <valarray>

#include <array>

#include <queue>

#include <set>

#include <unordered_set>

#include <map>

#include <unordered_map>

#include <algorithm>

#include <cmath>

#include <complex>

#include <random>



using namespace std;

using uint = unsigned int;

using ll = long long;

using ull = unsigned long long;

template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}



template <class E>

using Graph = vector<vector<E>>;



template<class D, D INF>

struct Dijkstra {

    vector<D> res; //res[i] = sからiまでの最短距離

    

    template<class E>

    Dijkstra(const Graph<E> &g, int s) {

        int V = (int)g.size();

        res = vector<D>(V, INF);

        

        using P = pair<D, int>;

        priority_queue<P, vector<P>, greater<P>> q;

        q.push(P(0, s));

        res[s] = 0;

        while (!q.empty()) {

            P p = q.top(); q.pop();

            if (res[p.second] < p.first) continue;

            for (E e: g[p.second]) {

                if (p.first+e.dist < res[e.to]) {

                    res[e.to] = p.first+e.dist;

                    q.push(P(res[e.to], e.to));

                }

            }

        }

    }

};



const int MN = 100100;



int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    using P = pair<int, int>;

    set<int> gc[MN];

    vector<P> g[MN];

    for (int i = 0; i < m; i++) {

        int p, q, c;

        scanf("%d %d %d", &p, &q, &c); p--; q--;

        gc[p].insert(c);

        gc[q].insert(c);

        g[p].push_back(P(q, c));

        g[q].push_back(P(p, c));

    }



    int co = 0;

    map<P, int> p2id;

    for (int i = 0; i < n; i++) {

        gc[i].insert(0);

        for (int c: gc[i]) {

            p2id[P(i, c)] = co;

            co++;

        }

    }



    struct Edge {

        int to, dist;

    };

    Graph<Edge> gdist(co);

    for (int i = 0; i < n; i++) {

        for (P p: g[i]) {

            int j = p.first;

            int c = p.second;

            int mid = p2id[P(i, c)];

            int yid = p2id[P(j, c)];

            gdist[mid].push_back(Edge{yid, 0});

        }

        for (int c: gc[i]) {

            if (c == 0) continue;

            int mid = p2id[P(i, c)];

            int yid = p2id[P(i, 0)];

            gdist[mid].push_back(Edge{yid, 0});

            gdist[yid].push_back(Edge{mid, 1});

        }

    }

    Dijkstra<int, TEN(9)> djk(gdist, p2id[P(0, 0)]);

    int sid = p2id[P(0, 0)];

    int tid = p2id[P(n-1, 0)];

    int ans = Dijkstra<int, TEN(9)>(gdist, sid).res[tid];

    if (ans == TEN(9)) ans = -1;

    printf("%d\n", ans);

    return 0;

}