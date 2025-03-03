#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(n);++i)

#define rrep(i,n) for(int i=1;i<(n);++i)

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),(a).rend()

#define maxs(a, b) a = max(a, b)

#define mins(a, b) a = min(a, b)

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

const ll linf = (1LL << 61);

const int inf = 1001001001;

const int mod = 1000000007;



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	int n;

	cin >> n;

	vector<int> v(n);

	rep(i, n) cin >> v[i];

	vector<P> a, b;

	map<int, int> c, d;

	rep(i, n) {

		if (i % 2 == 0) c[v[i]]++;

		else d[v[i]]++;

	}

	for (auto p : c) a.emplace_back(p.second, p.first);

	for (auto p : d) b.emplace_back(p.second, p.first);

	sort(rall(a)); sort(rall(b));

	if (a.front().second == b.front().second) {

		int ans = a.front().first;

		if (a.size() == 1 && b.size() == 1) {

			cout << n / 2 << endl;

			return 0;

		}

		if (a[1].first >= b[1].first) {

			ans += a[1].first;

		}

		else {

			ans += b[1].first;

		}

		cout << n - ans << endl;

	}

	else {

		int ans = a.front().first + b.front().first;

		cout << n - ans << endl;

	}

	return 0;

}