#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <map>

using namespace std;

typedef long long  ll;

#define rep(i,s,n)for(ll i=s;i<n;i++)

#define repe(i,s,n)for(ll i=s;i<=n;i++)



int main() {

	ll n; cin >> n;

	ll a[100000] = {};

	ll maxV = 0;

	rep(i, 0, n) {

		cin >> a[i];

		maxV = max(maxV, a[i]);

	}



	ll index = 0;

	ll minV = 1e20;

	rep(i, 0, n) {

		if (a[i] != maxV) {

			if (minV > abs(maxV - 2 * a[i])) {

				minV = abs(maxV - 2 * a[i]);

				index = i;

			}

		}

	}

	cout << maxV << " " << a[index] << endl;



	return 0;

}