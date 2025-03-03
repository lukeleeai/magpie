#include <cstdio>

#include <algorithm>

using namespace std;



typedef long long ll;



const int maxn =  1e5 + 5;



int n, E, T, pos;

int a[maxn];

ll f[maxn], mn = 1e18;



int main()

{

    scanf("%d%d%d", &n, &E, &T);

    for(int i = 1; i <= n; i++)

        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++)

    {

        while(T < 2 * (a[i] - a[pos + 1]))

        {

            mn = min(mn, f[pos] - 2 * a[pos + 1]);

            pos++;

        }

        f[i] = min(f[i - 1] + T, mn + 2 * a[i]);

        f[i] = min(f[pos] + T, f[i]);

    }

    printf("%lld\n", f[n] + E);

    return 0;

}