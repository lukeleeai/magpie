#include <cstdio>

#include <ctype.h>

#include <cmath>

#include <algorithm>



using namespace std;



char *p1, *p2, buf[1 << 20];



inline char gc()

{

    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++;

}



template<typename T>

void rd(T &num)

{

    char tt;

    bool flag = 0;

    while (!isdigit(tt = gc()) && tt != '-');

    if (tt == '-')

        num = 0, flag = 1;

    else

        num = tt - '0';

    while (isdigit(tt = gc()))

        num = num * 10 + tt - '0';

    if (flag)

        num = -num;

    return;

}



const int _N = 1e5 + 10;



int E, N, M;

int Nx[_N * 2], V[_N * 2], Fs[_N], Dfn[_N], Low[_N], ID[_N];



void ins(int a, int b)

{

    Nx[++E] = Fs[a], Fs[a] = E, V[E] = b;

    return;

}



bool dfs(int p, int clr, int *cnt)

{

    bool suc = 1;

    ID[p] = clr, ++cnt[clr];

    for (int i = Fs[p]; i; i = Nx[i]) {

        if (i & 1)

            ++cnt[3];

        int t = V[i], c = (clr + ((i & 1) ? 1 : 2)) % 3;

        if (ID[t] != -1) {

            if (ID[t] != c)

                suc = 0;

        } else {

            if (!dfs(t, c, cnt))

                suc = 0;

        }

    }

    return suc;

}



long long ss(int x)

{

    return 1ll * x * x;

}



int main()

{

    rd(N), rd(M);

    for (int a, b, i = 1; i <= M; ++i) {

        rd(a), rd(b);

        ins(a, b), ins(b, a);

    }

    for (int i = 1; i <= N; ++i)

        ID[i] = -1;

    long long ans = 0;

    for (int i = 1; i <= N; ++i) {

        if (ID[i] != -1)

            continue;

        int cnt[4];

        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;

        if (dfs(i, 0, cnt)) {

            if (cnt[0] && cnt[1] && cnt[2])

                ans += 1ll * cnt[0] * cnt[1] + 1ll * cnt[1] * cnt[2] + 1ll * cnt[2] * cnt[0];

            else

                ans += cnt[3];

        } else {

            ans += ss(cnt[0] + cnt[1] + cnt[2]);

        }

    }

    printf("%lld\n", ans);

    return 0;

}