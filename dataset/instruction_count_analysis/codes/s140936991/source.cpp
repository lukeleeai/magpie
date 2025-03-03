#include "stdc++.h"

using namespace std;



const int N = 100000 + 10;



const int Up = 0;

const int Down = 1;



int n;

int aa[N];

int dp[N][2];



int main() {

	scanf( "%d", &n );

	for( int i = 1; i <= n; i++ ) {

		scanf( "%d", aa + i );

	}

	memset( dp, 0x3f, sizeof(dp) );

	dp[1][Up] = dp[1][Down] = 1;

	for( int i = 2; i <= n; i++ ) {

		dp[i][Up] = dp[i-1][Up] + (aa[i] < aa[i-1]);

		dp[i][Down] = dp[i-1][Down] + (aa[i] > aa[i-1]);

		dp[i][Up] = min( dp[i][Up], dp[i-1][Down] + 1 );

		dp[i][Down] = min( dp[i][Down], dp[i-1][Up] + 1 );

	}

	printf( "%d\n", min(dp[n][Up],dp[n][Down]) );

}


