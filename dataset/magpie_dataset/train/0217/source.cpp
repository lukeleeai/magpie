#include <iostream>

#include <vector>

using namespace std;



int main(){

	int n, k, s, b;

	

	while( cin >> n >> k , n || k ){

		vector<int> S;

		for(int i=0 ; i<k ; i++ ){

			cin >> s;

			S.push_back(s);

		}

		for(int i=0 ; i<n ; i++ ){

			for(int j=0 ; j<k ; j++ ){

				cin >> b;

				S[j] -= b;

			}

		}

		bool flag = true;

		for(int i=0 ; i<k ; i++ ){

			if( S[i] < 0 ){

				flag = false;

			}

		}

		cout << ( (flag)? "Yes" : "No" ) << endl;

	}

}