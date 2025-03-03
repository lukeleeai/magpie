#include <cstdio>

#include <vector>

#include <utility>

#include <algorithm>

using namespace std;



using Graph = vector< vector<int> >;



int step[100010], ans[100010];

void dfs(Graph &G, int cur, int par=-1) {

    vector<int> children;

    for(auto to : G[cur]) {

        if(to == par) continue;

        dfs(G, to, cur);

        step[cur] = max(step[cur], step[to] + 1);

    }

}



void solve(Graph &G, int cur, int d_par, int par=-1) {

    vector< pair<int, int> > children;

    children.push_back(make_pair(0, -1));

    for(auto to : G[cur]) {

        if(to == par) children.push_back(make_pair(d_par + 1, to));

        else children.push_back(make_pair(step[to] + 1, to));

    }

    sort(children.begin(), children.end(), greater< pair<int, int> >());



    ans[cur] = children[0].first;

    for(auto to : G[cur]) {

        if(to == par) continue;

        int nxt_d_par = children[children[0].second == to].first;

        solve(G, to, nxt_d_par, cur);

    }

}



int main() {

    int N; scanf("%d", &N);

    Graph G(N);

    for(int i=0; i<N-1; i++) {

        int a, b; scanf("%d%d", &a, &b);

        a--; b--;

        G[a].push_back(b);

        G[b].push_back(a);

    }

    dfs(G, 0);

    solve(G, 0, 0);

    for(int i=0; i<N; i++) {

        printf("%d\n", 2 * (N-1) - ans[i]);

    }

    return 0;

}
