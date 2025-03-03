#include <cstdio>

#include <algorithm>

using namespace std;

int N;

int a[100005];

int b[100005];

int main() {

    scanf("%d",&N);

    for (int i = 0; i < N+1; i++) {

        scanf("%d",&a[i]);

    }

    for (int i = 0; i < N; i++) {

        scanf("%d",&b[i]);

    }

    long long ans = 0;

    for (int i = 0; i < N+1; i++) {

        if (i == N) {

            if (a[i] <= b[N-1]) {

                ans += a[i];

            } else {

                ans += b[N-1];

            }

            break;

        }



        if (i != 0 && b[i-1] > 0) {

            if (a[i] <= b[i-1]) {

                ans += a[i];

                a[i] = 0;

                b[i-1] -= a[i];



            } else {

                ans += b[i-1];

                a[i] -= b[i-1];

                b[i-1] = 0;

            }

        }

        if (a[i] <= b[i]) {

            b[i] -= a[i];

            ans += a[i];

            a[i] = 0;

        } else {

            a[i] -= b[i];

            ans += b[i];

            b[i] = 0;

        }

    }

    printf("%lld\n", ans);

    return 0;

}
