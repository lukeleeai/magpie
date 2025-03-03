#include <cstdio>

#include <algorithm>



typedef long long ll;



using namespace std;



int main() {

    ll n, p = 1, q = 1, t, a, m;

    scanf("%lld", &n);

    for (ll i = 0; i < n; ++i) {

        scanf("%lld%lld", &t, &a);

        m = max((p - 1) / t + 1, (q - 1) / a + 1);

        p = t * m, q = a * m;

    }

    printf("%lld\n", p + q);

    return 0;

}
