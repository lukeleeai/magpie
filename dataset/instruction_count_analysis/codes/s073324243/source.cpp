#include <iostream>

#include <algorithm>

#include <cmath>

#include <map>

#include <vector>

#include <queue>

#include <functional>

#include <string>

#include <stack>

#include <set>

#include <sstream>

#include <iomanip>

#include <limits>

using namespace std;

using ll = long long;

typedef unsigned long long ull;

typedef pair<ll, ll> P;

typedef pair<ll, pair<ll, ll>> PP;



const ll MOD = 1e9 + 7;

const ll MOD2 = 998244353;

const ll INF = 1 << 30;

const ll INF2 = 9e18;

const double INF3 = 9e14;

const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

#define ALL(x) (x).begin(),(x).end()

#define pb push_back

#define fr first

#define sc second







int main() {

	ll n, x, a[4010], ans = INF2, d[4010];

	cin >> n >> x;

	for (int i = 0;i < n;i++)cin >> a[i], a[i + n] = a[i], d[i] = INF2;

	for (int i = 0;i < n;i++) {

		ll sum = 0;

		for (int j = 0;j < n;j++) {

			d[j] = min(d[j], a[j + n - i]);

			sum += d[j];

	    }

		ans = min(ans, sum + i * x);

	}

	cout << ans << endl;

	return 0;

}