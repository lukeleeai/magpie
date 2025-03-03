#include <iostream>

#include <algorithm>

using namespace std;

int main() {

 

  int n;

  cin >> n;

  int a1[100005] = {};

  int m1 = 0;

  int p1 = 0;

  int a2[100005] = {};

  int m2 = 0;

  int p2 = 0;

  for (int i = 0; i < n; i++) {

    int tmp;

    cin >> tmp;

    if (i % 2 == 0) {

      a1[tmp]++;

      if (a1[tmp] > m1) {

        m1 = a1[tmp];

        p1 = tmp;

      }

    }

    if (i % 2 == 1) {

      a2[tmp]++;

      if (a2[tmp] > m2) {

        m2 = a2[tmp];

        p2 = tmp;

      }

    }

  }

  if (p1 == p2) {

    int M1 = 0;

    int M2 = 0;

    for (int i = 0; i <= 100000; i++) {

      if (i == p1) continue;

      M1 = max(M1, a1[i]);

      M2 = max(M2, a2[i]);

    }

    cout << n - max(m1 + M2, m2 + M1) << endl;

  }

  else {

    cout << n - m1 - m2 << endl;

  }

  return 0;

}