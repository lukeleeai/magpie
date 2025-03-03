#include <cstdio>

#include <cstdlib>

 

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

 

int n, m;

 

int pre[100005];

 

inline int ask(int p) {

    int ret = 0;

    for (; p; p -= p&-p)

        ret += pre[p];

    return ret;

}

 

inline void add(int p, int k) {

    for (; p <= n; p += p&-p)

        pre[p] += k;

}

 

signed main(void) {

    fread(buf, 1, siz, stdin);

 

    n = nextInt();

    m = nextInt();

 

    for (int i = 1; i <= m; ++i) {

        int c = nextInt();

        if (c)  // get(i)

            printf("%d\n", ask(nextInt()));

        else    // add(s, t, x)

        {

            int x = nextInt();

            int y = nextInt();

            int k = nextInt();

            add(x, k); add(y + 1, -k);

        }

    }

 

    //system("pause");

}
