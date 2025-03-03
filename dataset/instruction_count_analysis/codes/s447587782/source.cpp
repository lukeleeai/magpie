#include "stdc++.h"



using namespace std;

typedef long long ll;

ll MAX_N = 200005;



int main() {

  ll n;

  ll x[MAX_N], y[MAX_N];

  scanf("%lld", &n);

  for (ll i=0; i<n; i++) {

    scanf("%lld", &x[i]);

    y[i] = x[i];

  }

  sort(y, y+n);

  

  ll m = n/2 - 1;

  for (ll i=0; i<n; i++) {

    if (y[m] < x[i]) {

      printf("%lld\n", y[m]);

    } else {

      printf("%lld\n", y[m+1]);

    }

  }

  

  return 0;

}
