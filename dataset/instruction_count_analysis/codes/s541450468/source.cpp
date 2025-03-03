#include <iostream>

#include <string>

#include <vector>

#include <set>

#include <algorithm>

using namespace std;



int main() {

  int n;

  string s;

  cin >> n >> s;

  int ans = 0;

  for (int i = 0; i < n; ++i) {

    set<char> x, y;

    for (int j = 0; j <= i; ++j) {

      x.insert(s[j]);

    }

    for (int j = i+1; j < n; ++j) {

      y.insert(s[j]);

    }

    vector<char> v(n);

    auto it = set_intersection(x.begin(), x.end(), y.begin(), y.end(), v.begin());

    v.resize(it-v.begin());

    // cout << v.size() << endl;

    // for (auto it : v) {

    //   cout << it <<  ' ';

    // } cout << endl;

    ans = max(ans, (int)v.size());

  }

  cout << ans << endl;

}
