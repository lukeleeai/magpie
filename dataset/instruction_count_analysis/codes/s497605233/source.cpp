#include <cstdio>

#include <iostream>

#include <cmath>

#include <cstring>

#include <sstream>

#include <algorithm>

#include <cstdlib>

#include <map>

#include <queue>

#include <utility>

#include <vector>

#include <set>

#include <memory.h>

#include <iomanip>

#include <bitset>

#include <list>

#include <stack>

#include <deque>

#include <numeric>



using namespace std;



#define mod 1000000007





int n;

vector<vector<int> > graph;

map<pair<int, int>, int> pairToNodeId;



vector<bool> ischecked_dfs(1000001, false);

vector<bool> passed(1000001, false);



bool hasloop_dfs(int now)

{

	for(int i = 0; i < graph[now].size(); i++){

		int next = graph[now][i];

		if(passed[next]) return true;

		if(ischecked_dfs[next]) continue;

		passed[next] = true;

		if(hasloop_dfs(next)) return true;

		passed[next] = false;

	}

	ischecked_dfs[now] = true;

	return false;

}



bool hasloop()

{

	for(int i = 0; i < graph.size(); i++){

		if(ischecked_dfs[i]) continue;

		passed[i] = true;

		if(hasloop_dfs(i)) return true;

		passed[i] = false;

	}

	return false;

}



vector<int> result_dfs(1000001, -1);



int getMaxPath_dfs(int now)

{

	if(result_dfs[now] > 0) return result_dfs[now];

	int ans = 1;

	for(int i = 0; i < graph[now].size(); i++){

		int next = graph[now][i];

		ans = max(ans, getMaxPath_dfs(next) + 1);

	}

	return result_dfs[now] = ans;

}



int getMaxPath()

{

	int ans = 0;

	for(int i = 0; i < graph.size(); i++){

		ans = max(ans, getMaxPath_dfs(i));

	}

	return ans;

}



int getNodeId(int i, int j)

{

	if(j < i) swap(i, j);

	return pairToNodeId[make_pair(i, j)];

}



int main()

{

	cin >> n;

	int cnt = 0;

	for(int i = 1; i <= n; i++){

		for(int j = i + 1; j <= n; j++){

			pairToNodeId[make_pair(i, j)] = cnt;

			cnt++;

		}

	}

	graph = vector<vector<int> >(cnt);

	for(int i = 1; i <= n; i++){

		int pre_a;

		cin >> pre_a;

		for(int j = 1; j < n - 1; j++){

			int a;

			cin >> a;

			// i vs pre_a の試合は i vs a より早く行われる

			graph[getNodeId(i, pre_a)].push_back(getNodeId(i, a));

			pre_a = a;

		}

	}



	if(hasloop()) cout << -1 << endl;

	else cout << getMaxPath() << endl;

}