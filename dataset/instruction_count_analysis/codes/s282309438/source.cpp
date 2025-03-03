#include <map>

#include <cmath>

#include <cstdio>



typedef long long LL;



const int MAXN = 1e5 + 5;



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

_T MAX( const _T a, const _T b )

{

	return a > b ? a : b;

}



std :: map<LL, int> mp;



LL a[MAXN], oppo[MAXN];

LL pw2[MAXN], pw3[MAXN];



int prime[MAXN], pn;

int N;



bool isPrime[MAXN];



void EulerSieve( const int siz )

{

	for( int i = 2 ; i <= siz ; i ++ )

	{

		if( ! isPrime[i] ) prime[++ pn] = i;

		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= siz ; j ++ )

		{

			isPrime[i * prime[j]] = true;

			if( ! ( i % prime[j] ) ) break;

		}

	}

	for( int i = 1 ; i <= pn ; i ++ )

		pw2[i] = 1ll * prime[i] * prime[i], pw3[i] = 1ll * pw2[i] * prime[i];

}



int main()

{

	bool flg = false;

	read( N ); EulerSieve( 3000 );

	for( int i = 1 ; i <= N ; i ++ ) 

	{

		read( a[i] );

		for( int k = 1 ; k <= pn && pw3[k] <= a[i] ; k ++ )

			while( ! ( a[i] % pw3[k] ) )

				a[i] /= pw3[k];

		if( a[i] == 1 ) flg = true, mp[a[i]] = -1;

		else

		{

			mp[a[i]] ++;

			LL tmp = a[i];

			int tot = 0, indx; LL rest = 1;

			for( int k = 1 ; k <= pn && prime[k] <= tmp ; k ++ )

				if( ! ( tmp % prime[k] ))

				{

					tot ++, indx = 0;

					while( ! ( tmp % prime[k] ) )

						indx ++, tmp /= prime[k];

					if( indx & 1 ) rest = 1ll * rest * pw2[k];

					else rest = 1ll * rest * prime[k];

				}

			int t = sqrt( tmp );

			if( 1ll * t * t == tmp ) oppo[i] = 1ll * t * rest;

			else oppo[i] = ( tmp <= 1e5 ? rest * tmp * tmp : 0 );

		}

	}

	int ans = 0;

	for( int i = 1 ; i <= N ; i ++ )

		if( ~ mp[a[i]] )

			ans += MAX( mp[a[i]], mp[oppo[i]] ),

			mp[a[i]] = mp[oppo[i]] = -1;

	write( ans + flg ), putchar( '\n' );

	return 0;

}