#include "stdc++.h"



using namespace std;



struct segtree

{

	vector<int> t;

	segtree(int n) :t(n * 2 - 1, 0) {}

	void add(int a, int b, int o, int l, int r)

	{

		if (a >= r || b <= l)

			return;

		if (a <= l && b >= r) {

			t[o]++;

			return;

		}

		int m = (l + r) / 2;

		add(a, b, o + 1, l, m);

		add(a, b, o + (m - l) * 2, m, r);

	}

	int min(int o, int l, int r)

	{

		if (l + 1 == r)

			return t[o];

		int m = (l + r) / 2;

		int p = min(o + 1, l, m);

		int q = min(o + (m - l) * 2, m, r);

		return max(p, q) + t[o];

	}

};



pair<int, pair<int, int>> p[111111];

int main()

{

	int N, C;

	cin >> N >> C;

	for (int i = 0; i < N; i++)

		scanf("%d%d%d", &p[i].second.first, &p[i].second.second, &p[i].first);

	sort(p, p + N);

	segtree s(111000);

	int c = 0, d = 0;

	for (int i = 0; i < N; i++) {

		if (p[i].first != c || p[i].second.first != d) {

			c = p[i].first;

			s.add(p[i].second.first - 1, p[i].second.first, 0, 0, 111000);

		}

		d = p[i].second.second;

		s.add(p[i].second.first, p[i].second.second, 0, 0, 111000);

	}

	cout << s.min(0, 0, 111000) << endl;

	return 0;

}
