#include "stdc++.h"



using namespace std;



const int maxn = 1e5 + 5;



struct Edges

{

    int v, next;

} e[maxn << 1];

int h[maxn], mem;

int dep[maxn];

bool vis[maxn];

bool du[maxn];

int ansx[maxn], ansy[maxn], top;

bool sum[maxn];

void pre()

{

    memset(h, -1, sizeof(h));

    mem = 0;

    top = 0;

    memset(vis, 0, sizeof(vis));

    memset(du, 0, sizeof(du));

    memset(sum, 0, sizeof(sum));

}



void add( int u, int v )

{

    e[mem].v = v;

    e[mem].next = h[u];

    h[u] = mem++;

}



void dfs(int u, int f)

{

    vis[u] = 1;

    dep[u] = dep[f] + 1;

    for(int i=h[u]; i+1; i=e[i].next)

    {

        int v = e[i].v;

        if(v==f) continue;

        if(vis[v]){

            if(dep[u]<dep[v]||(dep[u]==dep[v]&&u<v))

            {

                du[u] ^= 1;

                ansx[top] = u;

                ansy[top++] = v;

            }

            continue;

        }

        du[u]^=1;

        dfs(v, u);

    }

}



vector<int> last;







void change(int u, int v)

{

    du[u] ^= 1;

    du[v] ^= 1;

}



bool dfsans(int u, int f)

{

    vis[u] = 1;

    //printf("dfsans %d %d\n", u, f);

    bool now=du[u];

    for(int i=h[u]; i+1; i=e[i].next)

    {

        int v = e[i].v;

        if(v==f) continue;

        if(vis[v]) continue;

        bool flag = dfsans(v, u);

        if(flag){

            ansx[top] = v;

            ansy[top] = u;

        }

        else{

            ansx[top] = u;

            ansy[top] = v;

        }

        top++;

        now ^= flag;

    }

    return now;

}



int main()

{

    int n, m;

    scanf( "%d%d", &n, &m );

    pre();

    for( int i = 1; i <= m; i++ )

    {

        int u, v;

        scanf("%d%d", &u, &v);

        add(u, v);

        add(v, u);

    }

    if(m&1){

        printf("-1\n");

        return 0;

    }

    dep[1] = 1;

    dfs(1, 1);

    last.clear();

    for(int i=1; i <= n; i++)

    {

        if(du[i]){

            last.push_back(i);

        }

    }

    memset(du, 0, sizeof(du));

    memset(vis, 0, sizeof(vis));

    int l = last.size();

    for(int i=0; i < l / 2; i++)

    {

        change(last[i], last[l-1-i]);

    }

    dfsans(1, 1);

    for(int i=0; i<top; i++)

    {

        printf("%d %d\n", ansx[i], ansy[i]);

    }

    //printf("%d\n", top);

    return 0;

}
