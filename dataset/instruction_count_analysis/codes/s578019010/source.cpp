#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;



int row , col , n ,top , f [ maxn ] , x_1 , y_1 , x_2 , y_2;

bool vis [ maxn ];

vector < pair < int , int > > v [ 4 ];



inline bool check ( int a , int b )

{

	if ( a == 0 || a == row || b == 0 || b == col ) {

		return true;

	} 

	return false;

}



inline int read ( )

{

	int s = 0 , t = 1; char ch = getchar ( );

	while ( ch < '0' || ch > '9' ) { if ( ch == '-' ) t = -1; ch = getchar ( ); }

	while ( ch >= '0' && ch <= '9' ) { s = s * 10 + ch - '0'; ch = getchar ( ); }

	return s * t;

}



void get_in ( int Row , int Col , int flag )

{

	if ( !Row ) {

		v [ 0 ].emplace_back ( make_pair ( Col , flag ) );

	} else if ( col == Col ) {

		v [ 1 ].emplace_back ( make_pair ( Row , flag ) );

	} else if ( row == Row ) {

		v [ 2 ].emplace_back ( make_pair ( col - Col , flag ) );

	} else {

		v [ 3 ].emplace_back ( make_pair ( row - Row , flag ) );

	}

} 



int main ( void )

{

	row = read ( ); col = read ( ); n = read ( );

	for ( int i = 1 ; i <= n ; i++ ) {

		x_1 = read ( ); y_1 = read ( ); x_2 = read ( ); y_2 = read ( );

		if ( check ( x_1 , y_1 ) && check ( x_2 , y_2 ) ) {

			get_in ( x_1 , y_1 , i );

			get_in ( x_2 , y_2 , i );

		}

	}

	for ( int i = 0 ; i < 4 ; i++ ) {

		sort ( v [ i ].begin ( ) , v [ i ].end ( ) );

		for ( vector < pair < int , int > >::iterator x = v [ i ].begin ( ) ; x != v [ i ].end ( ) ; x++ ) {

			int flag = x->second;

			if ( !vis [ flag ] ) {

				f [ ++top ] = flag;

				vis [ flag ] = 1;

			} else if ( !top || f [ top ] != flag ) {

				puts ( "NO" );

				return 0;

			} else {

				--top;

			}

		}

	}

	puts ( "YES" );

	return 0;

}





		