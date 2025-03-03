#include "stdc++.h"

using namespace std;



#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)  FOR(i,0,n)



int main() {

  

  int X,Y; cin >> X >> Y;



  REP(i,1000)REP(j,1000){

    if(i+j == X){

      if(2*i + 4*j == Y){

        cout << "Yes" << endl;

        return 0;

      }

    }

  }

 cout << "No" << endl;



  return 0;

}
