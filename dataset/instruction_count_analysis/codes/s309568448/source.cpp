#include <cstdio>

#include <algorithm>



#define Int register int



const int MAXN = 1e5;

int n, a[MAXN + 5];



inline void Work () {

	scanf ( "%d", &n );

	for ( Int i = 1; i <= n; ++ i ) scanf ( "%d", &a[i] );

	std :: sort ( a + 1, a + n + 1, []( const int x, const int y ) { return x > y; } );

	for ( Int i = 1; i <= n; ++ i ) {

		if ( i + 1 > a[i + 1] ) {

			int du = a[i] - i, dr = 0;

			for ( ; a[i + dr + 1] == i; ++ dr );

			puts ( du & 1 || dr & 1 ? "First" : "Second" );

			break;

		}

	}

}



int main () {

	Work ();

	return 0;

}