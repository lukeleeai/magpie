#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <queue>

#define REP(i, n) for (int i = 0; i < (n); i++) 



using namespace std;



using ll = long long;

template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

template<class T> using maxheap = priority_queue<T, vector<T>, less<T>>;



int main() {

  cin.tie(nullptr);

  ios::sync_with_stdio(false);

  int Q;

  cin >> Q;

  maxheap<ll> L;

  minheap<ll> R;

  ll ans = 0;

  while (Q--) {

    int type;

    cin >> type;

    if (type == 1) {

      ll a, b;

      cin >> a >> b;

      ans += b;

      L.push(a);

      R.push(a);

      if (L.top() > R.top()) {

        ll l = L.top(); L.pop();

        ll r = R.top(); R.pop();

        ans += l - r;

        L.push(r);

        R.push(l);

      }

    } else {

      cout << L.top() << ' ' << ans << '\n';

    }

  }

}
