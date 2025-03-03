#include <cstdio>

#include <map>

using namespace std;

int n, k, l, a[200005], b[200005];

map<pair<int,int>,int> mp;



int f(int p, int x[]) {

	if(x[p]==p) return p;

	else return x[p] = f(x[p], x);

}



int main() {

	int i, u, v;

	scanf("%d%d%d", &n, &k, &l);

	for(i=1; i<=n; i++) a[i] = b[i] = i;

	while(k--) {

		scanf("%d%d", &u, &v);

		u = f(u,a), v = f(v,a);

		if(u!=v) a[u] = v;

	}

	while(l--) {

		scanf("%d%d", &u, &v);

		u = f(u,b), v = f(v,b);

		if(u!=v) b[u] = v;

	}

	for(i=1; i<=n; i++) {

		u = f(i,a), v = f(i,b);

		mp[{u,v}]++;

	}

	for(i=1; i<=n; i++) {

		u = f(i,a), v = f(i,b);

		printf("%d ", mp[{u,v}]);

	}

	return 0;

}
