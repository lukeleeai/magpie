#include "stdc++.h"

using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  string s; cin >> s;

  int a = 0;

  for (int i = 0; i < (int)s.size(); i++) {

    a = i;

    if (s[i] == 'A') break;

  }

  int n = (int)s.size();

  int z = n - 1;

  for (int i = n - 1; i >= 0; i--) {

    z = i;

    if (s[i] == 'Z') break;

  }

  cout << z - a + 1 << endl;

  return 0;

}
