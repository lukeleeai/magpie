#include <memory.h>



#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <deque>

#include <iomanip>

#include <iostream>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <utility>

#include <vector>



using namespace std;



#define MOD 1000000007

#define INIT -1



int main() {

	int n;

	cin >> n;

	int a[100000];

	for (int i = 0; i < n; i++) {

		cin >> a[i];

	}

	sort(a, a + n);

	int suma[100010] = {};

	for (int i = 1; i <= n; i++) {

		suma[i] = suma[i - 1] + a[i - 1];

	}

	int ans = -MOD;

	int idx = -1;

	for (int i = 1; i < n; i++) {

		int tmp = suma[n] - suma[i] - suma[i];

		if (tmp > ans) {

			ans = tmp;

			idx = i;

		}

	}

	cout << ans << endl;

	int now = a[idx - 1];

	for (int i = idx; i < n - 1; i++) {

		cout << now << " " << a[i] << endl;

		now -= a[i];

	}

	cout << a[n - 1] << " " << now << endl;

	now = a[n - 1] - now;

	for (int i = 0; i < idx - 1; i++) {

		cout << now << " " << a[i] << endl;

		now -= a[i];

	}

}