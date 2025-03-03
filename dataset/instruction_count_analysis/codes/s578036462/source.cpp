#include "bits/stdc++.h"

#include<unordered_map>

#pragma warning(disable:4996)

using namespace std;

using ld = long double;

template<class T>

using Table = vector<vector<T>>;



struct aa {

	int now;

	int rest;

	int time;

};



class Compare {

public:

	//aa?????????????????¶

	bool operator()(const aa&l, const aa&r) {

		return l.time> r.time;

	}

};

int N, M;

int C;



bool check(const vector < vector<pair<int, int>>>&edges, int time) {

	int memo[100][101];

	for (int i = 0; i < 100; ++i) {

		for (int j = 0; j < 101; ++j) {

			memo[i][j] = 999999999;

		}

	}

	memo[0][time] = 0;

	priority_queue<aa, vector<aa>, Compare>que;

	que.push(aa{ 0,time });



	while (que.size()) {

		aa atop(que.top());

		if (atop.time > C)return false;

		if (atop.now == N - 1)return true;

		que.pop();

		for (const auto&e : edges[atop.now]) {

			if(atop.rest){

				int nexttime = atop.time;

				int nextplace = e.first;

				if (memo[nextplace][atop.rest - 1]>nexttime) {

					memo[nextplace][atop.rest - 1] = nexttime;

					que.push(aa{ nextplace,atop.rest - 1,nexttime });

				}

			}

			 {

				int nexttime = atop.time+e.second;

				int nextplace = e.first;

				if (memo[nextplace][atop.rest]>nexttime) {

					memo[nextplace][atop.rest] = nexttime;

					que.push(aa{ nextplace,atop.rest,nexttime });

				}

			}

		}

	}

	return false;

}

int main() {

	while (1) {

		 cin >> N >> M >> C;

		if (!N)break;

		vector<vector<pair<int,int>>>edges(N);

		for (int i = 0; i < M; ++i) {

			int f, t, c; cin >> f >> t >> c;

			f--; t--;

			edges[f].push_back(make_pair(t, c));

		}

		int amin = 0;

		int amax = 101;

		while (amin + 1 != amax) {

			int amid = (amin + amax) / 2;

			if (check(edges,amid)) {

				amax = amid;

			}

			else {

				amin = amid;

			}

		}

		if (check(edges, 0))amax = 0;

		cout << amax << endl;

	}

	return 0;

}