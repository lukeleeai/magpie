#include <cstdio>

#include <algorithm>



typedef long long ll;



using namespace std;



int main() {

    ll n, x, cnt = 0, prev = 0, now;

    scanf("%lld%lld", &n, &x);

    for (ll i = 0; i < n; ++i) {

        scanf("%lld", &now);

        prev = now - max(prev + now - x, 0LL);

        cnt += now - prev;

    }

    printf("%lld\n", cnt);

    return 0;

}
