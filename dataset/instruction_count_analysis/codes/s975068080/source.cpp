#include <cstdio>

#include <cstdlib>

#include <cstring>

 

#define siz 10000000

 

char buf[siz], *bit = buf;

 

inline int nextInt(void) {

    register int ret = 0;

    register int neg = false;

 

    for (; *bit < '0'; ++bit)

        if (*bit == '-')neg ^= true;

 

    for (; *bit >= '0'; ++bit)

        ret = ret * 10 + *bit - '0';

 

    return neg ? -ret : ret;

}

 

#define inf 2147483647

 

int n, m;

 

int tag[400005];

 

int find(int t, int l, int r, int p) {

    if (~tag[t])

        return tag[t];

    int mid = (l + r) >> 1;

    if (p <= mid)

        return find(t << 1, l, mid, p);

    else

        return find(t << 1 | 1, mid + 1, r, p);

}

 

void update(int t, int l, int r, int x, int y, int k) {

    if (l == x && r == y)

        tag[t] = k;

    else {

        int mid = (l + r) >> 1;

        if (~tag[t])

            tag[t << 1] = tag[t << 1 | 1] = tag[t], tag[t] = -1;

        if (y <= mid)

            update(t << 1, l, mid, x, y, k);

        else if (x > mid)

            update(t << 1 | 1, mid + 1, r, x, y, k);

        else {

            update(t << 1, l, mid, x, mid, k);

            update(t << 1 | 1, mid + 1, r, mid + 1, y, k);

        }

    }

}

 

signed main(void) {

    fread(buf, 1, siz, stdin);

 

    n = nextInt();

    m = nextInt();

 

    for (int i = 0; i < (n << 2); ++i)

        tag[i] = inf;

 

    for (int i = 1; i <= m; ++i) {

        int c = nextInt();

        if (c)  // find(x)

            printf("%d\n", find(1, 1, n, nextInt() + 1));

        else {

            int x = nextInt();

            int y = nextInt();

            int k = nextInt();

            update(1, 1, n, x + 1, y + 1, k);

        }

    }

 

    //system("pause");

}
