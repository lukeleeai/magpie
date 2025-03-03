#include "stdc++.h"

#define ll long long

#define ull unsigned long long

#define MAX_INF 0x3f

#define MAX_INF_VAL 0x3f3f3f3f

#define MAX_INF_VAL_LL 0x3f3f3f3f3f3f3f3f

#define pi 3.141592653589

#define eps 1e-6

//#define p 2173412051LL

//#define sz 2



using namespace std;



bool ok[ 200010 ];



int main() {

	int n, ma = 0;

	int x;

	ok[ 0 ] = true;

	scanf( "%d", &n );

	for( int i = 0; i < n; ++i ) {

		scanf( "%d", &x );

		ok[ x ] |= ok[ x - 1 ];

		if( ok[ x ] )

			ma = max( ma, x );

	}

	if( ma == 0 )

		ma = n + 1;

	printf( "%d", n - ma );

	return 0;

}