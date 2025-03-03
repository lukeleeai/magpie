#include "stdc++.h"

using namespace std;

int64_t MAXN = pow(10, 5) + 10;

int64_t N, first = 0;

vector<int64_t> A(MAXN);



int main()

{

  cin >> N;

  for (int i = 0; i < N; i++)

  {

    cin >> A[i];

    if (A[i] % 2)

      first = 1;

  }

  cout << (first ? "first" : "second") << endl;

}
