#include "stdc++.h"

using namespace std;



int main() {

  int a = 0, b, c = 0, d, e;

  string f;

  cin >> b;

  vector<string> g(b);

  while (c < b) cin >> g.at(c++);

  for (cin >> d; cin >> f; g.push_back(f));

  while (c--) {

    for (d = 0, e = g.size(); e--;) {

      if (g.at(c) == g.at(e)) if (e < b) d++;

      else d--;

    }

    if (d > a) a = d;

  }

  cout << a;

}