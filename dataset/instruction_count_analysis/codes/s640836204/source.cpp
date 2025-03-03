#include <iostream>

#include <cmath>

#include <vector>

#include <algorithm>

using namespace std;



int main(){ int n; long long a = 0;

	cin >> n;

	for (int i=0; i<=10000007; i++){

		a = (a*10+7)%n;

		if(a == 0){

			cout << i+1 << endl;

			return 0;

		}

	}

	cout << -1 << endl;

	return 0;

}