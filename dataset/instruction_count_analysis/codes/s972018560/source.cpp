#include "bits/stdc++.h"

using namespace std;

typedef pair<int,int> pii;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define all(a)  (a).begin(),(a).end()

#define pb push_back

#define INF 1<<30

#define MAX_V 200



struct edge{int to,cap,rev;};



vector<edge> G[10000];

bool used[10000];

void add_edge(int from,int to,int cap){

    G[from].pb((edge){to,cap,(int)G[to].size()});

    G[to].pb((edge){from,0,(int)(G[from].size())-1});

}



// ?¢?????????????DFS??§??¢???

int dfs(int v, int t, int f) {

    if (v == t) return f;

    used[v] = true;

    for (int i = 0; i < G[v].size(); i++) {

        edge &e = G[v][i];

        if (!used[e.to] && e.cap > 0) {

            int d = dfs(e.to, t, min(f, e.cap)); if (d > 0) {

                e.cap -= d;

                G[e.to][e.rev].cap += d;

                return d;

            }

        }

    }

    return 0;

}

// s??????t???????????§???????±???????

int max_flow(int s, int t) {

    int flow = 0; for (;;) {

        memset(used, 0, sizeof(used)); int f = dfs(s, t, INF);

        if (f == 0) return flow;

        flow += f;

    }

}



int main(){

    int v,e;

    cin>>v>>e;

    rep(i,e){

        int uu,vv,cc;

        cin>>uu>>vv>>cc;

        add_edge(uu,vv,cc);

    }

    cout<<max_flow(0,v-1)<<endl;

}