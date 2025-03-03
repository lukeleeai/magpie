	#include<iostream>

	#include<vector>

	using namespace std;

	#define LL	long long

	const int MAXN = 2e5+10;



	int N;

	int c[MAXN];

	vector<int> G[MAXN];

//	int tot = 0;

//	int head[MAXN], Next[MAXN], to[MAXN];



	// sub[i]: 顶点i下子树顶点的个数

	int sub[MAXN];

	// cnt[i]: 颜色为i的顶点下子树顶点的个数

	int cnt[MAXN]; 

	// ans[i]: 颜色为i的顶点下不经过颜色i的顶点数

	LL ans[MAXN];

	

	// 一开始起名count结果和c++ count()冲突，调试了半天, md

	inline LL cal(int n) {

		// C(n,2) + n

		return 1LL*n*(n+1)/2;

	}

	/*

	void dfs(int v, int fa) {

		int tmp = cnt[c[v]];

		sub[v] = 1;

		for(int i=head[v]; i; i=Next[i]) {

			int u = to[i];

			if(u == fa) continue;

			cnt[c[v]] = 0;	// 置0重新计数

			dfs(u, v);

			sub[v] += sub[u];

			ans[c[v]] += count(sub[u] - cnt[c[v]]);

		}

		cnt[c[v]] = tmp + sub[v];

	}

	void add(int a, int b) {

		++tot;

		Next[tot] = head[a];

		to[tot] = b;

		head[a] = tot;

	}

	*/

	void dfs(int v, int fa) {

		int tmp = cnt[c[v]];

		sub[v] = 1;

		for(int u:G[v]) {

			if(u==fa) continue;

			cnt[c[v]] = 0;

			dfs(u, v);

			sub[v] += sub[u];

			ans[c[v]]+=cal(sub[u]-cnt[c[v]]);

		}

		cnt[c[v]] = tmp + sub[v];

	}

	

	int main() {

		std::ios::sync_with_stdio(false);

		cin>>N;

		for(int i=1; i<=N; i++) {

			cin >> c[i];

		}

		int a, b;

		for(int i=1; i<N; i++) {

			cin>>a>>b;

			G[a].push_back(b);

			G[b].push_back(a);

		}

		//dfs1(1, 0);

		dfs(1, 0);

		for(int i=1; i<=N; i++) {

			cout << cal(N) - ans[i] - cal(N-cnt[i]) << endl;

		}

		return 0;

	}
