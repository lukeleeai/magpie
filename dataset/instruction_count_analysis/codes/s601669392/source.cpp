#include "stdc++.h"

using namespace std;



const int N = 100000 + 10;



int n, T;

int aa[N];



int main() {

	scanf( "%d%d", &n, &T );

	for( int i = 1; i <= n; i++ )

		scanf( "%d", aa + i );

	int amin = aa[1];

	int smax = 0;

	for( int i = 2; i <= n; i++ ) {

		smax = max( smax, aa[i] - amin );

		amin = min( amin, aa[i] );

	}

	int ans = 0;

	amin = aa[1];

	for( int i = 2; i <= n; i++ ) {

		ans += (aa[i] - amin == smax);

		amin = min( amin, aa[i] );

	}

	printf( "%d\n", ans );

}




