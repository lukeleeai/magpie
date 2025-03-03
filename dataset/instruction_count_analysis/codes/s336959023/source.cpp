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

    int k = d - 1;

    int res = k * (k + 1) / 2 - a;

    cout << res << endl;

  }

  return 0;

}
