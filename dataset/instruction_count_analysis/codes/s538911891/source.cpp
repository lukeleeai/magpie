#include<cmath>

#include<iostream>

#include<bitset>



#define MAX 10001



using namespace std;



int bComposite[MAX];



void ComputePrimes(){

	bComposite[1] = 1;

	for(int i = 4; i <= 10000; ++i){

		if( bComposite[ i ] == 0 ){

			for(int j = 2; j <= sqrt((double)i); ++j){

				if( i % j == 0 ){

					bComposite[ i ] = 1;

					break;

				}

			}

		}

		if( bComposite[ i ] == 0 ){

			for(unsigned int j = 2; i * j <= 10000; ++j){

				bComposite[ i * j ] = 1;

			}

		}

	}

}



int main()

{

	ComputePrimes();



	while( true )

	{

		int N, P = 0;

		

		cin >> N;



		if( cin.eof() )

			break;



		for(int i = 1; i <= N; ++i){

			if( !bComposite[N - i + 1] && !bComposite[ i ] )

				++P;

		}



		cout << P << '\n';

	}

	return 0;

}