#include <cstdio>

#include <cstring>

#include <algorithm>



const int MAXN = 5e5 + 5;



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



char S[MAXN];

int nxt1[MAXN], nxt2[MAXN];

int N;



void calc( int *ret )

{

	ret[1] = 0;

	for( int i = 2, j = ret[1] ; i <= N ; i ++ )

	{

		while( j && S[i] ^ S[j + 1] ) j = ret[j];

		if( S[j + 1] == S[i] ) j ++;

		ret[i] = j;

	}

}



bool chkPre( const int p ) { return nxt1[p] && p % ( p - nxt1[p] ) == 0; }

bool chkSuf( const int p ) { return nxt2[p] && p % ( p - nxt2[p] ) == 0; }

bool chk( const int p ) { return chkPre( p ) == 0 && chkSuf( N - p ) == 0; }



int main()

{

	scanf( "%s", S + 1 );

	N = strlen( S + 1 );

	calc( nxt1 ), std :: reverse( S + 1, S + 1 + N ), calc( nxt2 );

	if( nxt1[N] && N % ( N - nxt1[N] ) == 0 )

	{

		if( nxt1[N] == N - 1 ) { printf( "%d\n%d\n", N, 1 ); return 0; }

		puts( "2" ); int ans = 0;

		for( int i = 1 ; i < N ; i ++ ) 

			ans += chk( i );

		write( ans ), putchar( '\n' );

	}

	else puts( "1\n1" );

	return 0;

}