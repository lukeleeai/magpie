#include<iostream>

#include<algorithm>

#include<string>

#include<cstdlib>

#include<map>

#include<iomanip>

#include<sstream>

#include<vector>

#include<stack>

#include<math.h>

using namespace std;



//ユークリッドの互除法　a,bは最大公約数を求めたい２つの数

long long int gcd(long long int a, long long int b) {

	long long int tmp;

	long long int r = 1;

	if (b > a) {

		tmp = a;

		a = b;

		b = tmp;

	}

	r = a % b;

	while (r != 0) {





		a = b;

		b = r;

		r = a % b;



	}

	return b;

}





int main() {

	map<long long int, long long int>mp;

	//cout << fixed << setprecision(10);

	long long int n, m,v[200005],c[200005];

	long long dp[200005] = {}, dp2[200005] = {}, res = 0, cou = 0, memo, memo2;

	string str, str2;

	cin >> n;



	for (int i = 0; i < n; i++) {

		cin >> v[i];

		

	}

	memo = v[0];

	memo2 = v[1];

	if (n == 2) {

		cout << max(v[0], v[1]);

		return 0;

	}



	for (int i = 0; i < n; i++) {

		if (v[i] == memo) {

			cou++;

		}



	}



	if (cou== n-1) {

		cout << v[0];

		return 0;

	}

	cou = 0;

	for (int i = 0; i < n; i++) {

		if (v[i] == memo2) {

			cou++;

		}



	}



	if (cou == n - 1) {

		cout << v[1];

		return 0;

	}





	dp[0] = v[0];

	dp2[n - 1] = v[n - 1];

	for (int i = 1; i < n; i++) {

		dp[i] = gcd(dp[i - 1], v[i]);

		dp2[n - i - 1] = gcd(dp2[n - i], v[n - i-1]);

	}

	res = max(dp[n-2],dp2[1]);

	for (int i = 0; i < n-2; i++) {

		res = max(gcd(dp[i], dp2[i + 2]),res);

	}







	cout << res;

}
