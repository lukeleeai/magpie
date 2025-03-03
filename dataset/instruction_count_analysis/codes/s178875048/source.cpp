#include <cstdio>

#include <vector>

#include <algorithm>

#include <utility>

using namespace std;



struct Edge {

    int to, cost;

};

using Graph = vector< vector<Edge> >;



int dist[100010];



// dist[i] := 頂点 i から最も遠い葉との距離

void dfs(Graph &G, int cur, int par=-1) {

    for(auto e : G[cur]) {

        if(e.to == par) continue;

        dfs(G, e.to, cur);

        dist[cur] = max(dist[cur], dist[e.to] + e.cost);

    }

}



int solve(Graph &G, int root, int d_par, int par=-1) {

    vector< pair<int, int> > children;

    children.push_back(make_pair(0, -1));



    for(auto e : G[root]) {

        if(e.to == par) children.push_back(make_pair(d_par + e.cost, e.to));

        else children.push_back(make_pair(dist[e.to] + e.cost, e.to));

    }

    sort(children.begin(), children.end(), greater< pair<int, int> >());



    int max_cost = children[0].first + children[1].first;

    for(auto e : G[root]) {

        if(e.to == par) continue;

        int nxt_d_par = children[children[0].second == e.to].first;

        max_cost = max(max_cost, solve(G, e.to, nxt_d_par, root));

    }

    return max_cost;

}



int main() {

    int N; scanf("%d", &N);



    Graph G(N);

    for(int i=0; i<N-1; i++) {

        int s, t, w; scanf("%d%d%d", &s, &t, &w);

        G[s].push_back(Edge{t, w});

        G[t].push_back(Edge{s, w});

    }

    dfs(G, 0);

    printf("%d\n", solve(G, 0, 0));

}
