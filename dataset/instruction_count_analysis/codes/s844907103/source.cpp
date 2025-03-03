#pragma GCC optimize ("O3")

#pragma GCC target ("sse4")



#include "stdc++.h"



using namespace std;

using ll = long long ;



const int N = 2e5 + 5;

const int mod = 1e9 + 7;



int n, k;

int main(){

  cin >> n;

  vector<int>a(n);

  for(int i = 0; i < n; i++){

    cin >> a[i];  a[i] -= (i + 1);

  }



  sort(a.begin(), a.end());

  int med = a[n / 2];

  long long out = 0;

  for(int i = 0; i < n; i++)

    out += abs(a[i] - med);



  cout << out << '\n';



  return 0;

}
