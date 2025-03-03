#include <stdio.h>



int k[10000];



int main()

{



	int N, cnt, same, Not;



	while( 1 ) {



		cnt = 0;

		same = 0;

		Not = 0;



		for( int i = 0; i < 10000; i++ ) k[i] = 0;



	 	scanf( "%d", &N );

		if( N == 0 ) break;

		for( int i = 0; i < N; i++ ) {



			scanf( "%d", &k[i] );

			if( k[i] > 1 ) same++;

			else if( k[i] == 0 ) Not++;



		}



		if( N == 1 && k[0] >= 2 ) {

			printf( "2\n" );

			continue;

		}

		else if( same == 0 ) {

			printf( "NA\n" );

			continue;

		}



		printf( "%d\n", N + 1 - Not );



	}



	return 0;



}