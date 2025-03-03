#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;



ll n, m, p[1000], d[600000];



int main() {

  while (scanf("%lld%lld", &n, &m), n) {

    for (ll i = 0; i < n; i++) scanf("%lld", &p[i]);

    ll counter = 0;

    for (ll i = 0; i < n; i++) for (ll j = 0; j <= i; j++) d[counter++] = p[i] + p[j];

    for (ll i = 0; i < n; i++) d[counter++] = p[i];

    sort(d, d + counter);

    ll ans = 0;

    for (ll i = 0, j = counter - 1; i < counter; i++) {

      while (d[i] + d[j] > m) j--;

      if (i > j) break;

      if (ans < d[i] + d[j]) ans = d[i] + d[j];

    }

    printf("%lld\n", ans);

  }

}


