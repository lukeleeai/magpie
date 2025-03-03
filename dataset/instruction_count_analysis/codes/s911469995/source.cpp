#include <cstdio>

#include <algorithm>

#include <cstring>

#include <iostream>



using namespace std;



typedef long long ll; 

const int MAXN = 200010;

const ll  INF = 1e16+1;



int n, m;

struct iv{

	int l, r, w;

	bool operator<(const iv &o)const{return r!=o.r?r<o.r:l<o.l;}

}a[MAXN];



ll f[MAXN];



struct node{

	int l, r;

	ll maxx, tag;

}t[MAXN<<2];

inline void pushUp(int k){

	t[k].maxx = max(t[k<<1].maxx, t[k<<1|1].maxx);

}

inline void pushDown(int k)

{

	if(!t[k].tag) return ;

	t[k<<1].maxx   += t[k].tag;

	t[k<<1|1].maxx += t[k].tag;

	t[k<<1].tag    += t[k].tag;

	t[k<<1|1].tag  += t[k].tag;

	t[k].tag = 0;

}

void build(int l, int r, int k)

{

	t[k].l = l; t[k].r = r; t[k].maxx = 0; t[k].tag = 0;

	if(l == r) return ;

	int mid = l + r >> 1;

	build(l, mid, k<<1);

	build(mid+1, r, k<<1|1);

	pushUp(k);

}

void update(int x, int y, ll val, int k)

{

	if(t[k].l >= x && t[k].r <= y){

		t[k].maxx += val;

		t[k].tag += val;

		return ;

	}

	pushDown(k);

	int mid = t[k].l + t[k].r >> 1;

	if(x <= mid) update(x, y, val, k<<1);

	if(y >= mid+1) update(x, y, val, k<<1|1);

	pushUp(k);

}

ll query(int x, int y, int k)

{

	if(t[k].l >= x && t[k].r <= y) return t[k].maxx;

	pushDown(k);

	int mid = t[k].l + t[k].r >> 1;

	ll res = -INF;

	if(x <= mid) res = max(res, query(x, y, k<<1));

	if(y >= mid+1) res = max(res, query(x, y, k<<1|1));

	return res;

}



int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++)

		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);

	sort(a+1, a+m+1);

	a[m+1].r = 0;

	build(1, n, 1);

	int now = 1;

	for(int i=1;i<=n;i++)

	{

		update(i, i, query(1, i, 1), 1);

		while(a[now].r == i){

			update(a[now].l, a[now].r, a[now].w, 1);

			++now;

		}

	}

	printf("%lld\n",max(query(1, n, 1), 0ll));

	return 0;

}