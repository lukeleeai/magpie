#include <iostream>

#include <vector>

using namespace std;



int MinIndex(vector <int> A){

  int i = 0;

  int m = 1;

  for (int j = 0; j < A.size(); j++){

    if (A[j] < m)

      m = A[j];

      i = j;

  }

  return i;

}



int HowMany(vector <int> A, int K, int N){

  if (N == K)

    return 1;

  int i = 0;

  int x = N - MinIndex(A), y = MinIndex(A);

  while (x > 0){

    i++;

    x -= K;

    x++;

  }

  while (y > 0){

    i++;

    y -= K;

    y++;

  }

  return i-1;

}



int main() {

  ios_base::sync_with_stdio(false);



  int N, K;

  cin >> N >> K;

  vector <int> A(N);

  for (int i = 0; i < N; i++)

    cin >> A[i];

  cout << HowMany(A, K, N) << endl;

}