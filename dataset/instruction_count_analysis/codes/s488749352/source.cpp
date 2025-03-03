#include <iostream>

#include <algorithm>

#include <set>

#include <string>

#pragma warning (disable:4996)

using namespace std;





int main() {

	set<string> s;

	int n;

	string a;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> a;

		s.insert(a);

	}

	cout << s.size();



}