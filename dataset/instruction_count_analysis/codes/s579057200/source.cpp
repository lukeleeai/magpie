#include <cstdio>

int d[100005];

int main()

{

	int n;

	while ( ~scanf( "%d", &n ) )

	{

		int a = 0, b = 0, c = 0;

		for ( int i = 0; i < n; i++ )

		{

			scanf( "%d", d+i );

			if ( d[i]%4==0 )

				a++;

			else if ( d[i]%2==0 )

				b++;

			else

				c++;

		}

		if ( b )

			c++;

		if ( a - c >= -1 )

			printf( "Yes\n" );

		else

			printf( "No\n" );

	}

}
