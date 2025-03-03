#include <iostream>

#include <vector>



using namespace std;



int main() {

	int n, p;

	while (cin >> n >> p && (n || p)) {

		vector<int> a(n, 0);

		int i = 0, num = p;

		while (1) {

			if (p != 0) {

				a[i]++;

				p--;

				if (a[i] == num) {

					cout << i << endl;

					break;

				}

			} else if (a[i] != 0) {

				p = a[i];

				a[i] = 0;

			}

			i++;

			if (i >= n) i = 0;

		}

	}

	return 0;

}
