#include "stdc++.h"

typedef long long ll;

using namespace std;



const int N = 100005;

ll n, C, x[N], v[N], pre[N], ans, p, q, ans1, ans2;

ll a[N], b[N], L[N], R[N];



int main() {

    scanf("%lld%lld", &n, &C);

    // 1

    for (int i = 1; i <= n; i++) {

        scanf("%lld%lld", &x[i], &v[i]);

        pre[i] = pre[i - 1] + v[i];

    }

    for (int i = 1; i <= n; i++) {

        ll tmp = pre[i] - x[i];

        a[i] = tmp;

        ans1 = max(ans1, tmp);

    }

    ans = max(ans, ans1);



    // 2

    for (int i = 1; i <= n; i++) pre[i] = v[i];

    for (int i = n; i >= 1; i--) pre[i] += pre[i + 1];

    for (int i = n; i >= 1; i--) {

        ll tmp = pre[i] - (C - x[i]);

        b[i] = tmp;

        ans2 = max(ans2, tmp);

    }

    ans = max(ans, ans2);



    // 3

    for (int i = 1; i <= n; i++) {

        L[i] = max(L[i - 1], a[i] - x[i]);

    }

    for (int i = n; i >= 1; i--) {

        R[i] = max(R[i + 1], b[i]);

    }

    for (int i = 1; i <= n; i++)

        ans = max(ans, L[i] + R[i + 1]);



    // 4

    memset(L, 0, sizeof(L));

    memset(R, 0, sizeof(R));

    for (int i = 1; i <= n; i++) {

        L[i] = max(L[i - 1], a[i]);

    }

    for (int i = n; i >= 1; i--) {

        R[i] = max(R[i + 1], b[i] - (C - x[i]));

    }

    for (int i = 1; i <= n; i++)

        ans = max(ans, L[i] + R[i + 1]);





    printf("%lld\n", ans);

    return 0;

}
