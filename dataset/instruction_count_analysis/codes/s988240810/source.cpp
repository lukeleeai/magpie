#include<stdio.h>

#define inf 1000000000000ll

long long f ( long long b, long long n ) {

	if ( n < b ) return n;

	else return f ( b, n / b ) + n % b;

}

int main ( void ) {

	long long n, s;

	scanf ( "%lld%lld", &n, &s );

	if ( n < s ) {

		printf ( "-1" );

	} else if ( n == s ) {

		printf ( "%lld", n + 1 );

	} else {

		long long p = n - s, ans = inf;

		for ( int i = 1; 1ll * i * i <= p; i++ )

			if ( p % i == 0 ) {

				if ( f ( 1ll * i + 1, n ) == s && ans > i + 1 ) {

					ans = i + 1;

				}

				if ( f ( p / i + 1, n ) == s && ans > p / i + 1 ) {

					ans = p / i + 1;

				}

			}

		if ( ans != inf ) {

			printf ( "%lld", ans );

		} else {

			printf ( "-1" );

		}

	}

}
