#include<algorithm>

#include<iostream>



const int INF = 1 << 29;



int n, m;

int d[2][3000][3000];



int main()

{

	while( std::cin >> n >> m, n | m )

	{

		for( int i = 0; i != n; ++i )

			for( int j = 0; j != n; ++j )

				for( int k = 0; k != 2; ++k )

					d[k][i][j] = i == j ? 0 : INF;



		for( int i = 0; i != n; ++i )

		{

			int a, b, c, t;

			std::cin >> a >> b >> c >> t;

			d[0][a-1][b-1] = d[0][b-1][a-1] = c;

			d[1][a-1][b-1] = d[1][b-1][a-1] = t;

		}



		for( int k = 0; k != m; ++k )

			for( int i = 0; i != m; ++i )

				for( int j = 0; j != m; ++j )

					for( int l = 0; l != 2; ++l )

						d[l][i][j] = std::min( d[l][i][j], d[l][i][k] + d[l][k][j] );



		int k;

		std::cin >> k;

		while( k-- )

		{

			int p, q, r;

			std::cin >> p >> q >> r;



			std::cout << d[r][p-1][q-1] << std::endl;

		}

	}



	return 0;	

}