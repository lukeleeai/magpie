#include <iostream>

using namespace std;



int main(){

	int k,c,a;

	

	while( cin >> k , k ){

		a = 0;

		for(int i=0 ; i < k*(k-1)/2 ; i++ ){

			cin >> c;

			a += c;

		}

		cout << ( a / (k-1) ) << endl;

	}

}