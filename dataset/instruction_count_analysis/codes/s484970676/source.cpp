#include "stdc++.h"

using namespace std;



int main() {

  vector<string> a(200);

  int b = 0, c, d, e;

  for (cin >> c; c--; cin >> a.at(c));

  for (cin >> c; cin >> a.at(99 + c--););

  for (c = 100; c; c--) {

    d = 0;

    for (e = 200; e; e--) {

      if (a.at(c - 1) != "" && a.at(c - 1) == a.at(e - 1)) {

        if (e > 100) d--;

        else d++;

      }

    }

    if (d > b) b = d;

  }

  cout << b;

}