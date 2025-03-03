#include <iostream>

using namespace std;



int main()

{

	int n = 0;

	cin >> n;

	int maxTemp =0;

	int nextTemp = 0;

	int topIndex = 0;

	int temp = 0;

	for (int i =0; i < n; ++i) {

		cin >> temp;

		if (maxTemp < temp) {

			nextTemp = maxTemp;

			maxTemp = temp;

			topIndex = i;

		} else {

			if (nextTemp < temp) {

				nextTemp = temp;

			}

		}

	}

	for (int i = 0; i < n; ++i) {

		if (i == topIndex) {

			cout << nextTemp << endl;

		} else {

			cout << maxTemp << endl;

		}

	}



	return 0;

}