#include <stdio.h>

#include <algorithm>

#include <string.h>

using namespace std;

typedef long long LL;

#define N 100005

LL a[N];



int main()

{

    int n, cnt = 0;

    LL ans = 1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)

        scanf("%lld", &a[i]);

    sort(a + 1, a + 1 + n);

    for (int i = n; i > 0; i--)

    {

        if (cnt == 2) break;

        if (a[i - 1] == a[i])

        {

            ans *= a[i];

            i--;

            cnt++;

        }

    }

    if (cnt == 2)

        printf("%lld\n", ans);

    else

        printf("0\n");



    return 0;

}
