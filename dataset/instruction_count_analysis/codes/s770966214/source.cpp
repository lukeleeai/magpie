#include "stdc++.h"

using namespace std;

const int MX = 1e5+3, MOD = 1e9+7;

int a[MX];

vector<int> pos[MX];

long long ans = 1;

int main() {

	ios::sync_with_stdio(0);cin.tie(0);

	int n, mxp = 0;

	cin >> n;

	for(int i=0; i<n; i++) {

		cin >> a[i];

		pos[a[i]].push_back(i);

		mxp = max(mxp, a[i]);

		if(pos[a[i]].size() > 3)

			return !(cout << 0);

	}

	for(int i=0; i<=mxp; i++) {

		if(pos[i].empty() || (i && pos[i-1].size() < pos[i].size()))

			return !(cout << 0);

	}

	ans = (pos[0].size() >= 2 ? 6 : 3);

	for(int i=1; i<=mxp; i++) {

		int p = 0;

		for(int t: pos[i]) {

			int cnt = 0;

			for(int s: pos[i-1]) {

				cnt += s < t;

			}

			if(cnt <= p)

				return !(cout << 0);

			ans *= (cnt - p);

			p++;

		}

		ans %= MOD;

	}

	cout << ans;

}