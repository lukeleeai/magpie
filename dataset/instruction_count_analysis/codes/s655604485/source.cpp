#include <cstdio>



const int MAXN = 40, MAXL = 17, MOD = 1e9 + 7;

int n, x, y, z, f[2][1 << MAXL];



inline void add_eq ( int& a, const int b ) { if ( ( a += b ) >= MOD ) a -= MOD; }



int main () {

	scanf ( "%d %d %d %d", &n, &x, &y, &z );

	int all = ( 1 << x + y + z ) - 1, ans = 1;

	int haiku = ( 1 << x + y + z >> 1 ) | ( 1 << y + z >> 1 ) | ( 1 << z >> 1 );

	f[0][0] = 1;

	for ( int i = 0, t = 0; i < n; ++ i, t ^= 1, ans = ans * 10ll % MOD ) {

		for ( int s = 0; s <= all; ++ s ) {

			int& cur = f[t][s];

			if ( ! cur ) continue;

			for ( int j = 1, trs; j <= 10; ++ j ) {

				trs = ( s << j | ( 1 << j >> 1 ) ) & all;

				if ( ( trs & haiku ) ^ haiku ) add_eq ( f[t ^ 1][trs], cur );

			}

			cur = 0;

		}

	}

	int sub = 0;

	for ( int i = 0; i <= all; ++ i ) add_eq ( sub, f[n & 1][i] );

	printf ( "%d\n", ( ans - sub + MOD ) % MOD );

	return 0;

}