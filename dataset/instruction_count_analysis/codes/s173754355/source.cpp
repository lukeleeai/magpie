#include "stdc++.h"

using namespace std;

char ans [100] [100] ;

int main()

{

	int n , m , a , b;

	cin >> n >> m ;

	a = max (n , m) ;

	for (b = 0 ; b * b <= a ; b ++ )

	{

		a ;

	}

	n -- ;

	m -- ;

	b += 2 ;

	b = b * 4 - 1 ;

	

	for (int i = 0 ; i <= b ; i ++ )

	{

		

		for (int j =  0 ; j < b / 2; j ++ )

		{

			 if (n > 0  && i % 2 == 0)

			{

				if (j % 2 == 0)

				{

					ans [i] [j] = '.' ;

					n -- ;

				}

				else

				ans [i] [j] = '#' ;

			}

			else

			ans [i] [j] = '#' ;

		}

	}

	for (int i = 0 ; i <= b ; i ++ )

	{

		ans [i] [b / 2] = '#' ;

		ans [i] [b / 2 + 1] = '.' ;

	}

	for (int i = 0 ; i <= b ; i ++ )

	{

		

		for (int j = b / 2 + 2 ; j <= b ; j ++ )

		{

			 if (m > 0  && i % 2 == 0)

			{

				if (j % 2 == 0)

				{

					ans [i] [j] = '#' ;

					m -- ;

				}

				else

				ans [i] [j] = '.' ;

			}

			else

			ans [i] [j] = '.' ;

		}

	}

	cout << b + 1 << ' ' << b + 1<< endl ;

	for (int i =  0 ; i <= b ; i ++ )

	{for (int j = 0 ; j <= b ;  j ++ )

	cout << ans [i] [j] ;

	cout << endl ;

	}

}


