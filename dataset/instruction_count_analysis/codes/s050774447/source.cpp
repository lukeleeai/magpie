/*  ***  In The Name of God ... ***  */

#include "stdc++.h"



using namespace std ;

 

typedef long long ll ;

typedef long double ld ;





#define int long long

#define all(v) v.begin() , v.end()



template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}

template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}



const int N = ( int ) 1e5 + 10 ;



int n , a [ N ] , b [ N ] ;



int32_t main()                     

{

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n ;

	for ( int i = 0 ; i < n ; ++ i )

		cin >> a [ i ] >> b [ i ] ;

	int added = 0 , res = 0 ;

	for ( int i = n - 1 ; i >= 0 ; -- i ) {

		a [ i ] += added ;

		if ( a [ i ] % b [ i ] == 0 ) continue ; 

		int reach = a [ i ] + ( b [ i ] - ( a [ i ] % b [ i ] ) ) ;

		added += reach - a [ i ] ; 

	}

	cout << added << endl ; 

}
