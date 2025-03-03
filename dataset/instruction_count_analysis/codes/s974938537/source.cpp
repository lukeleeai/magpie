#include "bits/stdc++.h"

#include<unordered_map>

#include<unordered_set>

#pragma warning(disable:4996)

using namespace std;

using ld = long double;

const ld eps = 1e-9;



//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

set<string>memo;

vector<string> dfs(string now, map<string, vector<string>>mp) {

	if (memo.find(now) != memo.end())return vector<string>();

	else memo.emplace(now);

	if (mp.find(now) == mp.end())return vector<string>(1,now);

	else {

		vector<string>ans;

		for (auto child : mp[now]) {

			auto sts=dfs(child,mp);

			ans.insert(ans.end(), sts.begin(), sts.end());

			sort(ans.begin(), ans.end());

			ans.erase(unique(ans.begin(), ans.end()), ans.end());

		}

		return ans;

	}

}



int main() {

	while (1) {

		memo.clear();

		int N; cin >> N;

		if (!N)break;

		map<string, vector<string>>mp;

		string start;

		for (int i = 0; i < N; ++i) {

			string st; cin >> st;

			int a = st.find(':');

			string parent = st.substr(0, a);

			if (!i)start = parent;

			vector<string>children;

			int from = a+1;

			while (1) {

				int r = st.find(',',from);

				if (r == string::npos) {

					children.push_back(st.substr(from,st.find('.')-from));

					break;

				}

				else {

					children.push_back(st.substr(from, r-from));

					from = r + 1;

				}

			}

			mp[parent] = children;

		}

		auto anss = dfs(start, mp);

		cout << anss.size() << endl;

	}

	return 0;

}