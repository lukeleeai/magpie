#include "stdc++.h"

using namespace std;



int N, K, h, org;



int main () {

	cin >> N >> K;

	for (int i = 1; i <= N; i++){

		cin >> h;

		if (h >= K){

			org++;

		}

	}

	cout << org << endl;

}