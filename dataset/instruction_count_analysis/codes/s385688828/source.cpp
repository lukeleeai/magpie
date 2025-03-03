#include <cstdio>



typedef long long LL;



const int MAXN = 4005;



template<typename _T>

void read( _T &x )

{

	x = 0;char s = getchar();int f = 1;

	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}

	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}

	x *= f;

}



template<typename _T>

void write( _T x )

{

	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }

	if( 9 < x ){ write( x / 10 ); }

	putchar( x % 10 + '0' );

}



template<typename _T>

_T MIN( const _T a, const _T b )

{

	return a < b ? a : b;

}



int q[MAXN];

int a[MAXN];

int N, x;



LL calc( const int l )

{

	LL ret = 1ll * l * x;

	int h = 1, t = 0, r = 1;

	for( int i = 1 ; i <= N ; i ++ )

	{

		while( h <= t && q[h] < i ) h ++;

		for( ; r <= i + l ; r ++ )

		{

			while( h <= t && a[q[t]] >= a[r] )

				t --;

			q[++ t] = r;

		}

		ret += a[q[h]];

	}

	return ret;

}



int main()

{

	read( N ), read( x );

	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), a[i + N] = a[i];

	LL ans = 1e18;

	for( int i = 0 ; i < N ; i ++ )

		ans = MIN( ans, calc( i ) );

	write( ans ), putchar( '\n' );

	return 0;

}