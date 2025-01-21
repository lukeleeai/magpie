#include "stdc++.h"



using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int s;

  cin >> s;



  set<int> c;

  while (c.count(s) == 0) {

    c.insert(s);

    if (s % 2 == 0)

      s /= 2;

    else

      s = 3 * s + 1;

  }

  cout << c.size() + 1 << '\n';

  return 0;

}
