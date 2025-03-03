#include <cstdio>



int a, b, c, k, ans;



int main() {

    scanf("%d%d%d%d", &a, &b, &c, &k);

    if (a >= k) {

        printf("%d", k);

        return 0;

    }

    ans = a, k -= a;

    if (b >= k) {

        printf("%d", ans);

        return 0;

    }

    k -= b;

    printf("%d", ans - k);

}
