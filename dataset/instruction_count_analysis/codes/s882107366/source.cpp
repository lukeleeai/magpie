#include <iostream>

#include <iomanip>

#include <sstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <climits>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <algorithm>

#include <functional>



using namespace std;



typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<string> VS;

typedef pair<int,int> PII;

typedef long long ll;

typedef unsigned long long ull;



#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); i++ )

#define UREP( i, m, n ) for ( unsigned int i = (unsigned int)( m ); i < (unsigned int)( n ); i++ )



#define ITER( c ) __typeof( (c).begin() )

#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )

#define ALL( c ) (c).begin(), (c).end()

#define RALL( c ) (c).rbegin(), (c).rend()



#define PB( n ) push_back( n )

#define MP( a, b ) make_pair( ( a ), ( b ) )

#define EXIST( c, e ) ( (c).find( e ) != (c).end() )



#define fst first

#define snd second



#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl



VI memo;



int solve( int n )

{

	if ( n == 0 )

	{

		return 1;

	}

	else if ( n < 0 )

	{

		return 0;

	}



	if ( memo[n] != -1 )

	{

		return memo[n];

	}



	return memo[n] = solve( n - 1 ) + solve( n - 2 ) + solve( n - 3 );

}



int main()

{

	while ( true )

	{

		int n;

		cin >> n;



		if ( n == 0 )

		{

			break;

		}



		memo.resize( n + 1 );

		fill( ALL( memo ), -1 );



		cout << solve( n ) / 3650 + 1 << endl;

	}



	return 0;

}