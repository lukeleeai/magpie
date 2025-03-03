#include<iostream>

using namespace std;

typedef long long ll;

const int N = 301;

int a[N][N];

ll sum;

int main() {

	int n;



	cin >> n;

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= n; j++)

			cin >> a[i][j];



	for(int i=1;i<=n;i++)

		for (int j = i; j <= n; j++) {

			bool temp = true;

			for (int k = 1; k <= n; k++) {

				if (k == i || k == j)

					continue;

				if (a[i][k] + a[k][j] < a[i][j]) {

					cout << -1 << endl;

					return 0;

				}

				if (a[i][k] + a[k][j] == a[i][j])

					temp = false;

			}

			if (temp)

				sum += a[i][j];

		}



	cout << sum << endl;



	return 0;

}