// AOJ 0200 (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0200)

#include<cstdio>

#include<algorithm>

#include<limits>

#define rep(i,a) for(int i=0;i<(a);++i)



const int MAX_M = 100, INF = std::numeric_limits<int>::max()>>4;



int n, m;

int d[2][MAX_M][MAX_M];



int main()

{

	while( scanf( "%d%d", &n, &m ), n|m )

	{

		rep( k, 2 ) rep( i, m ) rep( j, m )

			d[k][i][j] = i==j?0:INF;



		rep( i, n )

		{

			int a, b, c, t;

			scanf( "%d%d%d%d", &a, &b, &c, &t );

			--a; --b;

			d[0][a][b] = d[0][b][a] = c;

			d[1][a][b] = d[1][b][a] = t;

		}



		rep( r, 2 ) rep( k, m ) rep( i, m ) rep( j, m )

			d[r][i][j] = std::min( d[r][i][j], d[r][i][k]+d[r][k][j] );



		int k;

		scanf( "%d", &k );



		rep( i, k )

		{

			int p, q, r;

			scanf( "%d%d%d", &p, &q, &r );



			printf( "%d\n", d[r][p-1][q-1] );

		}

	}



	return 0;

}