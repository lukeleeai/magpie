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



const int MAX = 222;



LL C[MAX][MAX];



LL ADD(LL v1, LL v2)

{

	LL res = v1 + v2;

	if (res >= LINF) res = LINF;

	return res;

}



LL MUL(LL v1, LL v2)

{

	double z = v1 * (double)v2;

	if (z >= 2e18) return LINF;

	LL res = v1 * v2;

	if (res >= LINF) res = LINF;

	return res;

}



LL get(int n, int m)

{

	LL res = 0;

	FOR (len, 0, min(n, m) + 1)

	{

		LL a = C[n][len];

		LL b = C[m][len];



		double z = a * (double)b;

		if (z > 2e18)

		{

			res = LINF;

			break;

		}



		res = ADD(res, a * b);

	}



	return res;

}



LL get(VI a)

{

	int res = 0;

	FOR (mask, 1, 1<<SZ(a))

	{

		VI s;

		FOR (i, 0, SZ(a))

		{

			if (mask & (1<<i)) s.PB(a[i]);

		}



		if (SZ(s) & 1) continue;



		int len = SZ(s) / 2;

		bool ok = true;

		FOR (i, 0, len)

		{

			if (s[i] != s[i+len]) ok = false;

		}

		res += ok;

	}



	return res;

}



int main()

{

	//freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	FOR (i, 0, MAX)

	{

		C[i][0] = 1;

		FOR (j, 1, i+1)

		{

			C[i][j] = ADD(C[i-1][j], C[i-1][j-1]);

		}

	}



	LL n;

	cin>>n;



	//n -= rand();



	LL N = n;



	VI res;



	int iter = 0;



	while(n)

	{

		iter++;

		int x = -1;

		FOR (i, 0, 60)

		{

			LL cur = (1ll << i) - 1;

			if (cur > n)

			{

				x = i - 1;

				break;

			}

		}



		if (x == -1) break;



	//	cout<<(1ll<<x)-1<<' '<<x<<endl;



		n -= (1ll << x) - 1;

		FOR (i, 0, x + 1)

		{

			res.PB(iter);

		}

	//	cout<<SZ(res)<<endl;



		break;

	}



//	cout<<"!! "<<n<<' '<<SZ(res)<<endl;



	vector<VI> RES;



	int len = SZ(res);

	int el = res[0];



	iter++;



	while(n)

	{

		int a = len;

		int b = 0;

		int ind = SZ(res);



		LL val = 1;



		bool any = false;



		LL bst = LINF;

		int len1 = -1, len2 = -1;



		RFOR(i, SZ(res), 0)

		{

			if (res[i] == el)

			{

				a--;

				b++;



				FOR (l1, 1, 10)

				{

					FOR (l2, 1, 10)

					{

						LL cur = MUL(get(a, b) - 1, get(l1, l2) - 1);

						cur = ADD(cur, (1ll<<(l1 + l2 - 1)) - 1);



						if (cur > n) continue;



						LL diff = n - cur;

						if (diff < bst)

						{



						//	cout<<"@@ "<<a<<' '<<b<<' '<<l1<<' '<<l2<<' '<<cur<<endl;

						//	cout<<get(a, b)<<' '<<get(l1, l2)<<endl;



							bst = diff;

							len1 = l1;

							len2 = l2;

							ind = i;

							val = cur;

						}

					}

				}

			}

			else break;

		}



	//	cout<<"*"<<' '<<n<<endl;



		if (bst == LINF)

		{

			RES.PB(res);

			res.clear();

			int x = -1;

			FOR (i, 0, 60)

			{

				LL cur = (1ll << i) - 1;

				if (cur > n)

				{

					x = i - 1;

					break;

				}

			}



			if (x == -1) break;



	//		cout<<(1ll<<x)-1<<' '<<x<<endl;



			n -= (1ll << x) - 1;

			FOR (i, 0, x + 1)

			{

				res.PB(iter);

			}

			//cout<<SZ(res)<<endl;

			len = SZ(res);

			el = res[0];

			iter++;

			continue;

		}



		//cout<<n<<' '<<val<<endl;

		//if (n < 0) throw -1;





		FOR (i, 0, len2)

		{

			res.insert(res.begin() + ind, iter);

		}

		FOR (i, 0, len1)

		{

			res.insert(res.begin(), iter);

		}

		iter++;



		n -= val;

	}



	RES.PB(res);

	res.clear();

	FOR (i, 0, SZ(RES))

	{

		FOR (j, 0, SZ(RES[i]))

		{

			res.PB(RES[i][j]);

		}

	}



	if (SZ(res) > 200) throw -1;





	printf("%d\n", SZ(res));



	FOR (i, 0, SZ(res))

	{

		printf("%d", res[i]);

		if (i != SZ(res) - 1) printf(" ");

	}



	printf("\n");



//	cout<<"!! "<<SZ(res)<<endl;



//	cout<<N<<endl;



//	cout<<get(res)<<endl;



}
