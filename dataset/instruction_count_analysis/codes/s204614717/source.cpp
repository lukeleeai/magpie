#include "stdc++.h"

using namespace std;



int main(void)

{

    int64_t n;

    int a[4];

    pair <int, int> b[4];

    for (int i = 0; i < 4; i++) {

        scanf("%d", &a[i]);

        b[i].first = a[i] << (3 - i);

        b[i].second = i;

    }

    sort(b, b + 4);

    scanf("%lld", &n);

    n *= 4;

    int64_t ans = 0;

    while (n) {

        if (n <= 4 && b[0].second == 3) {

            ans += a[b[1].second];

            n -= 1 << b[1].second;

        }

        else {

            int div = 1 << b[0].second;

            ans += n / div * a[b[0].second];

            n %= div;

        }

    }

    printf("%lld\n", ans);

    return 0;

}
