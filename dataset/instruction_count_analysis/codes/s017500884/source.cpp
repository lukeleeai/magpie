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

  vector<int> v;

  for (int i = 11; i <= 55555; i += 5) {

    int no = 0;

    for (int j = 2; j * j <= i; j++) {

      if (i % j == 0) {

        no++;

        break;

      }

    }

    if (!no) v.emplace_back(i);

  }  

  for (int i = 0; i < N; i++) {

    cout << v[i] << " \n"[i + 1 == N];

  }



  return 0;

}