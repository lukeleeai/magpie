#include <iostream>

#include <string.h>

using namespace std;



const int MAXN = 1e6+10;

char s[MAXN];

int a[MAXN],N,M;

struct node {

    int to,next;

}E[MAXN * 10];



int head[MAXN],sumE,sum;

bool vis[MAXN];

void add(int u,int v) {

    E[++sumE].to = v;

    E[sumE].next = head[u];

    head[u] = sumE;

}

#define read(x) scanf("%d",&x)

void Init() {

    scanf("%s",s + 1);

    N = strlen(s + 1);

    s[0] = 'a';s[N + 1] = 'a';

    for(int i = 1 ; i <= N + 1; ++i) a[i] = (s[i] - s[i - 1] + 26) % 26;

    read(M);

    int L,R;

    for(int i = 1 ; i <= M ; ++i) {

    read(L);read(R);

    add(L,R + 1);add(R + 1,L);

    }

    for(int i = 1 ; i <= N + 1 ; ++i) {

    add(i,N + 2 - i),add(N+2-i,i);

    }

}

void dfs(int u) {

    vis[u] = 1;

    sum = (sum + a[u]) % 26;

    for(int i = head[u] ; i ; i = E[i].next) {

    int v = E[i].to;

    if(!vis[v]) {

        dfs(v);

    }

    }

}

void Solve() {

    bool flag = 1;

    for(int i = 1 ; i <= N + 1 ; ++i) {

    if(!vis[i]) {

        sum = 0;

        dfs(i);

        if(sum != 0) {flag = 0;break;} 

    }

    }

    if(flag) puts("YES");

    else puts("NO");

}

int main() {

    Init();

    Solve();

    return 0;

}
