#include <cstdio>



const int MAXN = 5000, MOD = 1e9 + 7;

int n, ecnt, head[MAXN + 5], siz[MAXN + 5];

int g[MAXN + 5], f[MAXN + 5][MAXN + 5];



struct Edge { int to, nxt; } graph[MAXN * 2 + 5];



inline void addeq ( int& a, const int b ) { if ( ( a += b ) >= MOD ) a -= MOD; }



inline void link ( const int s, const int t ) {

	graph[++ ecnt] = { t, head[s] };

	head[s] = ecnt;

}



inline void solve ( const int u, const int fa ) {

	static int tmp[MAXN + 5];

	f[u][1] = siz[u] = 1;

	for ( int i = head[u], v; i; i = graph[i].nxt ) {

		if ( ( v = graph[i].to ) ^ fa ) {

			solve ( v, u );

			for ( int j = 1; j <= siz[u] + siz[v]; ++ j ) tmp[j] = 0;

			for ( int j = 0; j <= siz[v]; ++ j ) {

				for ( int k = 1; k <= siz[u]; ++ k ) {

					addeq ( tmp[j + k], 1ll * f[v][j] * f[u][k] % MOD );

				}

			}

			for ( int j = 1; j <= siz[u] + siz[v]; ++ j ) f[u][j] = tmp[j];

			siz[u] += siz[v];

		}

	}

	for ( int i = 2; i <= siz[u]; i += 2 ) addeq ( f[u][0], 1ll * f[u][i] * g[i] % MOD );

	f[u][0] = ( MOD - f[u][0] ) % MOD;

}



int main () {

	scanf ( "%d", &n );

	for ( int i = 1, u, v; i < n; ++ i ) {

		scanf ( "%d %d", &u, &v );

		link ( u, v ), link ( v, u );

	}

	g[0] = 1;

	for ( int i = 2; i <= n; i += 2 ) g[i] = ( i - 1ll ) * g[i - 2] % MOD;

	solve ( 1, 0 );

	printf ( "%d\n", ( MOD - f[1][0] ) % MOD );

	return 0;

}