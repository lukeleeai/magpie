#include "bits/stdc++.h"

#include<unordered_map>

#include<unordered_set>

#pragma warning(disable:4996)

using namespace std;

using ld = long double;

template<class T>

using Table = vector<vector<T>>;

const ld eps=1e-9;



//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"





struct aa {

	int now;

	int time;

	int use;

};

class Compare {

public:

	//aa?????????????????¶

	bool operator()(const aa&l, const aa&r) {

		return l.use> r.use;

	}

};

int main() {

	while (1) {

		int N, M, C; cin >> N >> M >> C;

		if (!N)break;

		vector<vector<int>>memo(N, vector<int>(M + 1,1e9));

		if (!N)break;

		vector < vector<pair<int, int>>>edges(N);

		for (int i = 0; i < M; ++i) {

			int f, t, c; cin >> f >> t >> c;

			f--; t--;

			edges[f].push_back(make_pair(t, c));

		}

		priority_queue<aa, vector<aa>, Compare>que;

		que.push(aa{ 0,0,0 });

		memo[0][0] = 0;

		int ans = -1;

		while (!que.empty()) {

			aa atop(que.top());

			if (atop.now == N - 1) {

				ans = atop.use;

				break;

			}

			que.pop();

			for (auto e : edges[atop.now]) {

				const int next = e.first;

				if (atop.time + e.second <= C) {

					if (memo[next][atop.use]>atop.time + e.second) {

						memo[next][atop.use] = atop.time + e.second;

						que.push(aa{ next,atop.time + e.second,atop.use });

					}

				}

				{

					if (memo[next][atop.use+1]>atop.time ) {

						memo[next][atop.use+1] = atop.time;

						que.push(aa{ next,atop.time,atop.use+1 });

					}

				}

			}

		}

		cout << ans << endl;



	}

	

	return 0;

}