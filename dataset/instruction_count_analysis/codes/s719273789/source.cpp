#include <algorithm>

#include <cmath>

#include <cstdio>

#include <deque>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <vector>



using namespace std;



typedef long long ll;



#define MOD 1000000007



int main() {

  int n;

  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; ++i) {

    cin >> a[i];

  }

  int t = 1;

  int cnt = 0;

  for (int i = 0; i < n; ++i) {

    if (t == a[i]) {

      t++;

      cnt++;

    }

  }

  if (cnt == 0) {

    cout << -1 << endl;

  } else {

    cout << n - cnt << endl;

  }

  return 0;

}