#include <iostream>

#include <vector>

using namespace std;



int HOST[20];



int DP(vector <int> V, int n){

  if (n < 0)

    return 0;

  if (!HOST[n])

    HOST[n] = max(V[n] + DP(V,n-1), DP(V,n-1));

  return HOST[n];

}



int main() {

  ios_base::sync_with_stdio(false);



  int n, x, y, i;

  cin >> n;

  vector <int> V (n);

  for (i = 0; i < n; i++)

    cin >> V[i];

  for (i = 0; i < n; i++){

    cin >> x;

    V[i] -= x;

  }

  

  cout << DP(V, n-1) << endl;

}