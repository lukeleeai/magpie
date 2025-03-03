#include "stdc++.h"

using namespace std;

 

const int MAXN = 500050;

 

char s[MAXN];

int ans, l, r, n, a[MAXN];

 

inline bool chk(int x)

{

	int len = n, sum = 0;

	for( int i = 1 ; i <= n ; i++ ) a[ i ] = ( s[ i ] - '0' ) * 9;

	a[ 1 ] += 9 * x;

	for( int i = 1 ; i <= len ; i++ )

		if( a[ i ] > 9 )

		{

			if( i == len ) a[ ++len ] = 0;

			a[ i + 1 ] += a[ i ] / 10;

			a[ i ] %= 10;

		}

	for( int i = 1 ; i <= len ; i++ ) sum += a[ i ];

	return sum <= 9 * x;

}

 

int main()

{

#ifdef wxh010910

	freopen( "data.in", "r", stdin );

#endif

	scanf( "%s", s + 1 );

	l = 1, r = n = strlen( s + 1 );

	reverse( s + 1, s + n + 1 );

	while( l <= r )

	{

		int mid = l + r >> 1;

		if( chk( mid ) ) ans = mid, r = mid - 1;

		else l = mid + 1;

	}

	cout << ans << endl;

}
