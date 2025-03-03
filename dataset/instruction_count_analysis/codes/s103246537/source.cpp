#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <iostream>

#include <set>

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;



const int KN = 305;



int n, m, a[KN][KN], pos[KN][KN], cnt[KN];



set<pii> S[KN];



bool check(int mid) {

	for (int i = 1; i <= n; ++i) {

		S[i].clear();

		for (int j = 1; j <= m; ++j) 

			S[i].insert(make_pair(j, a[i][j]));

	}

	int idx;

	for (int k = 1; k < m; ++k) {

		bool can = true;

		memset(cnt, 0x00, sizeof cnt);

		for (int i = 1; i <= n; ++i)

			++cnt[S[i].begin()->second];

		for (int i = 1; i <= m; ++i)

			if (cnt[i] > mid)

				can = false, idx = i;

		if (can)

			return true;

		for (int i = 1; i <= n; ++i)

			S[i].erase(make_pair(pos[i][idx], idx));

	}

	return false;

}



int main() {

	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)

		for (int j = 1; j <= m; ++j) {

			cin >> a[i][j];

			pos[i][a[i][j]] = j;

		}

	int low = 0, high = n, ans = high;

	while (low <= high) {

		int mid = (low + high) >> 1;

		if (check(mid))

			ans = mid, high = mid - 1;

		else low = mid + 1;

	}

	cout << ans << endl;

	return 0;

}