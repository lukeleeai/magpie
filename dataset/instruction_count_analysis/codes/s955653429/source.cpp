#include<cstdio>

#include<iostream>

#include<algorithm>

using namespace std;

const int MAXN = 3010;

const int MAXH = 100010, MAXW = 100010;

const int MOD = 1000000007;

int h, w, n;

struct node{

	int x, y;

}a[MAXN];

int fac[MAXH+MAXW], inv[MAXH+MAXW], f[MAXN+1];

inline int mul(int a, int b){return 1ll*a*b%MOD;}

inline int add(int a, int b){return (a+=b)>=MOD?a-MOD:a;}

inline int sub(int a, int b){return (a-=b)<0?a+MOD:a;}

inline int pw(int x, int p){int res=1;for(;p;p>>=1,x=mul(x,x))if(p&1)res=mul(res,x);return res;}

inline int C(int n, int m){return mul(fac[n], mul(inv[m], inv[n-m]));}

inline void prepare()

{

	fac[0] = 1;

	for(int i=1;i<=h+w;i++)

		fac[i] = mul(fac[i-1], i);

	inv[h+w] = pw(fac[h+w], MOD-2);

	for(int i=h+w;i>=1;i--)

		inv[i-1] = mul(inv[i], i);

}

inline bool cmp(node p, node q){return p.x!=q.x?p.x<q.x:p.y<q.y;}

int main()

{

	scanf("%d%d%d",&h,&w,&n);

	for(int i=1;i<=n;i++)

		scanf("%d%d",&a[i].x,&a[i].y);

	a[++n].x = h; a[n].y = w;

	prepare();

	sort(a+1, a+n+1, cmp);

	for(int i=1;i<=n;i++)

	{

		f[i] = C(a[i].x+a[i].y-2, a[i].x-1);

		for(int j=1;j<i;j++)

			if(a[j].x<=a[i].x&&a[j].y<=a[i].y)

				f[i] = sub(f[i], mul(f[j], C(a[i].x+a[i].y-a[j].x-a[j].y, a[i].x-a[j].x)));

	}

	printf("%d\n",f[n]);

	return 0;

}