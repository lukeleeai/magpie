#include <cstdio>



#define N 2001

#define P 4000001

#define M 1000000007LL



long long p[2][P], f[N][N];

int n, k, t;



long long sel(int n, int m)

{

    return n >= m ? p[0][n] * p[1][m] % M * p[1][n - m] % M : 0;

}



int main()

{

    scanf("%d%d", &n, &k);

    t = n * k;



    if (k == 1)

    {

        puts("1");

        return 0;

    }



    p[0][0] = 1;

    for (int i = 1; i <= t; i++)

        p[0][i] = p[0][i - 1] * i % M;



    p[1][t] = 1;

    for (long long x = p[0][t], e = M - 2; e; e >>= 1, x = x * x % M)

        if (e & 1)

            p[1][t] = p[1][t] * x % M;



    for (int i = t; i; i--)

        p[1][i - 1] = p[1][i] * i % M;



    f[0][0] = 1;

    for (int i = 0; i <= n; i++)

    {

        for (int j = i; j <= n; j++)

        {

            f[i][j + 1] = (f[i][j + 1] + f[i][j]) % M;

            f[i + 1][j] = (f[i + 1][j] + f[i][j] * sel(t - i * (k - 1) - j - 1, k - 2) % M) % M;

        }

    }



    printf("%lld\n", f[n][n] * p[0][n] % M);

    return 0;

}
