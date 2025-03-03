#include <cstdio>

#include <memory.h>

#include <vector>

using namespace std;

const int maxn = 200005;

struct Query{

    int v, d, c;

}q[maxn];

int n, m, Q;

vector<int> G[maxn];

bool vis[maxn][15];

int color[maxn];



void solve(int v, int d, int c){

    if(vis[v][d]) return;

    if(color[v] == 0)    color[v] = c;

    if(d <= 0) return;



    for(int i = 0; i < G[v].size(); i++)

    {

        solve(G[v][i], d-1, c);

    }

    vis[v][d] = 1;



}

int main(){

//freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    memset(color, 0, sizeof(color));

    memset(vis, false, sizeof(vis));

    int a, b;

    for(int i = 0; i < m; i++)

    {

        scanf("%d %d", &a, &b);

        G[a].push_back(b);

        G[b].push_back(a);

    }

    scanf("%d", &Q);

    for(int i = 0; i < Q; i++)

    {

        scanf("%d %d %d", &q[i].v, &q[i].d, &q[i].c);

    }

    for(int i = Q-1; i >= 0; i--)

       solve(q[i].v, q[i].d, q[i].c);

    for(int i = 1; i <= n; i++)

        printf("%d\n", color[i]);

    return 0;

}