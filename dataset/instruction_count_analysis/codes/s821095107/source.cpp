#include <iostream>

#include <string>

#include <iomanip>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <algorithm>



using namespace std;



#define drobucs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



int main() {

	drobucs;



	int n, d;

	cin >> n >> d;



	vector<vector<int>> v(n, vector<int>(d));



	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < d; ++j) {

			cin >> v[i][j];

		}

	}

	int cnt = 0;

	for (int i = 0; i < n - 1; ++i) {

		for (int j = i + 1; j < n; ++j) {

			int dist, sum = 0;

			for (int k = 0; k < d; ++k) {

				sum += pow((v[i][k] - v[j][k]), 2);

			}

			dist = sqrt(sum);

			if (dist * dist == sum) {

				cnt++;

			}

		}

	}



	cout << cnt;



	return 0;

}