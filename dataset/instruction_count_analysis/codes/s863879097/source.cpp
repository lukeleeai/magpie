#include "stdc++.h"

#define ll long long

#define ls id << 1

#define rs id << 1 | 1

#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))

#define memarray(array, value) memset(array, value, sizeof(array))

#define pb(x) push_back(x)

#define st(x) (1LL << (x))

#define pii pair<int, int>

#define mp(a, b) make_pair((a), (b))

#define Flush fflush(stdout)

using namespace std;

const int N = 200050;

const int inf = 0x3f3f3f3f;

const ll mod = 998244353LL;

clock_t TIME_START, TIME_END;

void program_end()

{

#ifdef ONLINE

    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);

    system("pause");

#endif

}

ll dp[N];

ll a[N];

ll sum[N];

int n;



void solve()

{

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)

        scanf("%lld", &a[i]);

    sum[1] = a[1];

    for (int i = 3; i <= n; i += 2)

        sum[i] = sum[i - 2] + a[i];

    for (int i = 2; i <= n; ++i)

    {

        if (i & 1)

            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);

        else

            dp[i] = max(sum[i - 1], dp[i - 2] + a[i]);

    }

    printf("%lld\n", dp[n]);

}



int main()

{

    TIME_START = clock();

    int Test = 1;

    // cin >> Test;

    while (Test--)

        solve();

    TIME_END = clock();

    program_end();

    return 0;

}