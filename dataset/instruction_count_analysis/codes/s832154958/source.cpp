#include <algorithm>

#include <climits>

#include <cmath>

#include <iomanip>

#include <iostream>

#include <list>

#include <map>

#include <set>

#include <sstream>

#include <string>

#include <vector>



#define endl '\n'

#define ull unsigned long long

#define ll long long

#define ul unsigned long

#define ld long double

#define PI 3.14159265359



using namespace std;



int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

	int t = 1;

	// cin >> t;

	while (t--) {

		int n;

		cin >> n;

		vector<int> v(n), c(n);

		for (auto &i : v) {

			cin >> i;

		}

		for (auto &i : c) {

			cin >> i;

		}

		int m = INT_MIN;

		int s = 0;

		for (int i = 0; i < n; i++) {

			if (v[i] > c[i])

				s += v[i] - c[i];

			m = max(m, s);

		}

		cout << m;

	}

}