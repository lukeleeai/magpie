#include <iostream>

#include <stdio.h>

#include <vector>

#define lld long long

 

using namespace std;

 

const lld MODULO = 1e9 + 7;

const int N = 2e5 + 5;

int n, m, t;

lld d[N], s[N], k[N], res;

vector <lld> F[N];

lld gcd, x, y;

 

void gener() {

    for (int i = 1; i <= max(m, n); i++) {

        k[i] = (k[i - 1] + (i - 1)) % MODULO;

        d[i] = (k[i] + d[i - 1]) % MODULO;

        s[i] = (s[i - 1] + k[i] * 2) % MODULO;

    }

}

 

void Clear() {

    for (int i = 0; i <= n; i++)

        for (int j = 0; j <= m; j++)

            F[i].push_back(0);

    for (int i = 1; i <= m; i++)

        F[1][i] = d[i];

    for (int i = 1; i <= n; i++)

        F[i][1] = d[i];

}

 

void print() {

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= m; j++)

            cout << F[i][j] << ' ';

        cout << '\n';

    }

}

 

void prepa() {

    gener();

    Clear();

    for (int i = 2; i <= n; i++)

        for (int j = 2; j <= m; j++) {

            lld temp = ((d[i] * j * j) % MODULO + (s[j] * k[i]) % MODULO + (d[j] * i) % MODULO) % MODULO;

            F[i][j] = temp;

        }

}

 

void extendedEuclid(lld A, lld B)

{

    if (B == 0)

    {

        gcd = A;

        x = 1;

        y = 0;

    }

    else

    {

        extendedEuclid(B, A%B);

        lld temp = x;

        x = y;

        y = temp - (A/B)*y;

    }

}

 

void solve()

{

    int q = t - 2;

    int p = n * m - 2;

    lld ngt = 1, n_k = 1, kgt = 1;

    for (int i = 1; i <= p; i++)

        ngt = (ngt * i) % MODULO;

    for (int i = 1; i <= q; i++)

        kgt = (kgt * i) % MODULO;

    for (int i = 1; i <= p - q; i++)

        n_k = (n_k * i) % MODULO;

    extendedEuclid(kgt, MODULO); kgt = x;

    extendedEuclid(n_k, MODULO); n_k = x;

    kgt = (kgt % MODULO + MODULO) % MODULO;

    n_k = (n_k % MODULO + MODULO) % MODULO;

    res = ((ngt * kgt % MODULO) * n_k % MODULO) * F[n][m] % MODULO;

    printf("%lld", res);

}

 

int main()

{

    //freopen("a.inp", "r", stdin);

    scanf("%d%d%d", &n, &m, &t);

        prepa();

        solve();

    return 0;

}