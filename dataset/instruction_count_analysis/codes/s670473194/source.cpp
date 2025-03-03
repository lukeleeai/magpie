#include<iostream>

#include<vector>

using namespace std;



int main() {

	int n;

	int v[100010] = { 0 };

	cin >> n;

	int s[100010];

	int t[100010] = { 0 };

	int sum = 0;

	for (int i = 1;i <= n;i++) {

		cin >> v[i];

		s[i - 1] = abs(v[i] - v[i - 1]);

		if (i > 1)t[i - 1] = abs(v[i] - v[i - 2]);

		sum += s[i - 1];

	}

	s[n] = abs(0 - v[n]);

	sum += s[n];

	t[n] = abs(0 - v[n - 1]);

	for (int i = 0;i < n;i++) {

		cout << sum - (s[i] + s[i + 1]) + t[i + 1] << endl;

	}

}