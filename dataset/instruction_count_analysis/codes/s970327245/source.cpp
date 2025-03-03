#include<cstdio>

using namespace std;



const int maxn = 405, mod = 998244353;

typedef long long ll;

int inv[maxn];



int fpow(int x, int k)

{

    int res = 1;

    while (k) {

        if (k & 1) res = (ll)res * x % mod;

        k >>= 1; x = (ll)x * x % mod;

    }

    return res;

}



int A[maxn], B[maxn], SA, SB, f[2][maxn][maxn];



int main()

{

    inv[1] = 1;

    for (int i = 2; i < maxn; i++) inv[i] = mod - 1LL * inv[mod % i] * (mod / i) % mod;

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d%d", &A[i], &B[i]), SA += A[i], SB += B[i];

    f[0][0][0] = mod - 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= SA; j++)

            for (int k = 0; k <= SB; k++)

                f[1][j][k] = f[0][j][k];

        int p = 1;

        for (int l = 0; l < B[i]; l++, p = (ll)p * A[i] % mod * inv[l] % mod)

            for (int j = A[i]; j <= SA; j++)

                for (int k = l; k <= SB; k++)

                    f[0][j][k] = (f[0][j][k] + (ll)(mod - f[1][j - A[i]][k - l]) * p) % mod;

    }

    int ans = 0;

    for (int j = 1; j <= SA; j++) {

        int p = 1, q = (ll)SA * inv[j] % mod;

        for (int k = 0; k <= SB; k++, p = (ll)p * k % mod * inv[j] % mod) ans = (ans + (ll)f[0][j][k] * p % mod * q) % mod;

    }

    printf("%d\n", ans);

	

    return 0;

}
