#include"stdc++.h"

#define mod 1000000007

#define maxn 100005

using namespace std;



int fac[maxn], n, m, sn, ifac[maxn], inv[maxn], f[21][maxn], ans, a[21], digit[maxn];

int C(int u, int v){

    if(u < v) return 0;

    return 1ll * fac[u] * ifac[v] % mod * ifac[u - v] % mod; 

}

int main()

{

    //freopen(".in","r",stdin);

    //freopen(".out","w",stdout);

    cin >> n; cin >> m; sn = 1 << n;

    fac[0] = 1; inv[0] = 1; ifac[0] = 1;

    for(int i = 1; i <= sn; i++) {

        fac[i] = 1ll * fac[i - 1] * i % mod;

        inv[i] = (i == 1) ? 1 : 1ll * inv[mod % i] * (mod - mod / i) % mod;

        ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod; 

    }

    for(int i = 1; i <= m; i++) cin >> a[i];

    sort(a + 1, a + m + 1);

    f[m + 1][0] = 1;

    for(int i = m; i >= 1; i--)

        for(int j = 0; j < sn; j++){

            (f[i][j] += f[i + 1][j]) %= mod;

            for(int k = 0; k < n; k++){

                if(j & (1 << k)) continue;

                int p = sn - j - a[i];

                (f[i][j + (1 << k)] += 1ll * f[i + 1][j] * C(p, (1 << k) - 1) % mod * fac[1 << k] % mod) %= mod;

            }

        }

    for(int i = 0; i < sn; i++) {

        digit[i] = digit[i >> 1] + (i & 1);

        f[1][i] = 1ll * f[1][i] * fac[sn - i - 1] % mod;

        if(digit[i] % 2 == 0) ans = (ans + f[1][i]) % mod;

        else ans = (ans + mod - f[1][i]) % mod;

    }

    cout << 1ll * ans * sn % mod<< endl;

    return 0;

}