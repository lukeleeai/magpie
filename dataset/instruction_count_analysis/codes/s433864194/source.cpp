#include <cstdio>

#include <cstring>

#include <algorithm>

#define ll long long

#define MOD 1000000007



//define

ll X;

int n, m;

struct Data{

	int x, y, v;

	bool operator<(const Data a)const{

		return v < a.v;

	}

}d[2333];



void input(){

	scanf("%d %d", &n, &m);

	scanf("%lld", &X);

	for(int i = 1; i <= m; i++)

		scanf("%d %d %d", &d[i].x, &d[i].y, &d[i].v);

	std::sort(d + 1, d + m + 1);

}



//work

ll ans;

int fa[1111];

int ls, mr, eq;



int find(int a){

	if(fa[a] == a) return a;

	return fa[a] = find(fa[a]);

}



void Kruskal(int a){

	ans = 0;

	for(int i = 1; i <= n; i++) fa[i] = i;

	ans = d[a].v;

	fa[d[a].x] = d[a].y;

	for(int i = 1; i <= m; i++){

		if(i == a) continue;

		int u = find(d[i].x), v = find(d[i].y);

		if(u == v) continue;

		fa[u] = v;

		ans = ans + d[i].v;

	}

	if(ans < X) ls++;

	if(ans == X) eq++;

	if(ans > X) mr++;

}



int Ans;



ll quickpow(ll p,ll k)

{

	ll tmp=1;

	while(k)

	{

		if(k&1)

			tmp=(tmp*p)%MOD;

		p=(p*p)%MOD;

		k>>=1;

	}

	return tmp;

}



void work(){

	/*p[0] = 1;

	for(int i = 1; i <= n; i++)

		p[i] = p[i - 1] * 2 % MOD;*/

	for(int i = 1; i <= m; i++) Kruskal(i);

	if(eq == 0) puts("0");

	else if(ls == 0)

		printf("%lld\n", 1ll * ((quickpow(2, eq) - 2 + MOD) % MOD) * quickpow(2, mr) % MOD);

	else

		printf("%lld\n", 2ll * ((quickpow(2, eq) - 1 + MOD) % MOD) % MOD * quickpow(2, mr) % MOD);

}



int main(){

	input();

	work();

	return 0;

}