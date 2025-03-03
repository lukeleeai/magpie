#include "stdc++.h"

using namespace std;



int main() {

  int n;

  string s;

  cin >> n >> s;

  s.resize(unique(s.begin(), s.end()) - s.begin());

  cout << s.size() << "\n";

  return 0;

}