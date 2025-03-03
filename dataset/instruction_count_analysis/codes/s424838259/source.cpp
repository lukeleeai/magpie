#include <cstdio>



typedef long long int ll;



const int MAXN = 1e5 + 5;



int n;

ll ans;

ll A[MAXN], B[MAXN];



int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n + 1; ++i) {

        scanf("%lld", &A[i]);

    }

    for (int i = 1; i <= n; ++i) {

        scanf("%lld", &B[i]);

        if (B[i] <= A[i])

            ans += B[i];

        else if (B[i] <= A[i] + A[i + 1]) {

            ans += B[i];

            A[i + 1] -= (B[i] - A[i]);

        }

        else {

            ans += (A[i] + A[i + 1]);

            A[i + 1] = 0;

        }

    }

    printf("%lld", ans);

    return 0;

}