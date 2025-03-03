#include "stdc++.h"

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)

#define REP(i,n)    FOR(i,0,n)

#define ALL(x)      begin(x),end(x)



using namespace std;

using vecint = vector<int>;

using ll = int64_t;



using Data = int;

const int len = 1 << 18;



struct BIT {

  vector<Data> data;

  BIT() : data(len, 0) {}

  void update(int i, Data value) {

    for (; i < len; i |= i+1) data[i] += value;

  }

  Data query(int i) {

    Data s = 0;

    for (; i >= 0; i = (i&i+1)-1) s += data[i];

    return s;

  }

};



bool ok(const vecint& a, const int th) {

  ll n = a.size();

  BIT bit;

  int offset = n;

  ll cnt = 0;

  REP(i,n) {

    bit.update(offset, 1);

    if (a[i] >= th) {

      offset -= 1;

    } else {

      offset += 1;

    }

    cnt += bit.query(offset-1);

  }

  ll m = n * (n+1) / 2;

  ll mid = m/2 + 1;

  return cnt >= mid;

}



int main()

{

  int n;

  cin>>n;

  vecint a(n);

  REP(i,n) cin>>a[i];

  vecint b = a;

  b.push_back(0);

  b.push_back(1000000007);

  sort(ALL(b));

  b.erase(unique(ALL(b)), end(b));

  int hi = b.size()-1;

  int lo = 0;

  while ((hi - lo) > 1) {

    int mid = (hi + lo) / 2;

    if (ok(a, b[mid])) {

      hi = mid;

    } else {

      lo = mid;

    }

  }

  cout << b[lo] << endl;

  return 0;

}
