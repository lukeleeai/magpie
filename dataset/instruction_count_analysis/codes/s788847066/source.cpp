#include <set>

#include <map>

#include <cmath>

#include <ctime>

#include <cstdio>

#include <bitset>

#include <vector>

#include <string>

#include <cassert>

#include <cstring>

#include <cstdlib>

#include <iomanip>

#include <iostream>

#include <algorithm>

#define rep(i, x, y)  for(int i = (int)x; i <= (int)y; i ++)

#define fi first

#define se second

#define pb push_back

#define mk make_pair

using namespace std;

typedef long long LL;

const	int N = 100005;

const	int P = (int)1e9 + 7;

int st[N<<1], deg[N], d[N], n, vis[N], a[N], tot, ct[N], sz[N], ans=1, fac[N], inv[N];



int power(int x, int y){

	int an = 1;

	for(; y; y >>= 1, x = (LL)x * x % P) if(y & 1) an = (LL)an * x % P;

	return an;

}



int C(int x, int y){

	if(x < 0 || y < 0 || x < y) return 0;

	return (LL)fac[x] * inv[y] % P * inv[x - y] % P;

}



void renew(int &x, const int y){

	x += y;

	if(x < 0) x += P;

	if(x >= P) x -= P;

}



void init(){

	fac[0] = inv[0] = fac[1] = inv[1] = 1;

	rep(i, 2, n){

		fac[i] = (LL)fac[i - 1] * i % P;

		inv[i] = power(fac[i], P - 2);

	}

}



int getdp(){

	int fr = 0;

	rep(i, 1, tot) st[i + tot] = st[i];

	rep(i, 1, tot) if(sz[st[i]]){

		fr = i;

		break;

	}

	reverse(st + fr + 1, st + fr + tot);

	int a = fr + sz[st[fr]] - 1, b = a + 1, c = 1;

	rep(i, fr + 1, fr + tot - 1)if(sz[st[i]]){

		int na = i + sz[st[i]] - 1, nb = na + 1, cc = 0;

		if(a < i) renew(cc, c);

		if(b < i) renew(cc, c);

		a = na;

		b = nb;

		c = cc;

	}

	int ans = 0;

	if(a < fr + tot) renew(ans, c);

	if(b < fr + tot) renew(ans, c);

	return ans;

}



int que[N], t;

int main(){

	scanf("%d", &n);

	rep(i, 1, n) scanf("%d", a + i);

	rep(i, 1, n){

		deg[a[i]] ++;

		if(deg[a[i]] > 2){ puts("0"); exit(0); }

	}

	rep(i, 1, n) d[i] = deg[i];

	rep(i, 1, n) if(!d[i]) que[++t] = i;

	rep(h, 1, t){

		int u = que[h];

		--d[a[u]];

		vis[u] = 1;

		if(!d[a[u]]) que[++t] = a[u];

	}

	rep(i, 1, n) if(vis[i] && deg[i] >= 2){

		puts("0");

		exit(0);

	}

	rep(i, 1, n) if(vis[i] && !deg[i]){

		int x = i, cnt = 0;

		for(x = i; vis[x]; x = a[x])cnt++;

		sz[x] = cnt;

	}

	init();

	ans=1;

	rep(i, 1, n)if(!vis[i])

	{

		int u = i, cu = 1;

		tot = 0;

		int res = 0;

		do{

			st[++tot] = u;

			cu &= !sz[u];

			vis[u] = 1;

			u = a[u];

		}while(u != i);

		if(cu){

			ct[tot] ++;

			res = 1;

		}else{

			res = getdp();		

		}

		ans = (LL)ans * res % P;

	}

	rep(i, 1, n) if(ct[i])

	{

		int tot = ct[i];

		int res = 0;

		for(int x = 0; x <= tot; x += 2){

			int cb = 1;

			cb = (LL)cb * power(i, (x >> 1)) % P;

			cb = (LL)cb * C(tot, x) % P;

			cb = (LL)cb * fac[x] % P;

			cb = (LL)cb * inv[x >> 1] % P;

			cb = (LL)cb * power((P + 1) >> 1, x >> 1) % P;

			if((i > 1) && (i & 1)){

				cb = (LL)cb * power(2, tot - x) % P;

			}

			renew(res, cb);

		}

		ans = (LL)ans * res % P;

	}

	printf("%d\n", ans);

}