#include"stdc++.h"

using namespace std ;

int x ;

int main()

{

	int sum = 0 , y ;

	cin >> x ;

	y= x ;

	while ( y > 0 ) 

		sum += y% 10 , y/=10 ;

	if ( x % sum == 0 ) 

		cout << "Yes" <<"\n" ;

	else

		cout << "No"<< endl;



}