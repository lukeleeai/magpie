#include"stdc++.h"

using namespace std;

int n, fa[100007], sz[100007], dep[100007], hvs[100007], id[100007], pos[100007], tp[100007], cnt;

int t1[400007], t2[400007], tag[400007], re[100007][2];

vector<int>e[100007];

int read()

{

	int num = 0;

	char c = getchar();

	while (c < '0' || c>'9')c = getchar();

	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();

	return num;

}

int dfs1(int w, int f)

{

	sz[w] = 1;

	for(int i=e[w].size()-1;i>=0;i--)

		if (e[w][i] != f)

		{

			fa[e[w][i]] = w;

			dep[e[w][i]] = dep[w] + 1;

			dfs1(e[w][i], w);

			sz[w] += sz[e[w][i]];

			if (sz[e[w][i]] > sz[hvs[w]])hvs[w] = e[w][i];

		}

	return 0;

}

int dfs2(int w, int top)

{

	id[w] = ++cnt;

	pos[cnt] = w;

	tp[w] = top;

	if (hvs[w])dfs2(hvs[w], top);

	for (int i = e[w].size() - 1; i >= 0; i--)

		if (e[w][i] != fa[w] && e[w][i] != hvs[w])

			dfs2(e[w][i], e[w][i]);

	return 0;

}

int down(int w)

{

	if ((!tag[w]) && (!t2[w]))return 0;

	t1[2 * w] += tag[w];

	t1[2 * w + 1] += tag[w];

	tag[2 * w] += tag[w];

	tag[2 * w + 1] += tag[w];

	t2[2 * w] ^= t2[w];

	t2[2 * w + 1] ^= t2[w];

	tag[w] = 0;

	t2[w] = 0;

	return 0;

}

int up(int w)

{

	t1[w] = min(t1[2 * w], t1[2 * w + 1]);

	return 0;

}

int change(int w, int l, int r, int x, int y, int v1, int v2)

{

	if (x <= l && r <= y)

	{

		t1[w] += v2;

		t2[w] ^= v1;

		tag[w] += v2;

		return 0;

	}

	down(w);

	int mid = (l + r) / 2;

	if (x <= mid)change(2 * w, l, mid, x, y, v1, v2);

	if (y > mid)change(2 * w + 1, mid + 1, r, x, y, v1, v2);

	up(w);

	return 0;

}

pair<int,int>find(int w, int l, int r)

{

	if (l == r)return make_pair(l, t2[w]);

	down(w);

	int mid = (l + r) / 2;

	if (t1[2 * w] == 1)return find(2 * w, l, mid);

	else return find(2 * w + 1, mid + 1, r);

}

int main()

{

	n = read();

	for (int i = 1; i < n; i++)

	{

		int a = read(), b = read();

		e[a].push_back(b);

		e[b].push_back(a);

	}

	for (int i = 1; i < n; i++)

	{

		re[i][0] = read();

		re[i][1] = read();

	}

	dep[1] = 1;

	dfs1(1, 0);

	dfs2(1, 1);

	for (int i = 1; i < n; i++)

	{

		int a = re[i][0], b = re[i][1];

		while (tp[a] != tp[b])

		{

			if (dep[tp[a]] < dep[tp[b]])swap(a, b);

			change(1, 1, n, id[tp[a]], id[a], i, 1);

			a = fa[tp[a]];

		}

		if (dep[a] < dep[b])swap(a, b);

		if (id[b] != id[a])change(1, 1, n, id[b] + 1, id[a], i, 1);

	}

	change(1, 1, n, 1, 1, 0, 1000000000);

	for (int i = 1; i < n; i++)

	{

		if (t1[1] != 1)

		{

			cout << "NO" << endl;

			return 0;

		}

		pair<int, int>res = find(1, 1, n);

		int a = re[res.second][0], b = re[res.second][1];

		while (tp[a] != tp[b])

		{

			if (dep[tp[a]] < dep[tp[b]])swap(a, b);

			change(1, 1, n, id[tp[a]], id[a], res.second, -1);

			a = fa[tp[a]];

		}

		if (dep[a] < dep[b])swap(a, b);

		if (id[b] != id[a])change(1, 1, n, id[b] + 1, id[a], res.second, -1);

		change(1, 1, n, res.first, res.first, 0, 1000000000);

	}

	cout << "YES" << endl;

	return 0;

}