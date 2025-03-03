#include <iostream>

#include <string>

using namespace std;

int N, Q, l, r, sum[100000]; string S;

int main() {

  cin >> N >> Q >> S;

  for(int i = 1; i < N; ++i) {

    sum[i] = sum[i-1]+(S.substr(i-1,2)=="AC");

  }

  for(int i = 0; i < Q; ++i) {

    cin >> l >> r;

    cout << sum[r-1]-sum[l-1] << endl;

  }

}