#include "stdc++.h"

using namespace std;



int main()

{

  int64_t N, a, odds = 0;

  cin >> N;

  for (int i = 0; i < N; i++)

  {

    cin >> a;

    if (a % 2)

      odds++;

  }

  cout << (odds == 0 ? "second" : "first") << endl;

}
