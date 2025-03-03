#include "stdc++.h"

using namespace std;

using ll = long long;

using pii = pair<int, int>;



int N;



int main() {

  cin.tie(0);

  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  

  cin >> N;

  vector<int> p;

  for (int i = 11; p.size() < N; i += 5) {

    int flag = 1;

    for (int j = 2; j * j <= i; j++) {

      if (i % j == 0) flag = 0;

    }

    if (flag) p.emplace_back(i);

  }

  for (int i = 0; i < N; i++) {

    cout << p[i] << " \n"[i + 1 == N];

  }



  return 0;

}