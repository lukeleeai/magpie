#include <iostream>

#include <stdio.h>

using namespace std;



const int MX = 200005, MOD = 1E9 + 7;



int m, n, k;

long long ans = 0;

long long ngt[MX]; // tinh n giai thua

long long ive[MX]; // tinh nghich dao modulo cua ive[i]

long long kgt[MX]; // tinh nghich dao modulo cua k giai thua (tinh tich nghich dao modolu tu 1 -> k)

long long d[MX];   // tong do "chenh lech" cua (1, 1) -> (1, max(n, m))

long long c[MX];   // mang tong (de hieu :]]] )



void gener()

{

    ngt[0] = kgt[0] = 1;

    ngt[1] = kgt[1] = ive[1] = 1;

    for (int i = 2; i <= m * n; i++)

    {

        ngt[i] = ngt[i - 1] * i % MOD;

        ive[i] = MOD - MOD / i * ive[MOD % i] % MOD;

        kgt[i] = kgt[i - 1] * ive[i] % MOD;

    }

}



void solve()

{

    for (int i = 1; i <= max(m, n); i++)

    {

        c[i] = (c[i - 1] + (i - 1)) % MOD;

        d[i] = (c[i] + d[i - 1]) % MOD;

    }

    ans += d[m] * n % MOD * n % MOD;

    ans += d[n] * m % MOD * m % MOD;

}



int main()

{

    scanf("%d%d%d", &n, &m, &k);

    gener();

    solve();

    cout << ans * ngt[m * n - 2] % MOD * kgt[k - 2] % MOD * kgt[m * n - k] % MOD;

}
