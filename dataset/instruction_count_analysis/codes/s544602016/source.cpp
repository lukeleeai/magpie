#include "stdc++.h"



using namespace std;

using ll = long long;

using pii = pair<int, int>;



int c[3][3];



int main() {

  cin.tie(0);

  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {

      cin >> c[i][j];

    }

  }  



  for (int i = 0; i <= 100; i++) {

    for (int j = 0; j <= 100; j++) {

      for (int k = 0; k <= 100; k++) {

        bool ok = true;

        for (int l = 0; l < 3; l++) {

          int x = c[0][l] - i;

          int y = c[1][l] - j;

          int z = c[2][l] - k;

          ok &= (x == y && y == z);

        }

        if (ok) {

          cout << "Yes" << endl;

          return 0;

        }

      }

    }

  }

  cout << "No" << endl;



  return 0;

}