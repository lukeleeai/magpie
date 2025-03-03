#include <iostream>

using namespace std;



int main() {

  int N, K; cin >> N >> K;

  int A[100000]; for (int i = 0; i < N; i++) cin >> A[i];

  cout << (N + K - 3) / (K - 1) << endl;

  return 0;

}