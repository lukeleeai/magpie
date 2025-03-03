#include <cstdio>

#include <algorithm>



using namespace std;

typedef long long ll;



int N;

ll A[200001];

ll acc[200002];



int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        scanf("%lld", &A[i]);

    }

    for (int i = 0; i < N; i++) {

        acc[i + 1] = acc[i] + A[i];

    }

    ll ans = 1LL << 62;

    int i = 1, k = 3;

    for(int j = 2; j < N - 1; j++) {

        while(i + 1 < j) {

            ll newarea = acc[i + 1] - acc[0];

            ll area = acc[i] - acc[0];

            if (abs(newarea - (acc[j] - newarea)) > abs(area - (acc[j] - area))) break;

            i++;

        }

        while(k + 1 < N) {

            ll newarea = acc[k + 1] - acc[j];

            ll area = acc[k] - acc[j];

            if (abs(newarea - (acc[N] - acc[j] - newarea)) > abs(area - (acc[N] - acc[j] - area))) break;

            k++;

        }

        ll mi = min(min(acc[i], acc[j] - acc[i]), min(acc[k] - acc[j], acc[N] - acc[k]));

        ll ma = max(max(acc[i], acc[j] - acc[i]), max(acc[k] - acc[j], acc[N] - acc[k]));        

        ans = min(ans, ma - mi);

    }

    printf("%lld\n", ans);

    return 0;

}
