#include <cstdio>

#include <algorithm>



const int MAXN = 1e5 + 5;



template<typename _T>

void read( _T &x )

{

	x = 0; char s = getchar(); int f = 1;

	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }

	while( '0' <= s && s <= '9' ) { x = ( x << 1 ) + ( x << 3 ) + s - '0', s = getchar(); }

	x *= f;

}



template<typename _T>

void write( _T x )

{

	if( x < 0 ) { putchar( '-' ), x = -x; }

	if( 9 < x ) write( x / 10 );

	putchar( x % 10 + '0' );

}



int a[MAXN];

int N;



bool cmp( const int &a, const int &b ) { return a > b; }



int main()

{

	read( N );

	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );

	std :: sort( a + 1, a + 1 + N, cmp );

	int fir = 1;

	for( ; fir <= N && fir + 1 <= a[fir + 1] ; fir ++ );

	bool up = ( a[fir] - fir + 1 ) & 1, rig = true;

	for( int i = fir + 1 ; i <= N && a[i] >= fir ; i ++, rig ^= 1 );

	bool tag = ! ( up & rig );

	puts( tag ? "First" : "Second" );

	return 0;

}