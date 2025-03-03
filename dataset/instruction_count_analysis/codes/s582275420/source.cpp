#include<iostream>

#include<vector>

#include<cmath>

using namespace std;



int main() {

  int N, T;

  vector<int> t;



  cin >> N >> T;

  t.resize(N);



  for (int i = 0; i < N; i++)

    cin >> t[i];



  int64_t ans = 0;

  for (int i = 1; i < N; i++) {

    if (t[i] - t[i-1] >= T)

      ans += T;

    else

      ans += t[i] - t[i-1];

  }

  ans += T;



  cout << ans << endl;

}
