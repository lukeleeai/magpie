#include<iostream>

using namespace std;

int main()

{

	int s[10] = {0}, i, a, n,j;

	while (1) {

		cin >> n;

		if (n == 0)

			break;

		for (i = 0; i < n; i++) {

			cin >> a;

			s[a]++;

		}

		for (i = 0; i < 10; i++) {

			if (s[i] == 0)

				cout << "-";

			else {

				for (j = 0; j < s[i]; j++) {

					cout << "*";

				}

			}

			cout << endl;

			s[i] = 0;

		}

	}

	return 0;

}