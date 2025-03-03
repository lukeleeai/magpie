#include <vector>

#include <iostream>

#include <algorithm>

#include <string>

using namespace std;



int main()

{

	int n = 0;

	int k = 0;

	string str;

	int origin = 0;

	cin >> n;

	cin >> k;

	cin >> str;

	for (int i = 0; i < n - 1; ++i) {

		if (str[i] == str[i + 1]) { ++origin; }

	}

	cout << min(origin + 2 * k, n - 1);

}