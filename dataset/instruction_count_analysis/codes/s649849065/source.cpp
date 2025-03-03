// In the name of God 

#include "stdc++.h"



using namespace std ;





#define int long long

#define all(v) v.begin() , v.end()



template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}

template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}



const int N = ( int ) 1e5 + 10 ;



int n , a [ N ] ; 



int32_t main()

{

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n ;

	for ( int i = 1 ; i <= n ; ++i )

		cin >> a [ i ] ;

	sort ( a + 1 , a + n + 1 ) ;

	reverse ( a + 1 , a + n + 1 ) ; 

	int id = 0 ;

	for ( int j = 1 ; j <= n ; ++j )

		if ( a [ j ] >= j )

			id = j ;

	//cout << id << '\n' ; 

	int res = 0 , rem = a [ id ] - id + 1 ;

	res |= rem % 2 == 0 ;

	int found = 0 ; 

	for ( int i = id + 1 ; i <= n ; ++i ) {

		if ( a [ i ] >= id ) {

			found = i ; 

		}

	}

	//cout << rem << ' ' << found << '\n' ; 

	if ( found ) 

		res |= ( found - id + 1 ) % 2 == 0 ;

	cout << ( res ? "First" : "Second" ) << '\n' ; 

}
