#include "stdc++.h"



#define fr first

#define sc second

#define mk make_pair

#define pb push_back

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()

#define int long long



using namespace std;



const int N = 25, MASK = 1 << 18, mod = 1e9 + 7;



int n, m, ar[N], dp[N][MASK], fc[MASK], in[MASK], nn, ans;



int binpow (int a, int b)

{

    if (b == 0)

        return 1ll;



    if (b & 1)

        return (a * 1ll * binpow(a, b - 1) % mod);



    int res = binpow(a, b >> 1);



    return (res * 1ll * res % mod);

}

int Calc (int n, int k)

{

    if (n < k)

        return 0ll;



    return fc[n] * 1ll * in[k] % mod * in[n - k] % mod;

}

main()

{

    cin >> n >> m;



    nn = (1 << n);



    fc[0] = in[0] = 1;



    for (int i = 1; i <= nn; i++)

    {

        fc[i] = fc[i - 1] * 1ll * i % mod;

        in[i] = binpow(fc[i], mod - 2);

    }

    for (int i = 1; i <= m; i++)

        cin >> ar[i];



    sort( ar + 1, ar + m + 1, greater <int>() );



    dp[0][0] = 1;



    for (int i = 1; i <= m; i++)

    {



        for (int mask = 0; mask < (1 << n ); mask++)

        {

            int sum = 0;



            for (int j = 0; j < n; j++)

            {

                if (mask & (1 << j))

                    sum += (1 << j);

            }

            dp[i][mask] += dp[i - 1][mask];

            dp[i][mask] %= mod;

            for (int j = 0; j < n; j++)

            {

                if (!(mask & (1 << j)) ) continue;



                dp[i][mask] += ( (dp[i - 1][mask ^ (1 << j) ] * 1ll * fc[ (1 << j) ] ) % mod * 1LL * Calc( nn - ar[i] - sum + (1 << j), (1 << j) - 1 ) ) % mod;

                dp[i][mask] %= mod;

            }

        }

    }

    for (int mask = 0; mask < (1 << n); mask++)

    {

        int res = dp[m][mask], sum = 0;



        if (__builtin_popcount(mask) & 1)

            res = -res + mod;



        for (int i = 0; i < n; i++)

        {

            if (mask & (1 << i)) continue;

            sum += (1 << i);

        }



        ans = ans + res * fc[sum] % mod;



        ans %= mod;

    }

    cout << ans * (1 << n) % mod << endl;

}
