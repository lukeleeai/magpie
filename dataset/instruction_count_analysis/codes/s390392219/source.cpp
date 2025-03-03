#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)



int main(){

  int N;

  cin >> N;

  vector<int> a(N);

  rep(i,N){

    cin >> a[i];

  }



  int count = 0;

  bool flag = true;

    

  while(flag == true){

    rep(i,N){

    	if(a[i]%2 == 0){

      		a[i] = a[i]/2;

        }

      	else {

          flag = false;

          break ;

        }

    }

    if(flag == false) break;

    count++;

  }

  

  cout << count << endl;

  

  return 0;

}
