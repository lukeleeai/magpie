#include <iostream>

#include <string>

#include <algorithm>

#include <vector>

#include <map>

using namespace std;

typedef long long  ll;

#define rep(i,s,n)for(ll i=s;i<n;i++)

#define repe(i,s,n)for(ll i=s;i<=n;i++)



ll a[100001];

int main()

{

	ll n; cin >> n;

	ll maxA = 0;

	rep(i, 0, n) {

		cin >> a[i];

		if (maxA <= a[i]) {

			maxA = a[i];

		}

	}



	ll minV = 1e20;

	ll minIndex = 0;

	rep(i, 0, n) {

		if (a[i] != maxA) {

			if (minV >= abs(2 * a[i] - maxA)) {

				minV = abs(2 * a[i] - maxA);

				minIndex = i;

			}

		}

	}

	cout << maxA << " " << a[minIndex] << endl;



	return 0;

}