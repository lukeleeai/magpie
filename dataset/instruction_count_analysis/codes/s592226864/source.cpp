#include <cstdio>

#include <iostream>

#include <cmath>

#include <cstring>

#include <sstream>

#include <algorithm>

#include <cstdlib>

#include <map>

#include <queue>

#include <utility>

#include <vector>

#include <set>

#include <memory.h>

#include <iomanip>

#include <bitset>

#include <list>

#include <stack>

#include <deque>

#include <numeric>

#include <complex>



using namespace std;



#define mod 1000000007



int main()

{

	int n;

	cin >> n;

	int a[100001] = {};

	for(int i = 0; i < n; i++){

		cin >> a[i];

	}

	sort(a, a + n);



	if(n == 2){

		cout << a[1] - a[0] << endl;

		cout << a[1] << " " << a[0] << endl;

		return 0;

	}



	long long int suma[100001] = {};

	for(int i = 1; i <= n; i++){

		suma[i] = suma[i - 1] + a[i - 1];

	}

	long long int ans = -mod;

	int max_i = 0;

	for(int i = 1; i < n; i++){

		long long int tmp = (suma[n] - suma[i]) - suma[i];

		if(tmp > ans){

			ans = tmp;

			max_i = i;

		}

	}

	// cout << max_i << endl;

	// 0 ... max_i - 1 まではマイナス

	// max_i, ... , n - 1 はプラス

	cout << ans << endl;

	if(max_i == n - 1){

		long long int now = a[n - 1];

		for(int i = n - 2; i >= 0; i--){

			cout << now << " " << a[i] << endl;

			now -= a[i];

		}

		return 0;

	}

	cout << a[0] << " " << a[max_i] << endl;

	long long int now = a[0] - a[max_i];

	for(int i = max_i + 1; i < n - 1; i++){

		cout << now << " " << a[i] << endl;

		now -= a[i];

	}

	cout << a[n - 1] << " " << now << endl;

	now = a[n - 1] - now;

	for(int i = max_i - 1; i >= 1; i--){

		cout << now << " " << a[i] << endl;

		now -= a[i];

	}



}