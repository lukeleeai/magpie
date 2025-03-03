#include<iostream>

#include<cmath>



using namespace std;

typedef unsigned long long ullong;



ullong power(ullong x, ullong n, ullong M){

  ullong tmp = 1;



  if ( n > 0 ){

    tmp = power(x, n/2, M);

    if ( n%2 == 0 ) tmp = (tmp*tmp)%M;

    else tmp = (((tmp*tmp)%M)*x)%M;

  }

  return tmp;

}



main(){

  int m, n;

  cin >> m >> n;



  cout << power(m, n, 1000000007) << endl;



  return 0;

}