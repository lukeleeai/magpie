#include "stdc++.h"

using namespace std;



int main() {

  int N;

  int a[100000] = {};



  cin >> N;

  for(int i = 1; i <= N; i++){

    cin >> a[i];

  }



  int s = 0;

  for(int i = 0; i <= N; i++){

    s += abs(a[i] - a[i+1]);

  }



  int ans = 0;

  for(int i = 1;i <=N; i++){

    ans = s - abs(a[i-1] - a[i]) - abs(a[i] - a[i+1]) + abs(a[i-1] - a[i+1]);

    cout << ans << endl;

  }



}