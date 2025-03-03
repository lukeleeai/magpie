#include <iostream>

#include <cstdlib>

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

#define rep(x, n) for (int x = 1; x <= n; ++x)

#define FOR(x, l, r) for (int x = l; x <= r; ++x)

const int maxN = 505;

struct T

{

	double l, r, bg;

	int a;

	double ed()

	{

		return bg + a * (r - l);

	}

	double dis()

	{

		return (bg + ed()) * (r - l) * 0.5;

	}

	void print()

	{

		cout << l << " " << r << " " << bg << " " << a << endl;

	}

}st[maxN];

int v[maxN], t[maxN], n, top;



void add(double l, double r, double bg, int a)

{

	++top;

	st[top].l = l; st[top].r = r;

	st[top].bg = bg; st[top].a = a;

}



void make(double v)

{

	if (st[top].ed() <= v) return;

	double l = st[top].l, r = st[top].r;

	double bg = st[top].bg;

	if (bg > v + (r - l))

	{

		top--;

		make(v + (r - l));

		add(l, r, v + (r - l), -1);

	}

	else

	{

		double a = st[top].a;

		double x = (v + r + l * a - bg) / (1 + a);

		st[top].r = x;

		add(x, r, v + r - x, -1);

	}

}



int main()

{

	scanf("%d", &n);

	rep(i, n) scanf("%d", t + i);

	rep(i, n) scanf("%d", v + i);



	add(-1, 0, 0, 0);



	double ti = 0;

	rep(i, n)

	{

		make(v[i]);

		double last = st[top].ed();

		if (t[i] > (v[i] - last))

		{

			add(ti, ti + v[i] - last, last, 1);

			add(ti + v[i] - last, ti + t[i], v[i], 0);

		}

		else

		{

			add(ti, ti + t[i], last, 1);

		}

		ti += t[i];

	}

	make(0.0);



	double ans = 0;

	rep(i, top) ans += st[i].dis();



	printf("%.10lf\n", ans);

	return 0;

}
