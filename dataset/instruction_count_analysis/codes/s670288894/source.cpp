#include "stdc++.h"

using namespace std;



int n, m, r;

vector<int> t1[114514], t2[114514], t3(114514);



void bfs(int s) {

	queue<pair<int, int> > q;

	vector<int> d(114514, -1), v(114514, 0);

	q.push(make_pair(s, 0));

	

	t3[s] = -1;

	d[s] = 0;

	

	while (!q.empty()) {

		pair<int, int> p = q.front(); q.pop();

		

		for (int i = 0; i < t2[p.first].size(); i++) {

			bool flag = true;

			

			v[t2[p.first][i]]++;

			

			/*for (int j = 0; j < t1[t2[p.first][i]].size(); j++) {

				//cout << t2[p.first][i] << ':' << t1[t2[p.first][i]][j] << ':' << d[t1[t2[p.first][i]][j]] << ':' << endl;

				if (t1[t2[p.first][i]][j] != p.first && d[t1[t2[p.first][i]][j]] == -1) {

					flag = false;

					break;

				}

			}*/

			

			if (v[t2[p.first][i]] != t1[t2[p.first][i]].size()) continue;

			

			//cout << p.first << ' ' << t2[p.first][i] << endl;

			

			d[t2[p.first][i]] = p.second + 1;

			t3[t2[p.first][i]] = p.first;

			q.push(make_pair(t2[p.first][i], p.second + 1));

		}

	}

}



int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n - 1 + m; i++) {

		int a, b;

		cin >> a >> b;

		a--; b--;

		t1[b].push_back(a);

		t2[a].push_back(b);

	}

	for (int i = 0; i < n; i++) {

		if (t1[i].size() == 0) r = i;

	}

	bfs(r);

	for (int i = 0; i < n; i++) {

		cout << t3[i] + 1<< endl;

	}

}