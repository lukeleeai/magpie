#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

#define LL long long

#define L (x << 1)

#define R (x << 1 | 1)

#define N 100110

using namespace std;

vector<int> edge[N];

vector<int> mark[N], query[N];

int n, m;

struct Tree{

	struct node{

		int v;

	}tr[N * 3];

	void init(){

		memset(tr, 0, sizeof(tr));

	}

	void update(int x){

		tr[x].v = max(tr[L].v, tr[R].v);

	}

	void modify(int x, int a, int b, int pos, int ad){

		if(a == b){

			tr[x].v = ad;

			return;

		}

		int mid = a + b >> 1;

		if(pos <= mid) modify(L, a, mid, pos, ad);

		else modify(R, mid + 1, b, pos, ad);

		update(x);

	}

	int query(int x, int a, int b, int l, int r){

		if(l <= a && b <= r) return tr[x].v;

		int mid = a + b >> 1;

		if(r <= mid) return query(L, a, mid, l, r);

		else if(l > mid) return query(R, mid + 1, b, l, r);

		else return max(query(L, a, mid, l, r), query(R, mid + 1, b, l, r));

	}

}sg;



LL ans = 0;

int list[N];

int pos[N], f[N];

void dfs(){

	int u = 1, d = 1;

	for(int i = 1; i <= n; i ++) pos[i] = 0;

	while(1){

		list[d] = u;

		for(int i = 0; i < mark[u].size(); i ++){

			int _index = mark[u][i];

			sg.modify(1, 1, m, _index, d);

		}

		for(int i = 0; i < query[u].size(); i ++){

			int _index = query[u][i];

			int id = sg.query(1, 1, m, 1, _index);

			ans = ans + list[id];

			//cout << u << ' ' << id << ' ' << list[id] << endl;

		}

		if(pos[u] < edge[u].size()){

			u = edge[u][pos[u] ++];

			d ++;

		}

		else{ 

			while(1){

				if(pos[u] < edge[u].size() || u == 1) break;

				for(int i = 0; i < mark[u].size(); i ++){

					int _index = mark[u][i];

					sg.modify(1, 1, m, _index, 0);

				}

				u = f[u];

				d --;

			}

			if(pos[u] < edge[u].size()){

				u = edge[u][pos[u] ++];

				d ++;

			}

			else break;

		}

	}

}

void solve(){

	ans = 0;

	for(int i = 1; i <= n; i ++){

		edge[i].clear();

		query[i].clear();

		mark[i].clear();

	}

	for(int i = 2; i <= n; i ++){

		scanf("%d", &f[i]);

		edge[f[i]].push_back(i);

	}

	

	mark[1].push_back(1);

	m ++;

	for(int i = 2; i <= m; i ++){

		char str[2];

		int v;

		scanf("%s%d", str, &v);

		if(str[0] == 'Q') query[v].push_back(i);

		else mark[v].push_back(i);

	}

	

	sg.init();

	dfs();

	

	printf("%lld\n", ans);

}

int main(){

	while(scanf("%d%d", &n, &m) == 2 && n + m){

		solve();

	}

	return 0;

}