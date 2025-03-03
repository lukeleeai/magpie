#include "stdc++.h"

#define dum(x) cout<<#x<<'='<<x<<endl

#define ll long long

using namespace std;



int main() {

  int n;

  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {

    cin >> v.at(i);

  }

  v.insert(v.begin(), 0);

  v.push_back(0);

  int d = 0;

  for (int i = 0; i < v.size() - 1; i++) {

    d += abs(v.at(i) - v.at(i + 1));

  }

  int ans = 0;

  for (int i = 1; i < v.size() - 1; i++) {

    ans = d - abs(v.at(i - 1) - v.at(i)) - abs(v.at(i) - v.at(i + 1)) + abs(v.at(i - 1) - v.at(i + 1));

    cout << ans << endl;

  }

}