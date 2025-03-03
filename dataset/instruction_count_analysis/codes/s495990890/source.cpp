#include"stdc++.h"

using namespace std;



#define FOR(i,a,b) for (int i = (a); i < (b); i++)

#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)

#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a, value) memset(a, value, sizeof(a))



#define SZ(a) (int)a.size()

#define ALL(a) a.begin(), a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1);

const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL)INF;



struct point

{

	LL x, y;

	point(){}

	point(LL x1, LL y1)

	{

		x = x1;

		y = y1;

	}



	LL d2() const

	{

		return x * x + y * y;

	}



	point operator -(const point& a) const

	{

		return point(x - a.x, y - a.y);

	}



	LL operator *(const point& a) const

	{

		return x * a.y - a.x * y;

	}



	bool operator <(const point& a) const

	{

		if (x == a.x) return y < a.y;

		return x < a.x;

	}



};



const int MAX = 100 + 47;

double const EPS = 1e-8;



point A[MAX];

double ANS[MAX];

int n;

point a, b;



double getAng(point a, point b)

{

	double a1 = atan2(a.y, a.x);

	if (a1 < 0) a1 += 2 * PI;



	double a2 = atan2(b.y, b.x);

	if (a2 < 0) a2 += 2 * PI;



	double alpha = abs(a1 - a2);

	if (alpha > PI) alpha = 2 * PI - alpha;

	return PI - alpha;

}



bool isOk(point a, point b)

{

	bool ccw = false;

	bool cw = false;



	FOR(i, 0, n)

	{

		LL val = (b - a) * (A[i] - a);

		if (val > 0) ccw = true;



		if (val < 0) cw = true;

	}



	if (ccw && cw) return false;



	return true;

}



bool inside(point a, point b, point c)

{

	if (a.x < b.x && b.x < c.x) return true;

	if (a.y < b.y && b.y < c.y) return true;



	return false;

}



bool inOneLine()

{

	FOR(i, 2, n)

	{

		if ((A[i] - A[i - 1]) * (A[i - 1] - A[i - 2]) != 0) return false;

	}



	return true;

}



int main()

{

	//freopen("in.txt", "r", stdin);

	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	FOR(i, 0, n)

	{

		cin >> A[i].x >> A[i].y;

	}



	if (inOneLine())

	{

		int mn = 0, mx = 0;

		FOR(i, 0, n)

		{

			if (A[i] < A[mn]) mn = i;

			if (A[mx] < A[i]) mx = i;

		}



		ANS[mn] = ANS[mx] = 0.5;

	}

	else

	{

		FOR(i, 0, n)

		{

			point a = A[i];



			FOR(j, 0, n)

			{

				if (i == j) continue;

				point b = A[j];



				if (!isOk(a, b)) continue;

				FOR(k, 0, n)

				{

					if (k == i || k == j) continue;

					point c = A[k];

					if (!isOk(b, c)) continue;

					//cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;



					if ((a - b) * (c - b) == 0) continue;

					double ans = getAng(a - b, c - b) / (2 * PI);

					ANS[j] = ans;

				}

			}

		}

	}



	FOR(i, 0, n)

	{

		cout << fixed << setprecision(12) << ANS[i] << "\n";

	}

	return 0;

}
