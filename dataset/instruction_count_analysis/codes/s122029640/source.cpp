#include <algorithm>

#include <cstring>

#include <deque>

#include <functional>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <vector>

using namespace std;

using ll = long long;



int main() {

  const int maxA = 60, maxN = 60;

  int N;

  while (cin >> N) {

    vector<int> a(N), b(N);

    for (int i = 0; i < N; i++) {

      cin >> a[i];

    }

    for (int i = 0; i < N; i++) {

      cin >> b[i];

    }

    bool reachable[maxA][maxA][maxA];

    memset(reachable, false, sizeof(reachable));

    for (int i = 0; i < maxA; i++) {

      for (int j = 0; j < maxA; j++) {

        reachable[0][i][i] = true;

      }

    }

    for (int k = 1; k < maxA; k++) {

      for (int i = 0; i < maxA; i++) {

        for (int j = 0; j < maxA; j++) {

          reachable[k][i][j] =

              reachable[k - 1][i][j] | reachable[k - 1][i % k][j];

        }

      }

    }

    bool ok = true;

    for (int i = 0; i < N; i++) {

      ok &= reachable[maxA - 1][a[i]][b[i]];

    }

    if (!ok) {

      cout << -1 << endl;

      continue;

    }

    bool available[maxN][maxA];

    memset(available, false, sizeof(available));

    for (int i = 0; i < N; i++) {

      available[i][a[i]] = true;

    }

    ll res = 0;

    for (int k = maxA - 1; k >= 1; k--) {

      bool need = false;

      for (int i = 0; i < N; i++) {

        bool found = false;

        for (int a = 0; a < maxA; a++) {

          if (available[i][a] && reachable[k - 1][a][b[i]]) {

            found = true;

            break;

          }

        }

        if (!found) {

          need = true;

          break;

        }

      }

      if (need) {

        res += 1ll << k;

        for (int i = 0; i < N; i++) {

          for (int a = 0; a < k; a++) {

            for (int t = a + k; t < maxA; t += k) {

              available[i][a] |= available[i][t];

            }

          }

        }

      }

    }

    cout << res << endl;

  }

  return 0;

}
