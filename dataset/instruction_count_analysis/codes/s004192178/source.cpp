#include "bits/stdc++.h"

using namespace std;

#define all(v) (v).begin(), (v).end()

#define io ios::sync_with_stdio(0)

#define rep(i, a, b) for (int i = a; i <= b; i++)

#define rson rt << 1 | 1, mid + 1, r

#define lson rt << 1, l, mid

#define lll __int128

#define pii pair<int, int>

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define eps 1e-14

#define int long long

const int mod = 1e9 + 7;

inline int ksm(int a, int b)

{

	int ans = 1;

	for (; b; b >>= 1, a = a * a % mod)

		if (b & 1)

			ans = ans * a % mod;

	return ans;

}

#define double long double 

const double PI = acos(-1.0);

#define sqr(x) ((x) * (x))

const int N = 1010;

double area[100];

int n,k;



int dcmp(double x)

{

	if (x < -eps)

		return -1;

	else

		return x > eps;

}



struct cp

{

	double x, y, r, angle;

	double c;

	int d;

	cp() {}

	cp(double xx, double yy, double ang = 0, int t = 0)

	{

		x = xx;

		y = yy;

		angle = ang;

		d = t;

	}

	void get()

	{

		scanf("%lf%lf%lf", &x, &y, &r);

		d = 1;

	}

} cir[N], tp[N * 2];



double dis(cp a, cp b)

{

	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));

}



double cross(cp p0, cp p1, cp p2)

{

	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);

}



int CirCrossCir(cp p1, double r1, cp p2, double r2, cp &cp1, cp &cp2)

{

	double mx = p2.x - p1.x, sx = p2.x + p1.x, mx2 = mx * mx;

	double my = p2.y - p1.y, sy = p2.y + p1.y, my2 = my * my;

	double sq = mx2 + my2, d = -(sq - sqr(r1 - r2)) * (sq - sqr(r1 + r2));

	if (d + eps < 0)

		return 0;

	if (d < eps)

		d = 0;

	else

		d = sqrt(d);

	double x = mx * ((r1 + r2) * (r1 - r2) + mx * sx) + sx * my2;

	double y = my * ((r1 + r2) * (r1 - r2) + my * sy) + sy * mx2;

	double dx = mx * d, dy = my * d;

	sq *= 2;

	cp1.x = (x - dy) / sq;

	cp1.y = (y + dx) / sq;

	cp2.x = (x + dy) / sq;

	cp2.y = (y - dx) / sq;

	if (d > eps)

		return 2;

	else

		return 1;

}



bool circmp(const cp &u, const cp &v)

{

	return dcmp(u.r - v.r) < 0;

}



bool cmp(const cp &u, const cp &v)

{

	if (dcmp(u.angle - v.angle))

		return u.angle < v.angle;

	return u.d > v.d;

}



double calc(cp cir, cp cp1, cp cp2)

{

	double ans = (cp2.angle - cp1.angle) * sqr(cir.r) - cross(cir, cp1, cp2) + cross(cp(0, 0), cp1, cp2);

	return ans / 2;

}



void CirUnion(cp cir[], int n)

{

	cp cp1, cp2;

	sort(cir, cir + n, circmp);

	for (int i = 0; i < n; ++i)

		for (int j = i + 1; j < n; ++j)

			if (dcmp(dis(cir[i], cir[j]) + cir[i].r - cir[j].r) <= 0)

				cir[i].d++;

	for (int i = 0; i < n; ++i)

	{

		int tn = 0, cnt = 0;

		for (int j = 0; j < n; ++j)

		{

			if (i == j)

				continue;

			if (CirCrossCir(cir[i], cir[i].r, cir[j], cir[j].r,

							cp2, cp1) < 2)

				continue;

			cp1.angle = atan2(cp1.y - cir[i].y, cp1.x - cir[i].x);

			cp2.angle = atan2(cp2.y - cir[i].y, cp2.x - cir[i].x);

			cp1.d = 1;

			tp[tn++] = cp1;

			cp2.d = -1;

			tp[tn++] = cp2;

			if (dcmp(cp1.angle - cp2.angle) > 0)

				cnt++;

		}

		tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, PI, -cnt);

		tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, -PI, cnt);

		sort(tp, tp + tn, cmp);

		int p, s = cir[i].d + tp[0].d;

		for (int j = 1; j < tn; ++j)

		{

			p = s;

			s += tp[j].d;

			area[p] += calc(cir[i], tp[j - 1], tp[j]);

		}

	}

}



double  solve(double mid )

{

//	scanf("%d", &n);

	for (int i = 0; i < n; ++i)

		cir[i].r = mid/cir[i].c,cir[i].d=1;

	memset(area, 0, sizeof(area));

	CirUnion(cir, n);

	//去掉重复计算的

	for (int i = 1; i <= n; ++i)

	{

		area[i] -= area[i + 1];

	}

	//area[i]为重叠了i次的面积

	//tot 为总面积

	double tot = 0;

	for (int i = k; i <= n; i++)

		tot += area[i];

//	cout<<mid<<" "<<tot<<endl;

	return tot;

	//printf("%f\n", tot);

}





signed main()

{

	io;

	cin>>n>>k;

	rep(i,0,n-1){

		cin>>cir[i].x>>cir[i].y>>cir[i].c;

	}

	double ans = 1e40;

	double l=0,r=1e20;

	int T=800;

	while(T--){

		if(l+eps > r)break;

		double mid = (l+r)/2;

		double t=solve(mid);

		if(t>eps)ans=mid,r=mid-eps;

		else l=mid+eps;

	}

	

	cout<<fixed<<setprecision(10)<<ans<<endl;

	

	getchar(); //

	getchar();

}