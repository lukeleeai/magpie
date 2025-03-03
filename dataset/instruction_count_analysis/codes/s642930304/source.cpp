#include "stdc++.h"

using namespace std;



int main(){

  int n;  cin >> n;

  int ans = 1<<30;

  while(n--){

    int a;  cin >> a;

    int cnt = 0;

    while(a % 2 == 0){

      a >>= 1;

      cnt++;

    }

    ans = min(ans, cnt);

  }



  cout << ans << endl;



  return 0;

}
