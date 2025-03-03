#include <algorithm>

#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <cctype>

#include <queue>

#include <map>

#include <string>

#include <vector>

#include <set>

#include <math.h>

#include <stack>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#define ll long long

#define chushihua(x,y) memset(x,y,sizeof x)

using namespace std;

const int MAXX = 100000 + 10;

const double PI = 3.14159265358979323846;

const ll mod = 1000000007;

int main() {

	int t;

	ll n, m;

	ll sum = 0;

	while (cin >> t) {

		int flag = 0;

		ll minn = 0x3f3f3f3f;

		for (ll i = 0; i < t; i++) {

			scanf("%I64d%I64d", &n, &m);

			sum += n;

			if (n > m) {

				minn = min(m, minn);

			}

			if (n != m) {

				flag = 1;

			}

		}

		//cout << minn << endl;

		if (!flag) {

			cout << "0" << endl;

		}

		else {

			cout << sum - minn << endl;

		}

	}

	return 0;

}