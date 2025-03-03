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

#define fst first

#define snd second

using ll = long long;

using I = pair<int, int>;



int main() {

  int a, b;

  while (cin >> a >> b) {

    int d = b - a;

    int res = -1;

    for (int i = 1; i <= 999; i++) {

      for (int j = 1; j <= 999; j++) {

        int A = i * (i + 1) / 2;

        int B = j * (j + 1) / 2;

        if (A > a && B > b && B - A == d) {

          res = A - a;

        }

      }

    }

    cout << res << endl;

  }

  return 0;

}
