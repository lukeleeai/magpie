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

		int n, a, b;

		cin >> n >> a >> b;

		cout << ((b - a) & 1 ? "Borys" : "Alice");

	}

}