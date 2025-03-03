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

#include <cstring>



using namespace std;

using ll = long long;

typedef unsigned long long ull;

typedef pair<ll, ll> P;

typedef pair<double, double >pd;

typedef pair<string, string> sP;

typedef pair<ll, P> PP;

typedef pair<P, P> PPP;



const ll MOD = 1e9 + 7;

const ll MOD2 = 998244353;

const ll INF = 1 << 30;

const ll INF2 = 9e18;

const double INF3 = 5e14;

const double eps = 1e-10;

const double PI = acos(-1);

const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

const int tx[8] = { -1,-1,-1,0,0,1,1,1 }, ty[8] = { -1,0,1,-1,1,-1,0,1 };



#define ALL(x) (x).begin(),(x).end()

#define ALLR(x) (x).rbegin(),(x).rend()

#define pb push_back

#define eb emplace_back

#define fr first

#define sc second



ll h, w, ans = INF2;



int main() {

	cin >> h >> w;

	if (h % 3 == 0 || w % 3 == 0) {

		cout << 0 << endl;

		return 0;

	}

	ans = min(h, w);

	for (int i = 1;i < h;i++) {

		ll tp = i * w, l = (h - i)*(w / 2), r = (h - i)*(w - w / 2);

		ans = min(ans, max({ tp,l,r })-min({ tp, l, r }));

	}

	for (int i = 1;i < w;i++) {

		ll tp = i * h, l = (w - i)*(h / 2), r = (w - i)*(h - h / 2);

		ans = min(ans, max({ tp,l,r }) - min({ tp, l, r }));

	}

	cout << ans << endl;

	return 0;

}