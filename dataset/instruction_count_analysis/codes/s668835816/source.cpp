#include <cstdio>

#include <cstring>

#include <algorithm>

#include <iostream>

using namespace std;



typedef long long ll;

const int maxn = 100000;



int n;

long long a[maxn], b[maxn];



int main(void) {

	cin >> n;

	for(int i = 0; i < n; ++i) {

		cin >> a[i] >> b[i];

	}

	long long add = 0;

	for(int i = n-1; i >= 0; --i) {

		a[i] += add;

		if(a[i] % b[i]) {

			add += b[i] - a[i] % b[i];

		}

	}

	cout << add << endl;

	return 0;

}