#include <cstdio>



const int mod = 1e9 + 7;

const int MAXN = 5005;



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



struct edge

{

	int to, nxt;

}Graph[MAXN << 1];



int tmp[MAXN];

int f[MAXN][MAXN], g[MAXN];

int head[MAXN], siz[MAXN];

int N, cnt;



void sub( int &x, const int v ) { x = ( x < v ? x + mod - v : x - v ); }

void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }



void addEdge( const int from, const int to )

{

	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];

	head[from] = cnt;

}



void DFS( const int u, const int fa )

{

	f[u][1] = 1, siz[u] = 1;

	for( int i = head[u], v ; i ; i = Graph[i].nxt )

		if( ( v = Graph[i].to ) ^ fa )

		{

			DFS( v, u );

			for( int i = 0 ; i <= siz[u] + siz[v] ; i ++ ) tmp[i] = 0; 

			for( int j = siz[u] ; j ; j -- )

				for( int k = siz[v] ; ~ k ; k -- )

					add( tmp[j + k], 1ll * f[u][j] * f[v][k] % mod );

			siz[u] += siz[v];

			for( int i = 0 ; i <= siz[u] ; i ++ ) f[u][i] = tmp[i];

		}

	for( int i = 1 ; i <= siz[u] ; i ++ )

		sub( f[u][0], 1ll * f[u][i] * g[i] % mod );

}



int main()

{

	read( N );

	for( int i = 1, a, b ; i < N ; i ++ )

		read( a ), read( b ), addEdge( a, b ), addEdge( b, a );

	g[2] = 1;

	for( int i = 4 ; i <= N ; i += 2 )

		g[i] = 1ll * g[i - 2] * ( i - 1 ) % mod;

	DFS( 1, 0 );

	write( ( mod - f[1][0] ) % mod ), putchar( '\n' );

	return 0;

}