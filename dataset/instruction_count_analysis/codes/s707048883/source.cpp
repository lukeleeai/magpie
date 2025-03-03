#include <iostream>



using namespace std;



static int D, N;



int solve();

int ndiv(int x);



int ndiv(int x) {

  int cnt = 0;

  while (true) {

    if (x % 100 == 0) {

      x /= 100;

      cnt++;

    } else {

      break;

    }

  }

  return cnt;

}



int solve() {

  int cnt = 0;

  int x = 1;

  while (true) {

    int nn = ndiv(x);

    if (nn == D) {

      cnt++;

    }

    if (cnt == N) {

      break;

    }

    x++;

  }

  return x;

}



int main() {

  cin >> D >> N;

  cout << solve() << endl;

  return 0;

}
