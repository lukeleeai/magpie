#include <cstdio>

#include <assert.h>



typedef long long LL;



const int MAXM = 1e5, MOD = 1e9 + 7;

int n, m;



inline int add ( int a, const int b ) { return ( a += b ) < MOD ? a : a - MOD; }

inline int mul ( LL a, const int b ) { return ( a *= b ) < MOD ? a : a % MOD; }



inline int rint () {

	int x = 0; char s = getchar ();

	for ( ; s < '0' || '9' < s; s = getchar () );

	for ( ; '0' <= s && s <= '9'; s = getchar () ) x = x * 10 + ( s ^ '0' );

	return x;

}



struct Matrix {

	int n, m, mat[3][3];

	Matrix (): n ( 0 ), m ( 0 ), mat {} {}

	Matrix ( const int tn, const int tm ): n ( tn ), m ( tm ), mat {} {}

	inline int* operator [] ( const int key ) { return mat[key]; }

	inline Matrix operator * ( Matrix t ) {

		assert ( m == t.n );

		Matrix ret ( n, t.m );

		for ( int i = 0; i < n; ++ i ) {

			for ( int k = 0; k < m; ++ k ) {

				for ( int j = 0; j < t.m; ++ j ) {

					ret[i][j] = add ( ret[i][j], mul ( mat[i][k], t[k][j] ) );

				}

			}

		}

		return ret;

	}

};



inline Matrix qkpow ( Matrix a, int b ) {

	Matrix ret ( a.n, a.m );

	for ( int i = 0; i < ret.n; ++ i ) ret[i][i] = 1;

	for ( ; b; a = a * a, b >>= 1 ) if ( b & 1 ) ret = ret * a;

	return ret;

}



Matrix I ( 3, 1 ), A ( 3, 3 ), B ( 3, 3 );



inline void init () {

	I[0][0] = 1;

	A[0][0] = 1;

	A[1][0] = 2, A[1][1] = 1;

	A[2][0] = A[2][1] = A[2][2] = 1;

	B = A, ++ B[0][0], ++ B[0][1], ++ B[0][2];

}



int main () {

	init ();

	n = rint (), m = rint ();

	int las = 0;

	for ( int i = 1, x; i <= m; ++ i ) {

		x = rint ();

		I = A * qkpow ( B, x - las - 1 ) * I;

		las = x;

	}

	

	I = A * qkpow ( B, n - las - 1 ) * I;

	printf ( "%d\n", I[2][0] );

	return 0;

}