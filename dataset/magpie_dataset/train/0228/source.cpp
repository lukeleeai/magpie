#include <iostream>

#include <algorithm>

#include <cstdlib>



using namespace std;



const int inf = 1000001;



int main()

{

  int n, mn, t, a[21], mask, s, u;



  while(cin>>n && n){

    t = 0;

    mn = inf;



    for(int i = 0; i < n; ++i){

      cin >> a[i];

      t += a[i];

    }



    mask = 1<<n;

    for(int i = 0; i < mask; i++){

      s = 0;

      for(int j = 0; j < n; j++){

	u = 1<<j;

	if(i&u) s += a[j];

      }  

      mn = min(mn, abs(s-(t-s)));

    }



    cout << mn << endl;

  }



  return 0;

}