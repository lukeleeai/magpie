#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;

using P = pair<int, int>;



int main() {

  ll x;

  cin >> x;

  for (int i = -118; i < 120; i++) {

    for (int j = -119; j < 119; j++)

      if (pow(i, 5) - pow(j, 5) == x) {

        printf("%d %d\n", i, j);

        return 0;

      }

  }

  return 0;

}