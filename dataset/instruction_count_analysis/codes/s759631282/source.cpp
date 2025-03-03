#include"stdc++.h"

using namespace std ;



int main () {

  int  N ;

  cin >> N ;

  int ans = 0 ;

  for(int i = 1 ; i <= 1+N ; i++ ){

    for(int j = 2 ; j <= 2+N ; j++ ){

      int pre = pow(i,j) ;

      if( pre <= N ) ans = max(ans,pre) ;

      else break ;

    }

  }

  cout << ans << endl ;

}
