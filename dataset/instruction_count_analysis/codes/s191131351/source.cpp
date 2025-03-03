#include <queue>

#include <cstdio>

#include <vector>

#include <algorithm>

using namespace std;

#define N 100100

#define fi first

#define se second

#define pb push_back

#define mp make_pair

#define mod 1000000007

#define rep(x, a, b) for(int x=a; x<=b; x++)

#define drp(x, a, b) for(int x=a; x>=b; x--)

int st[N<<1], deg[N], d[N], n, vis[N], a[N], tot, num[N], l[N], ans=1, fac[N], inv[N];

typedef long long LL;



int power(int x, int y){

	int an = 1;

	for(; y; y >>= 1, x = (LL)x * x % mod) if(y & 1) an = (LL)an * x % mod;

	return an;

}



int C(int x, int y){

	if(x < 0 || y < 0 || x < y) return 0;

	return (LL)fac[x] * inv[y] % mod * inv[x - y] % mod;

}



void renew(int &x, const int y){

	x += y;

	if(x < 0) x += mod;

	if(x >= mod) x -= mod;

}



void init(){

	fac[0] = inv[0] = fac[1] = inv[1] = 1;

	rep(i, 2, n){

		fac[i] = (LL)fac[i - 1] * i % mod;

		inv[i] = power(fac[i], mod - 2);

	}

}



int getdp(){

	int fr = 0;

	rep(i, 1, tot) st[i + tot] = st[i];

	rep(i, 1, tot) if(l[st[i]]){

		fr = i;

		break;

	}

	reverse(st + fr + 1, st + fr + tot);

	int a = fr + l[st[fr]] - 1, b = a + 1, c = 1;

	rep(i, fr + 1, fr + tot - 1)if(l[st[i]]){

		int na = i + l[st[i]] - 1, nb = na + 1, cc = 0;

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



int que[N], h, t;

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

		l[x] = cnt;

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

			cu &= !l[u];

			vis[u] = 1;

			u = a[u];

		}while(u != i);

		if(cu){

			num[tot] ++;

			res = 1;

		}else{

			res = getdp();		

		}

		ans = (LL)ans * res % mod;

	}

	rep(i, 1, n) if(num[i])

	{

		int tot = num[i];

		int res = 0;

		for(int x = 0; x <= tot; x += 2){

			int cb = 1;

			cb = (LL)cb * power(i, (x >> 1)) % mod;

			cb = (LL)cb * C(tot, x) % mod;

			cb = (LL)cb * fac[x] % mod;

			cb = (LL)cb * inv[x >> 1] % mod;

			cb = (LL)cb * power((mod + 1) >> 1, x >> 1) % mod;

			if((i > 1) && (i & 1)){

				cb = (LL)cb * power(2, tot - x) % mod;

			}

			renew(res, cb);

		}

		ans = (LL)ans * res % mod;

	}

	printf("%d\n", ans);

}