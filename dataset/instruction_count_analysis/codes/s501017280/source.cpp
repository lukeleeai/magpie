#include <cstdio>



const int mod = 1e9 + 7;

const int MAXN = 2005, MAXS = MAXN * MAXN;



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



int f[MAXN][MAXN];

int fac[MAXS], ifac[MAXS];

int N, K;



int qkpow( int, int );

int inv( const int a ) { return qkpow( a, mod - 2 ); }

void sub( int &x, const int v ) { x = ( x < v ? x - v + mod : x - v ); }

void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }



int qkpow( int base, int indx )

{

	int ret = 1;

	while( indx )

	{

		if( indx & 1 ) ret = 1ll * ret * base % mod;

		base = 1ll * base * base % mod, indx >>= 1;

	}

	return ret;

}



void init( const int siz )

{

	fac[0] = ifac[0] = 1;

	for( int i = 1 ; i <= siz ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;

	ifac[siz] = inv( fac[siz] );

	for( int i = siz - 1 ; ~ i ; i -- ) ifac[i] = 1ll * ifac[i + 1] * ( i + 1 ) % mod;

}



int C( const int n, const int m ) { return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }



int main()

{

	read( N ), read( K );

	if( K == 1 ) { puts( "1" ); return 0; }

	init( N * K );

	for( int i = 0 ; i <= N ; i ++ ) f[i][0] = 1;

	for( int i = 1 ; i <= N ; i ++ )

		for( int j = 1 ; j <= i ; j ++ )

		{

			f[i][j] = f[i - 1][j];

			int t = N * K - i - ( K - 1 ) * ( j - 1 ) - 1;

			add( f[i][j], 1ll * f[i][j - 1] * ( N - j + 1 ) % mod * C( t, K - 2 ) % mod );

		}

	write( f[N][N] ), putchar( '\n' );

	return 0;

}