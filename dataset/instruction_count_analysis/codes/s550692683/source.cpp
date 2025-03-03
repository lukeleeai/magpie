#include "stdc++.h"

using namespace std;



int main() {

	int n, m;

	cin >> n >> m;

	multiset<int, greater<int> > s;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; ++i) {

		int A, B;

		cin >> A >> B;

		v.push_back( { A, B });



	}

	int j = 0;

	sort(v.begin(), v.end());

	long long res = 0;

	for (int i = 1; i <= m; i++) {

		while (j < n && v[j].first == i) {

			s.insert(v[j].second);

			j++;

		}

		if (s.size()) {

			res += *s.begin();

			s.erase(s.begin());

		}

	}

	cout << res;

	return 0;

}

/*

 *

 * 1 4

 * 1 4

 * 1 2

 * 2 3

 * 2 2

 * 2 1

 * 3 3 j

 * 3 4

 * 3 1

 1=>  4 2

 2=>

 3=> 3 4 1 2 3 1 2

 4+4+4

 */
