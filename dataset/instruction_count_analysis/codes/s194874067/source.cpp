#include <cstdio>

#include <vector>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;

const int maxn = 200005;

int n, fa[maxn], sg[maxn], pos = 1, tot, maxi = -1, mini = 0x3f3f3f3f;

bool vis[maxn], bucket[maxn];

vector<int> e[maxn];

void dfs(int u) {

	for(auto v : e[u]) 

		if(!vis[v]) dfs(v);

	for(auto v : e[u])

		if(!vis[v]) bucket[sg[v]] = true;

	while(bucket[sg[u]]) ++sg[u];

	for(auto v : e[u])

		if(!vis[v]) bucket[sg[v]] = false;

}

int main() {

	ios :: sync_with_stdio(false);

	cin >> n;

	for(int i = 1; i <= n; ++i)

		cin >> fa[i], e[fa[i]].push_back(i);

	while(!vis[pos]) vis[pos] = true, pos = fa[pos];

	memset(vis, 0, sizeof vis);

	while(!vis[pos]) vis[pos] = true, pos = fa[pos], ++tot;

	if(tot & 1) for(int i = 1; i <= n; ++i)

		if(vis[i]) dfs(i), maxi = max(maxi, sg[i]), mini = min(mini, sg[i]);

	puts(tot & 1 and maxi == mini ? "IMPOSSIBLE" : "POSSIBLE");

}