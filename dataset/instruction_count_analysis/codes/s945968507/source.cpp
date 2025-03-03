#include "stdc++.h"

using namespace std;



typedef long long ll;

const int maxn = 200005, maxm = 200005;



inline int gi()

{

    char c = getchar();

    while (c < '0' || c > '9') c = getchar();

    int sum = 0;

    while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();

    return sum;

}



#define pb push_back



int n, m, d[maxn];



struct edge

{

    int to, next,vis;

} e[maxm * 2];

int h[maxn], tot = 1;

int w[maxm], col[maxn], fa[maxn], fe[maxn];

vector<int> vec[maxn];



inline void add(int u, int v)

{

    e[++tot] = (edge) {v, h[u]}; h[u] = tot;

    e[++tot] = (edge) {u, h[v]}; h[v] = tot;

}



void dfs(int u)

{

    for (int i=h[u];i;i=e[i].next) {

	if(!e[i].vis)continue;

	int v=e[i].to;

	if (col[v] == -1) col[v] = 1-col[u] , dfs(v);

    }

}



int main()

{

    n = gi(); m = gi();

    for (int i = 1; i <= n; ++i) d[i] = gi();

    for (int i = 1; i <= m; ++i) add(gi(), gi());

    fill(w + 1, w + m + 1, 1e9);



    d[0] = 2e9;

    for (int u = 1; u <= n; ++u) {

	if(!h[u])return puts("-1"), 0;;

	int p=h[u];

	for(int i=e[p].next;i;i=e[i].next){

	    if(d[e[i].to]<d[e[p].to])p=i;

	    else if(d[e[i].to]==d[e[p].to]&&e[i].to<e[p].to)p=i;

	}

	if (d[e[p].to] > d[u]) return puts("-1"), 0;

	w[p>>1]=d[u];fa[u] = e[p].to;e[p^1].vis=1;

    }

	

    fill(col + 1, col + n + 1, -1);

    for (int i = 1; i <= n; ++i) if (fa[fa[i]] == i && col[i] == -1) col[i] = 0, dfs(i); 

    for (int i = 1; i <= n; ++i) putchar(col[i] == 0 ? 'B' : 'W');

    puts("");

    for (int i = 1; i <= m; ++i) printf("%d\n", w[i]);

	

    return 0;

}
