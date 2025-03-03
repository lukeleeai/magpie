#include "stdc++.h"

using namespace std;



int main() {

  int64_t b;



  while (cin >> b, b) {

    for (int64_t d = sqrt(2 * b); d > 0; --d) {

      int64_t a = (2 * b + d - d * d) / (2 * d);

      if (a <= 0 || b < a) continue;

      if ((a + d) * (a + d - 1) - a * (a - 1) == 2 * b) {

        cout << a << " " << d << endl;

        break;

      }

    }

  }

}


