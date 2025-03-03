#pragma GCC optimize(3)

#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<cstring>

#include<string>

#include<algorithm>

#include<vector>

#include<map>

#include<set>

#include<list>

#include<queue>

#include<stack>

#include<bitset>

#include<deque>

using namespace std;

#define ll long long

// #define inf 0x3f3f3f3f

#define ri register int

#define il inline

#define fi first

#define se second

#define mp make_pair

#define pi pair<int,int>

#define mem0(x) memset((x),0,sizeof (x))

#define mem1(x) memset((x),0x3f,sizeof (x))

il char gc()

{

    static const int BS = 1 << 22;

    static unsigned char buf[BS], *st, *ed;

    if (st == ed) ed = buf + fread(st = buf, 1, BS, stdin);

    return st == ed ? EOF : *st++;

}

#define gc getchar

template<class T>void in(T &x)

{

    x = 0;

    bool f = 0;

    char c = gc();

    while (c < '0' || c > '9')

    {

        if (c == '-') f = 1;

        c = gc();

    }

    while ('0' <= c && c <= '9')

    {

        x = (x << 3) + (x << 1) + (c ^ 48);

        c = gc();

    }

    if (f) x = -x;

}

#undef gc

#define pb push_back

#define N 100010

#define M N<<1

int n, m;

int v[M], nx[M];

int cnt, head[N];

il void add(int uu, int vv)

{

    v[++cnt] = vv, nx[cnt] = head[uu];

    head[uu] = cnt;

}

int col[N];

bool ok = 1;

int sz;

void dfs(int x)

{

    if (col[x] == 2) ++sz;

    for (ri i = head[x]; i; i = nx[i])

    {

        if (col[v[i]])

        {

            if (col[v[i]] == col[x])

            {

                ok = 0;

                return;

            }

        }

        else

        {

            col[v[i]] = col[x] ^ 1;

            dfs(v[i]);

        }

    }

}

signed main()

{

#ifndef ONLINE_JUDGE

    //freopen("in.in", "r", stdin);

#endif

    in(n), in(m);

    for (ri i = 1, a, b; i <= m; ++i)

    {

        in(a), in(b);

        add(a, b);

        add(b, a);

    }

    col[1] = 2;

    dfs(1);

    if (ok == 0)

    {

        printf("%lld", (ll)n * (n - 1) / 2 - m);

    }

    else

    {

        printf("%lld", (ll)sz * (n - sz) - m);

    }

    return 0;

}