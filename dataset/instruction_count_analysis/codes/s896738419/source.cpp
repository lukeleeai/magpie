#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <queue>

#define REP(i, n) for (int i = 0; i < (n); i++) 



using namespace std;



using ll = long long;



template<class T>

struct BIT {

  vector<T> dat;



  BIT(int n) : dat(n) {}



  void add(int k, T v) {

    for (int i = k + 1; i < dat.size(); i += i & -i) {

      dat[i] += v;

    }

  }



  T sum(int k) {

    T res = 0;

    for (int i = k; i > 0; i -= i & -i) {

      res += dat[i];

    }

    return res;

  }



  T rsum(int k) {

    return sum(dat.size()-1) - sum(k);

  }



  // sum[0..k) >= v

  int lower_bound(T v) {

    if (v == 0) return 0;

    int k = 0;

    for (int i = dat.size() >> 1; i >= 1; i >>= 1) {

      if (dat[k + i] < v) {

        v -= dat[k + i];

        k += i;

      }

    }

    return k + 1;

  }

};



int main() {

  cin.tie(nullptr);

  ios::sync_with_stdio(false);

  int Q;

  cin >> Q;

  vector<int> type(Q);

  vector<ll> A(Q), B(Q);

  vector<ll> C;

  for (int i = 0; i < Q; i++) {

    cin >> type[i];

    if (type[i] == 1) {

      cin >> A[i] >> B[i];

      C.push_back(A[i]);

    }

  }

  sort(C.begin(), C.end());

  C.erase(unique(C.begin(), C.end()), C.end());

  BIT<int> bit0(1 << 18);

  BIT<ll> bit1(1 << 18);

  int n = 0;

  ll sumb = 0;

  for (int i = 0; i < Q; i++) {

    if (type[i] == 1) {

      sumb += B[i];

      int k = lower_bound(C.begin(), C.end(), A[i]) - C.begin();

      bit0.add(k, 1);

      bit1.add(k, A[i]);

      n++;

    } else {

      int k = bit0.lower_bound((n + 1) / 2);

      ll x = C[k - 1];

      ll ans = sumb + (x * bit0.sum(k) - bit1.sum(k)) + (bit1.rsum(k) - x * bit0.rsum(k));

      cout << x << ' ' << ans << '\n';

    }

  }

}
