#include <iostream>

#define mod 1000000007

#define nmax 1000

using std::cin;

using std::cout;

int n, a, b, c, d;

long long ft[nmax+1], rft[nmax+1], dp[2][nmax+1];

long long qmod(long long x)

{

    return (x < mod) ? x : x - mod;

}

long long power(long long b, long long p)

{

    long long res = 1, a = b;

    for(; p; p >>= 1){

      if(p&1) res = res * a % mod;

      a = a * a % mod;

    }

    return res;

}

long long rverse(long long x)

{

    return power(x, mod - 2);

}

void build()

{

    ft[0] = rft[0] = 1;

    for(int i = 1; i <= n; ++i)

      ft[i] = ft[i - 1] * i % mod;

    rft[n] = rverse(ft[n]);

    for(int i = n - 1; i > 0; --i)

      rft[i] = rft[i + 1] * (i + 1) % mod;

}

long long P(long long x, long long k)

{

    if(x < k) return 0;

    return ft[x] * rft[x - k] % mod;

}

int main()

{

    std::ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    cin >> n >> a >> b >> c >> d;

    build();

    dp[!(a & 1)][0] = 1;

    for(int i = a; i <= b; ++i){

      int o = i & 1;

      long long tmp0 = power(rft[i], c);

      for(int j = n; j >= 0; --j){

        dp[o][j] = dp[!o][j];

        long long tmp = tmp0;

        for(int k = c; k <= d && j + i * k <= n; ++k){

          long long ik = i * k;

          dp[o][j + ik] = qmod(dp[o][j + ik] + dp[!o][j] * P(n - j, ik) % mod * tmp % mod * rft[k] % mod);

          tmp = tmp * rft[i] % mod;

        }

      }

    }

    cout << dp[b & 1][n];

    return 0;

}
