/**

 * @author yuzining

 * @date 2020/08/17 16:13

 */



#ifdef local

#include "D:\vscode\acm\local.hpp"

#else

#include"stdc++.h"

using namespace std;

#define debug(...) do { } while(false)

void Main();

int main() {

  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  Main();

  return 0;

}

#endif



int64_t Function(int64_t b, int64_t n) {

  if (n < b) return n;

  return Function(b, n / b) + n % b;

}



void Main() {

  int64_t n, s; cin >> n >> s;

  if (n == s) {

    cout << (n + 1) << '\n';

    return;

  }

  for (int64_t b = 2; b <= n / b; b++) {

    if (Function(b, n) == s) {

      cout << b << '\n';

      return;

    }

  }

  if (s > n) {

    cout << "-1\n";

    return;

  }

  int64_t ans = LLONG_MAX;

  for (int64_t x = 1; x <= (n - s) / x; x++) {

    if ((n - s) % x == 0) {

      const int64_t b = (n - s) / x + 1;

      if (Function(b, n) == s) {

        ans = min(ans, b);

      }

    }

  }

  if (ans == LLONG_MAX) {

    ans = -1;

  }

  cout << ans << '\n';

}