#include <iostream>

#include <vector>

using namespace std;

int main() {

  int N, a, r{2};

  cin >> N;

  vector<int> A(N + 1);

  while (r--)

    for (int i = 1; i <= N; ++i) cin >> a, A[i] = a + max(A[i - 1], A[i]);

  cout << A[N] << endl;

}
