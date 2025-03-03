#include<cstdio>

#include<iostream>

#include<cstdlib>

#include<cstring> 

#include<algorithm>

#include<queue>

#include<vector>

#include<ctime>

using namespace std;

typedef long long ll;

const int N = 200010;

ll read() {

	ll x = 0,f = 1;char c = getchar();

	while(c < '0' || c > '9') {

		if(c == '-') f = -1; c = getchar();

	}

	while(c >= '0' && c <= '9') {

		x = x * 10 + c - '0'; c = getchar();

	}

	return x * f;

}

struct node {

	int v,nxt;

}e[N << 1];

int du[N],ejs,head[N];

void add(int u,int v) {

	e[++ejs].v = v;e[ejs].nxt = head[u];head[u] = ejs;

}

int n,dis[N];

void dfs(int u,int fa) {

	for(int i = head[u];i;i = e[i].nxt) {

		int v = e[i].v;if(v == fa) continue;

		dis[v] = dis[u] + 1;

		dfs(v,u);

	}

}

int zj[N],tot;

bool get(int u,int fa,int T) {

	if(u == T) {

		zj[++tot] = T;

		return true;

	}

	for(int i = head[u];i;i = e[i].nxt) {

		int v = e[i].v;if(v == fa) continue;

		if(get(v,u,T)) {

			zj[++tot] = u;

			return true;

		}

	}

	return false;

}

int ans[N];

int main() {

	n = read();

	for(int i = 1;i < n;++i) {

		int u = read(),v = read();add(v,u);add(u,v);

		du[u]++;du[v]++;

	}

	

	dfs(1,0);

	int tmp = 0;

	for(int i = 1;i <= n;++i)

		if(dis[i] > dis[tmp]) tmp = i;

	dis[tmp] = 0;

	dfs(tmp,0);

	int tt = 0;

	for(int i = 1;i <= n;++i) 

		if(dis[i] > dis[tt]) tt = i;

	get(tmp,0,tt);

	

	int flag = 0;

	for(int i = 1;i <= tot;++i) {

		if(du[zj[i]] < du[zj[tot - i + 1]]) break;

		if(du[zj[i]] > du[zj[tot - i + 1]]) {

			flag = 1;break;

		}

	}

	if(flag) {

		for(int i = 1;i <= tot / 2;++i) swap(zj[i],zj[tot - i + 1]);

	}

	

	int pos = 0,now = 0;

	

	ans[++pos] = ++now;

	for(int i = 2;i < tot;++i) {

		int tmp = ++now;

		for(int j = 1;j < du[zj[i]] - 1;++j) ans[++pos] = ++now;

		ans[++pos] = tmp;

	}

	ans[++pos] = ++now;

	if(pos != n) {

		puts("-1");return 0;

	}

	for(int i = 1;i <= pos;++i) printf("%d ",ans[i]);

	return 0;

}
