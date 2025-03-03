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

				if (l[h][i] && r[i][w])ans[h][w] = true;

				//ans[h][w] += l[h][i] * r[i][w];

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



struct node{

	int now;

	int from;

};



int main() {

	while (1) {



		int N, M, Z; cin >> N >> M >> Z;

		if (!N)break;

		vector<node>nodes;

		for (int i = 0; i < N; ++i) {

			nodes.push_back(node{ i,-1 });

		}

		

		vector<vector<int>>gyou(N +2* M, vector<int>(N +2*M));

		for (int i = 0; i < M; ++i) {

			int s, d; cin >> s >> d; s--; d--;

			nodes.push_back(node{ d,s });

			nodes.push_back(node{ s,d });

		}

		for (int i = 0; i < nodes.size(); ++i) {

			for (int j = 0; j < nodes.size(); ++j) {

				if (nodes[i].now == nodes[j].from&&nodes[i].from!=nodes[j].now) {

					gyou[j][i] = 1;

				}

			}

		}

		auto kakeru = powgyou<int>(gyou, Z);

		vector<vector<int>>start(N + 2*M,vector<int>(1));

		start[0][0] = true;

		

		vector<int>cango(N);

		vector<vector<int>>goal = keisann<int>(kakeru, start);

		for (int i = 0; i < N +2* M; ++i) {

			if (goal[i][0]) {

				cango[nodes[i].now] = true;

			}

		}

		if (cango[N - 1])cout << "yes" << endl;

		else cout << "no" << endl;





	}

	return 0;

}