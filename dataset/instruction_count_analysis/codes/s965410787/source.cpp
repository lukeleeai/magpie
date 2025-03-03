#include <iostream>

#include <algorithm>

#include <cmath>



using namespace std;

int main() {

	long n;

	cin >> n;

	for (long i = n; ; i--) {

		if (floor(sqrt(i))*floor(sqrt(i)) == i) {

			cout << i << endl;

			break;

		}

	}

	

	return 0;

}