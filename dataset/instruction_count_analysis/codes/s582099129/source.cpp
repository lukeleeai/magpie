#include<cstdio>

#include<cstring>

#include<algorithm>



using namespace std;



const int N = 705;

const int M = 490005;

int n, m, u, v, ans = 0x7fffffff;

bool g[N][N], s[N], t[N];

int col[N], cnt[2];



void dfs(int x, int c){

    col[x] = c;

    cnt[c == 1]++;

    for(int i = 1; i <= n; i++){

        if(i == x || g[x][i])   continue;

        if(!col[i]) dfs(i, -c);

        else if(col[i] == c){

            puts("-1");

            exit(0);

        }

    }

}



int main(){

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++){

        scanf("%d%d", &u, &v);

        g[u][v] = g[v][u] = 1;

    }

    s[0] = 1;

    for(int i = 1; i <= n; i++){

        if(col[i])  continue;

        cnt[0] = cnt[1] = 0;

        dfs(i, 1);

        memset(t, 0, sizeof t);

        for(int j = 0; j <= n; j++){

            t[j+cnt[0]] |= s[j];

            t[j+cnt[1]] |= s[j];

        }

        for(int j = 0; j <= n; j++)

            s[j] = t[j];

    }

    for(int i = 0; i <= n; i++)

        if(s[i])

            ans = min(ans, i*(i-1)/2 + (n-i)*(n-i-1)/2);

    printf("%d\n", ans);

    return 0;

}