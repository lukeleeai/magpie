#include "stdc++.h"

using namespace std;



#define FOR(i,a,b) for(int i = (a); i < (b); i++)

#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)

#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a, value) memset(a, value, sizeof(a))



#define SZ(a) (int) a.size()

#define ALL(a) a.begin(),a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const LL INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL)INF;



const int MAX = 100100;



struct RMQ

{

	int A[MAX * 4];

	int P[MAX * 4];

	int n;



	void init(int n)

	{

		this->n = n;

		FOR (i, 0, n*4)

		{

			A[i] = -1;

			P[i] = -1;

		}

	}



	void upd(int v, int val)

	{

		A[v] = val;

		P[v] = val;

	}

	void push(int v, int tl, int tr)

	{

		if (tl == tr || P[v] == -1) return;



		upd(v*2, P[v]);

		upd(v*2+1, P[v]);

		P[v] = -1;

	}



	void upd(int tl, int tr, int v, int l, int r, int val)

	{

		if (l > r) return;

		push(v, tl, tr);

		if (l == tl && r == tr)

		{

			upd(v, val);

			return;

		}



		int tm = (tl + tr) / 2;

		upd(tl, tm, v*2, l, min(tm, r), val);

		upd(tm+1, tr, v*2+1, max(tm+1, l), r, val);

	}



	void paint(int l, int r, int c)

	{

		upd(0, n-1, 1, l, r, c);

	}



	int get(int tl, int tr, int v, int x)

	{

		push(v, tl, tr);

		if (tl == tr)

		{

			return A[v];

		}



		int tm = (tl + tr) / 2;

		if (x <= tm) return get(tl, tm, v*2, x);

		return get(tm+1, tr, v*2+1, x);

	}



	int get(int x)

	{

		return get(0, n-1, 1, x);

	}

} R;



struct Fen

{

	int A[MAX];

	int n;



	void init(int n)

	{

		this->n = n;

	}



	void add(int x, int val)

	{

		for (; x < n; x = x | (x + 1))

		{

			A[x] += val;

		}

	}



	void add(int l, int r, int val)

	{

		add(l, val);

		add(r+1, -val);

	}



	int get(int x)

	{

		int res = 0;

		for (; x >= 0; x = (x & (x + 1)) - 1)

		{

			res += A[x];

		}

		return res;

	}





} F;



int A[MAX];

int B[MAX];



vector<PII> C;



VI v;



int getInd(int x)

{

	return lower_bound(ALL(v), x) - v.begin();

}



LL DP[MAX][2];



int len(int x, int y, int mod)

{

	if (y >= x) return y - x;

	return y - x + mod;

}



int main()

{

	//freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	int n, k;

	scanf("%d%d", &n, &k);

	LL add = 0;

	FOR (i, 0, n)

	{

		scanf("%d%d", &A[i], &B[i]);

		add += A[i];

	}



	int sum = 0;



	FOR (i, 0, n)

	{

		int ns = sum + A[i];

		ns %= k;



		if (B[i] == 1)

		{

			if (2 * A[i] >k)

			{

				cout<<-1<<endl;

				return 0;

			}

			C.PB(MP(-2*sum, -2*ns));

		}



		sum = ns;

	}



	FOR (i, 0, SZ(C))

	{

		C[i].first %= k;

		if (C[i].first < 0) C[i].first += k;



		C[i].second %= k;

		if (C[i].second < 0) C[i].second += k;



		v.PB(C[i].first);

		v.PB(C[i].second);

	}



	sort(ALL(v));

	v.erase(unique(ALL(v)), v.end());



	R.init(SZ(v));



	/*FOR (i, 0, SZ(C))

	{

		cout<<C[i].first<<' '<<C[i].second<<endl;

	}*/



	RFOR(i, SZ(C), 0)

	{

		int x = C[i].first;



		int c = R.get(getInd(x));

		if (c == -1) DP[i][0] = 0;

		else

		{

			DP[i][0] = DP[c][0] + len(x, C[c].first, k);

		}



		x = C[i].second;

		c = R.get(getInd(x));

		if (c == -1) DP[i][1] = 0;

		else

		{

			DP[i][1] = DP[c][0] + len(x, C[c].first, k);

		}



		int l = getInd(C[i].first);

		int r = getInd(C[i].second);

		if (l > r)

		{

			R.paint(r+1, l-1, i);

		}

		else

		{

			R.paint(0, l-1, i);

			R.paint(r+1, SZ(v)-1, i);

		}

	}



	F.init(SZ(v));



	LL res = LINF;



	FOR (i, 0, SZ(C))

	{

		int x = C[i].first;

		int cnt = F.get(getInd(x));

		if (cnt == i) res = min(res, DP[i][0]);



		x = C[i].second;

		cnt = F.get(getInd(x));

		if (cnt == i) res = min(res, DP[i][1]);



		int l = getInd(C[i].first);

		int r = getInd(C[i].second);



		if (l <= r)

		{

			F.add(l, r, 1);

		}

		else

		{

			F.add(0, r, 1);

			F.add(l, SZ(v)-1, 1);

		}

	}



	res += add * 2;



	cout<<res<<endl;



}
