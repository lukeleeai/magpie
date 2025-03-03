#include <iostream>

using namespace std;



#define MAX 10000



int main(void){

  int n,data[MAX+1],des[2],num,max,mnum;



  for(;;){



    max = mnum = 0;



    for( int i = 0 ; i <= MAX ; i++ )

	data[i] = 0;



    cin >> n;

    if( n == 0 ) break;

    for( int i = 0 ; i < n ; i++ ){

      cin >> num >> des[1] >> des[0];

      data[num] = des[0] + des[1];



      if( data[num] > max ){

	max = data[num];

	mnum = num;

      }



    }



    cout << mnum << " " << max << endl;



  }



  return 0;

}