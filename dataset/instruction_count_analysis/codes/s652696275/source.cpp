#include "stdc++.h"

#define ll long long

#define ull unsigned long long

#define MAX_INF 0x3f

#define MAX_INF_VAL 0x3f3f3f3f

#define MAX_INF_VAL_LL 0x3f3f3f3f3f3f3f3f

#define pi 3.141592653589

#define eps 1e-6

//#define p 2173412051LL

//#define sz 2



using namespace std;



int n;

int u, v, lca;

int fa[ 100010 ], dep[ 100010 ], ma[ 100010 ];

vector< int > e[ 100010 ], son[ 100010 ];



void dfs( int );

int check( int );



int main() {

	int n;

	int x, y;

	int ans = 0;

	scanf( "%d%d%d", &n, &u, &v );

	for( int i = 1; i < n; ++i ) {

		scanf( "%d%d", &x, &y );

		e[ x ].push_back( y );

		e[ y ].push_back( x );

	}

	dfs( 1 );

	if( fa[ u ] == v ) {

		printf( "%d", ma[ u ] - dep[ u ] );

		return 0;

	}

	if( fa[ v ] == u ) {

		y = 0;

		while( u ) {

			x = 0;

			for( int i = 0; i < son[ u ].size(); ++i ) {

				if( son[ u ][ i ] == v )

					continue;

				x = max( x, ma[ son[ u ][ i ] ] - dep[ son[ u ][ i ] ] );

			}

			if( x == 0 )

				ans = max( ans, y );

			else

				ans = max( ans, y + 1 + x );

			u = fa[ u ];

			v = fa[ v ];

			++y;

		}

		printf( "%d", ans );

		return 0;

	}

	x = u, y = v;

	while( x != y ) {

		if( dep[ x ] < dep[ y ] )

			swap( x, y );

		x = fa[ x ];

	}

	lca = x;

	if( lca == u ) {

		lca = fa[ v ];

	} else if( lca == v ) {

		x = u;

		while( fa[ x ] != v )

			x = fa[ x ];

		lca = x;

	} else {

		lca = fa[ v ];

	}

	memset( ma, 0, sizeof( ma ) );

	memset( fa, 0, sizeof( fa ) );

	memset( dep, 0, sizeof( dep ) );

	dfs( lca );

	for( int i = u; i; i = fa[ i ] ) {

		x = check( i );

		if( x == -1 )

			break;

		ans = max( ans, x );

	}

	printf( "%d", ans );

	return 0;

}



void dfs( int x ) {

	ma[ x ] = dep[ x ];

	for( int i = 0; i < e[ x ].size(); ++i ) {

		if( e[ x ][ i ] == fa[ x ] )

			continue;

		son[ x ].push_back( e[ x ][ i ] );

		fa[ e[ x ][ i ] ] = x;

		dep[ e[ x ][ i ] ] = dep[ x ] + 1;

		dfs( e[ x ][ i ] );

		ma[ x ] = max( ma[ x ], ma[ e[ x ][ i ] ] );

	}

}



int check( int x ) {

	int res = dep[ u ] - dep[ x ];

	int a = x, b = dep[ u ] + dep[ v ] - dep[ lca ] - 2 * ( dep[ u ] - dep[ x ] );

	if( b <= 0 )

		return -1;

	res += ma[ a ] - dep[ a ];

	while( b ) {

		if( b == 1 )

			break;

		++res;

		b -= 2;

		if( b == 0 )

			break;

		++res;

	}

	return res;

}