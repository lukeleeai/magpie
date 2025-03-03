#include "stdc++.h"

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)

#define REP(i,n)    FOR(i,0,n)

#define ALL(x)      begin(x),end(x)



using namespace std;

using vecint = vector<int>;

using ll = int64_t;



bool ok(const vecint& a, const int th, vecint& v) {

  ll n = a.size();

  v.assign(n*4, 0);

  int offset = n*2;

  ll cnt = 0;

  ll sum = 0;

  REP(i,n) {

    v[offset] += 1;

    if (a[i] >= th) {

      offset -= 1;

      sum -= v[offset];

    } else {

      sum += v[offset];

      offset += 1;

    }

    cnt += sum;

  }

  ll m = n * (n+1) / 2;

  ll mid = m/2 + 1;

  return cnt >= mid;

}



int main()

{

  int n;

  scanf("%d", &n);

  vecint a(n);

  REP(i,n) scanf("%d", &a[i]);

  int hi = 1000000001;

  int lo = 0;

  vecint v(n*4);

  while ((hi - lo) > 1) {

    int mid = (hi + lo) / 2;

    if (ok(a, mid, v)) {

      hi = mid;

    } else {

      lo = mid;

    }

  }

  printf("%d\n", lo);

  return 0;

}
