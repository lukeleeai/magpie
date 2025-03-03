/*  ***  In The Name of God ... ***  */ 

#include "stdc++.h"

 

using namespace std;

 

typedef long long ll;

typedef long double ld;

 

 

#define int long long

#define all(v) v.begin() , v.end()



template<typename T> inline bool smin(T &a, const T &b){ return b < a ? a = b,1:0;}

template<typename T> inline bool smax(T &a, const T &b){ return a < b ? a = b,1:0;}



const int N = 1e5 + 10 ;



int n , ar [ N ] ;

vector < int > vc ;

map < int , int > mp ; 



inline void work ( ) {

	for ( int i = 1 ; i <= n ; ++ i )

		vc . push_back ( ar [ i ] ) ;

	sort ( all ( vc ) ) ;

	int ptr = 1 ; 

	for ( int x : vc )

		mp [ x ] = ptr ++ ;

	for ( int i = 1 ; i <= n ; ++ i )

		ar [ i ] = mp [ ar [ i ] ] ; 

}



int32_t main()

{

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n ;

	for ( int i = 1 ; i <= n ; ++ i )

		cin >> ar [ i ] ;

	work ( ) ;

	vector < int > odd ; 

	for ( int i = 1 ; i <= n ; i += 2 ) {

		odd . push_back ( ar [ i ] ) ; 

	}

	for ( int x : odd )

		cerr << x << ' ' ;

	cerr << '\n' ; 

	int bads = 0 ; 

	for ( int x : odd ) 

		bads += ( x % 2 == 0 ) ;

	cout << bads << '\n' ; 

}
