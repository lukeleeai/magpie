#include<cmath>

#include<iostream>

#include<bitset>



#define MAX 10001



using namespace std;



bitset<MAX> b1;



void ComputePrimes(){

	b1.set();



	b1.reset(1);

	for(int i = 4; i <= 10000; ++i){

		for(int j = 2; j <= sqrt((double)i); ++j){

			if( i % j == 0 ){

				b1.reset( i );

				break;

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

			if( b1[N - i + 1] == true && b1[ i ] == true )

				++P;

		}



		cout << P << '\n';

	}

	return 0;

}