#include "bits/stdc++.h"

#include<unordered_map>

#include<unordered_set>

#pragma warning(disable:4996)

using namespace std;

using ld = long double;

const ld eps = 1e-9;





template<typename T>

vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {

	vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));

	assert(l[0].size() == r.size());

	for (unsigned int h = 0; h < l.size(); ++h) {

		for (unsigned int i = 0; i < r.size(); ++i) {

			for (unsigned int w = 0; w < r[0].size(); ++w) {



				ans[h][w] |= l[h][i] * r[i][w];

			}

		}

	}

	return ans;

}



template<typename T>

vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {

	assert(a.size() == a[0].size());

	if (!n) {

		vector<vector<T>>e(a.size(), vector<T>(a[0].size()));

		for (unsigned int i = 0; i < a.size(); ++i) {

			e[i][i] = 1;

		}

		return e;

	}

	if (n == 1)return a;

	else {

		vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));

		ans = powgyou(a, n / 2);

		ans = keisann(ans, ans);

		if (n % 2) {

			ans = keisann(ans, a);

		}

		return ans;

	}

}





int main() {

	while (1) {

		int N, M, Z; cin >> N >> M >> Z;

		if (!N)break;

		vector<pair<int, int>>edges;

		edges.push_back(make_pair(-1, 0));

		for (int i = 0; i < M; ++i) {

			int s, d; cin >> s >> d; s--; d--;

			edges.push_back(make_pair(s, d));

			edges.push_back(make_pair(d, s));

		}

		vector<vector<int>>field(edges.size(), vector<int>(edges.size()));

		for (int i = 0; i < edges.size(); ++i) {

			for (int j = 0; j <edges.size(); ++j) {

				auto a = edges[i];

				auto b = edges[j];

				if (a.second == b.first&&a.first != b.second) {

					field[j][i] = true;

				}

			}

		}

		vector<vector<int>>start(edges.size(), vector<int>(1));

		start[0][0] = true;

		vector<vector<int>>kake = powgyou<int>(field, Z);

		vector<vector<int>>ans = keisann<int>(kake, start);

		bool ok = false;

		for (int i = 0; i <edges.size(); ++i) {

			if (edges[i].second == N - 1 && ans[i][0])ok = true;

		}

		if (ok)cout << "yes" << endl;

		else cout << "no" << endl;

	}

	return 0;

}