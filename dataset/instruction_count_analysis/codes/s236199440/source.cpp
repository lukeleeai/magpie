#include"stdc++.h"

using namespace std;

int main(){

	int n , cont = 0;

	cin >> n;

	int arreglo[n];

	for(int i = 0 ; i < n ; i++){

		cin >> arreglo[i];

	}

	for(int i = 0 ; i < n ; i++){

		bool cuenta = true;

		for(int j = 0 ; j < i ; j++){

			if(arreglo[j] > arreglo[i]){

			   cuenta = false;

			}

		}

		if(cuenta) cont++;

	}

	cout << cont << endl;

	return 0;

}