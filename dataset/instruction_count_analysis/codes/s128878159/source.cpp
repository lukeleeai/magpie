#include <memory.h>



#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <deque>

#include <iomanip>

#include <iostream>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <utility>

#include <vector>



using namespace std;



#define mod 1000000007



int main() {

	int n;

	cin >> n;

	vector<vector<int> > graph(n * n);

	vector<int> indegree(n * n, 0);

	for (int i = 0; i < n; i++) {

		int preva = -1;

		for (int j = 0; j < n - 1; j++) {

			int a;

			cin >> a;

			a--;

			if (preva == -1) {

				preva = a;

				continue;

			}

			int prev = n * min(i, preva) + max(i, preva);

			int now = n * min(i, a) + max(i, a);

			graph[prev].push_back(now);

			indegree[now]++;

			preva = a;

		}

	}

	queue<int> qu;

	vector<int> result(n * n, -1);

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			if (indegree[n * i + j] == 0) {

				qu.push(n * i + j);

				result[n * i + j] = 1;

			}

		}

	}

	int ans = 1;

	while (!qu.empty()) {

		int now = qu.front();

		qu.pop();

		for (int i = 0; i < graph[now].size(); i++) {

			int next = graph[now][i];

			indegree[next]--;

			if (indegree[next] == 0) {

				qu.push(next);

				result[next] = result[now] + 1;

				ans = max(ans, result[next]);

			}

		}

	}

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			if (result[n * i + j] == -1) {

				cout << -1 << endl;

				return 0;

			}

		}

	}

	cout << ans << endl;

}