/*

 　　　　　／＞　 フ

 　　　　　| 　_　 _|

 　 　　　／`ミ _x 彡

 　　 　 /　　　 　 |

 　　　 /　  ヽ　　 ?

 　／￣|　　 |　|　|

 　| (￣ヽ＿_ヽ_)_)

 　＼二つ

  */



#include <queue>

#include <vector>

#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#define MP make_pair

#define ll long long

#define fi first

#define se second

using namespace std;



template <typename T>

void read(T &x) {

    x = 0; bool f = 0;

    char c = getchar();

    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;

    for (;isdigit(c);c=getchar()) x=x*10+(c^48);

    if (f) x=-x;

}



template<typename F>

inline void write(F x, char ed = '\n') {

    static short st[30];short tp=0;

    if(x<0) putchar('-'),x=-x;

    do st[++tp]=x%10,x/=10; while(x);

    while(tp) putchar('0'|st[tp--]);

    putchar(ed);

}



template <typename T>

inline void Mx(T &x, T y) { x < y && (x = y); }



template <typename T>

inline void Mn(T &x, T y) { x > y && (x = y); }



const int N = 605000;

const int P = 924844033;

ll inv[N], fac[N], E[N]; int f[N], g[N], lim = 1, r[N];

int siz[N], cnt[N], h[N], ne[N<<1], to[N<<1], tot, m, n;

inline void adde(int x, int y) {

    ne[++tot] = h[x], to[h[x] = tot] = y;

}

void dfs(int x, int fa) {

    siz[x] = 1;

    for (int i = h[x]; i; i = ne[i]) {

        int y = to[i]; if (y == fa) continue;

        dfs(y, x), siz[x] += siz[y], cnt[siz[y]]++, cnt[n - siz[y]]++;

    }

}

ll fpw(ll x, ll mi) {

    ll res = 1;

    for (; mi; mi >>= 1, x = x * x % P)

        if (mi & 1) res = res * x % P;

    return res;

}



inline int add(int x, int y) { return x + y >= P ? x + y - P : x + y;  }



void dft(int *A) {

    for (int i = 0;i < lim; i++)

        if (r[i] > i) swap(A[i], A[r[i]]);

    for (int i = 1;i < lim; i <<= 1) {

        for (int j = 0;j < lim; j += (i << 1)) {

            ll *e = E + i; int *f = A + j, *g = f + i;

            for (int k = 0;k < i; k++) {

                int x = f[k], y = e[k] * g[k] % P;

                f[k] = add(x, y), g[k] = add(x, P - y);

            }

        }

    }

}



void idft(int *A) { 

    dft(A); ll inv = fpw(lim, P - 2);

    for (int i = 0;i < lim; i++) A[i] = 1ll * A[i] * inv % P;

    reverse(A + 1, A + lim);

}



inline ll C(ll n, ll m) { return fac[n] * inv[m] % P * inv[n-m] % P; }

int main() {

    read(n);

    for (int i = 1, x, y;i < n; i++) 

        read(x), read(y), adde(x, y), adde(y, x);

    dfs(1, 0), fac[0] = fac[1] = inv[0] = inv[1] = 1, cnt[0] = 0;

    /* for (int i = 1;i <= n; i++) write(cnt[i]); */

    for (int i = 2;i <= n; i++) fac[i] = fac[i-1] * i % P;

    inv[n] = fpw(fac[n], P - 2);

    for (int i = n - 1;i >= 1; i--) inv[i] = inv[i+1] * (i + 1) % P;

    /* for (int i = 1;i <= n; i++) write(cnt[n-i], ' '); */

    for (int i = 1;i < n; i++) f[i] = 1ll * cnt[n-i] * fac[n-i] % P;

    for (int i = 0;i <= n; i++) g[i] = inv[i] % P;

    /* for (int i = 1;i <= n; i++) write(f[i], ' '), write(g[i]); */

    while (lim <= n + n) lim <<= 1;

    int len = lim >> 1;

    for (int i = 1;i <= lim; i++) r[i] = (r[i>>1]>>1) | ((i & 1) ? len : 0);

    E[1] = 1;

    for (int i = 2;i < lim; i <<= 1) {

        ll *e0 = E + (i >> 1), *e1 = E + i, w = fpw(5, (P - 1) / (i << 1));

        for (int j = 0;j < i; j += 2)

            e1[j] = e0[j>>1], e1[j + 1] = e1[j] * w % P;

    }

    dft(f), dft(g);

    /* for (int i = 0;i < lim; i++) write(f[i], ' '), write(g[i]); */

    /* puts(""); */

    for (int i = 0;i < lim; i++) f[i] = 1ll * f[i] * g[i] % P;

    /* for (int i = 0;i < lim; i++) write(f[i]); */

    idft(f);

    for (int i = 1;i <= n; i++) write((C(n, i) * n % P + (P - inv[i]) * f[n-i]) % P);

    return 0;

}