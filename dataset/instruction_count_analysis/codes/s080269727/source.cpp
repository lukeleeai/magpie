#include <cstdio>

#include <vector>

#include <map>

#define N 200005

using namespace std;

int n, k, l, num, u[N], v[N];

vector<int> a[N], b[N];

map<pair<int,int>,int> mp;



void f(int p, int q) {

	if(u[p]) return;

	u[p] = q;

	for(int i=0; i<a[p].size(); i++) {

		f(a[p][i], q);

	}

}



void g(int p, int q) {

	if(v[p]) return;

	v[p] = q;

	for(int i=0; i<b[p].size(); i++) {

		g(b[p][i], q);

	}

}



int main() {

	int i, x, y;

	scanf("%d%d%d", &n, &k, &l);

	while(k--) {

		scanf("%d%d", &x, &y);

		a[x].push_back(y);

		a[y].push_back(x);

	}

	while(l--) {

		scanf("%d%d", &x, &y);

		b[x].push_back(y);

		b[y].push_back(x);

	}

	for(i=1, num=0; i<=n; i++) if(!u[i]) f(i, ++num);

	for(i=1, num=0; i<=n; i++) if(!v[i]) g(i, ++num);

	for(i=1; i<=n; i++) mp[{u[i],v[i]}]++;

	for(i=1; i<=n; i++) {

		if(!u[i] || !v[i]) printf("1 ");

		else printf("%d ",  mp[{u[i],v[i]}]);

	}

	return 0;

}