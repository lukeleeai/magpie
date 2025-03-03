//in the name of Allah ;

#include"stdc++.h"

using namespace std ;

int arr[1000] ;

int main ()

{

	int n , ans = 0;

	cin >> n ;

	n *= 2 ; 

	for ( int i = 0 ;i < n ; i++ ) 

		cin >> arr[i];

	sort ( arr, arr+n ) ;

	for ( int i = 0 ; i < n ; i+= 2 ) 

		ans += min ( arr[i] , arr[i+1] ) ;

	cout << ans << endl;

}