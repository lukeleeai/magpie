#include <iostream>

using namespace std;



#define INF (1 << 30) - 1 + (1 << 30)



int a[262144], n2, lazy[262144];



void lazyeval(int i) {

  if (lazy[i] == INF) return;

  a[i] = lazy[i];

  if (i < n2 - 1) {

    lazy[2 * i + 1] = lazy[2 * i + 2] = lazy[i];

  }

  lazy[i] = INF;

}



int findsingle(int i) {

  int j = i + n2 - 1;

  int val = a[i + n2 - 1];

  if (lazy[j] != INF) val = lazy[j];

  while (j > 0) {

    j = (j - 1) / 2;

    if (lazy[j] != INF) val = lazy[j];

  }



  return val;

}



void updaterange(int s, int t, int i, int l, int r, int x) {

  lazyeval(i);

  // cout << s << " " << t << " " << i << " " << l << " " << r << endl;

  if (s <= l && r <= t) {

    a[i] = x;

    if (i < n2 - 1) {

      lazy[2 * i + 1] = lazy[2 * i + 2] = a[i];

    }

    return;

  }

  if (t <= l || r <= s) return;

  updaterange(s, t, i * 2 + 1, l, (l + r) / 2, x);

  updaterange(s, t, i * 2 + 2, (l + r) / 2, r, x);



  a[i] = min(a[i * 2 + 1], a[i * 2 + 2]);

}



int main() {

  int n, q, com, s, t, x;



  cin >> n >> q;

  n2 = 1;

  while (n > n2) n2 *= 2;

  for (int i = 0; i < n2 * 2; i++) a[i] = lazy[i] = INF;



  for (int i = 0; i < q; i++) {

    cin >> com >> s;

    if (com == 0) {

      cin >> t >> x;

      updaterange(s, t + 1, 0, 0, n2, x);

    } else

      cout << findsingle(s) << endl;

  }

  return 0;

}
