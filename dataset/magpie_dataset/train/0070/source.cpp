#include <iostream>

using namespace std;



int main(){

	int n;

	while( cin >> n , n ){

		int ice[10] = {};

		for(int i=0 ; i<n ; ++i ){

			int a;

			cin >> a;

			ice[a]++;

		}

		for(int i=0 ; i<10 ; ++i ){

			for(int j=0 ; j<ice[i] ; ++j ){

				cout << "*";

			}

			if(!ice[i]) cout << "-";

			cout << endl;

		}

	}

}