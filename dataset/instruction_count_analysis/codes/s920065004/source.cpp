

#include<iostream>

#include<vector>

#include<map>

#include<algorithm>

using namespace std;

int a[200005];

map<int, int>m;// [200005];//就相当于是int m[200005];

vector<int> g[200005];

int vis[200005]={0};

int maxn = 0;

int dfs(int i, int ans) {

	if(vis[i]!=0)return ans;

	for (int j = 0; j<g[i].size(); j++)

	{

		//if(!vis[i])

		ans = max(dfs(g[i][j], ans) + 1, ans);

	}

	vis[i]=ans;

	return ans;

}

int main() {

	int n; cin >> n;

	int x;

	for (int i = 1; i <= n; i++) {

		cin >> x;

		m[x] = i;

	}

	for (int i = 1; i <= n; i++) {

		if (m[i]<m[i + 1])

			//如果 i+1的下标比i要大, 就是在他后面

			g[i].push_back(i + 1);

	}

	//建图完毕

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		ans = max(ans, dfs(i, 1));

	}

	cout << (n-ans)<<endl;//(最长的)

	return 0;

}
