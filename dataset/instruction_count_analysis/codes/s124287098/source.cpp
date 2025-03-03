#include <iostream>

using namespace std;



int main()

{

	const int MaxVal = 2000000;

	int n = 0;

	int A[MaxVal] = { 0 };

	cin >> n;

	int maxTemp =0;

	int nextTemp = 0;

	int topIndex = 0;

	for (int i =0; i < n; ++i) {

		cin >> A[i];

		if (maxTemp < A[i]) {

			nextTemp = maxTemp;

			maxTemp = A[i];

			topIndex = i;

		} else {

			if (nextTemp < A[i]) {

				nextTemp = A[i];

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