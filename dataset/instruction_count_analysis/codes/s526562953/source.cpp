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



int getBL(int a, int b, int cnt)

{

	int l = -1, r = a + b + 1;

	while(r - l > 1)

	{

		int m = (r + l) / 2;



		int aa = a - m * cnt;

		int bb = b - m;

		bb++;

		//cout<<m<<' '<<aa<<' '<<bb<<endl;



		if (aa < 0 || bb < 0)

		{

			r = m;

			continue;

		}



		int c = (bb + aa) / (aa + 1);

	//	cout<<c<<endl;

		if (c > cnt) r = m;

		else l = m;

	}



	return l;

}



string solve(int, int, int, int, int=-1);



string solveAB(int a, int b, int l, int r, int cnt = -1)

{

	if (cnt == -1) cnt = (a + b) / (b + 1);



	//cout<<a<<' '<<b<<' '<<l<<' '<<r<<' '<<": "<<cnt<<endl;

	if (b == -1) throw -1;

	//inv = false;

	if (cnt == 1)

	{

		string res;

		FOR (i, l, r + 1)

		{

			if (i % 2 == 0) res += 'A';

			else res += 'B';

		}

		return res;

	}



	if (cnt >= a)

	{

//		cout<<"!! "<<l<<' '<<r<<' '<<a<<' '<<b<<endl;

		a -= l;

		if (a < 0) return string(r-l+1, 'B');

		a = min(a, r - l + 1);

		return string(a, 'A') + string(r - l + 1 - a, 'B');

	}



//	cout<<cnt<<endl;



	int bl = getBL(a, b, cnt);

//	cout<<bl<<endl;



	int fbl = min(bl, l / (cnt + 1));



//	cout<<fbl<<endl;





	a -= fbl * cnt;

	b -= fbl;

	l -= fbl * (cnt + 1);

	r -= fbl * (cnt + 1);



	bl -= fbl;



//	cout<<"!! "<<l<<' '<<r<<endl;



//	cout<<bl<<' '<<fbl<<endl;



//	cout<<a<<' '<<b<<endl;



	if (bl) a -= l;

//	cout<<bl<<endl;



//cout<<a<<' '<<b<<endl;



	string res;



	int sz = 0;



	if (bl == 0)

	{

	//	cout<<"! "<<endl;

		string t = solve(a, b, l, r, cnt);

	//	cout<<"!!! "<<t<<endl;

		res += t;

		return res;

	}



	FOR (i, l, r+1)

	{

		if (bl)

		{

			if (i % (cnt + 1) == cnt)

			{

				res += 'B';

				bl--;





				b--;

			}

			else

			{

				res += 'A';

				a--;

			}

		}

		else

		{



			{

	//			cout<<"! "<<a<<' '<<b<<endl;

				string t = solve(a, b, 0, r - i, cnt);

	//			cout<<"!!! "<<t<<endl;

				res += t;

				return res;

				break;

			}



			break;



			if (sz == cnt)

			{

				res += 'A';

				a--;

				sz = 0;

				continue;

			}



			if (a == 0)

			{

				res += 'B';

				continue;

			}



			a--;

			if ((b + a) / (a + 1) > cnt)

			{

				a++;

				b--;

				sz++;

				res += 'B';

			}

			else

			{

				res += 'A';

				sz = 0;

			}

		}

	}





	return res;

}



string solveBA(int a, int b, int l, int r, int cnt = -1)

{

	int n = a + b;

	int l1 = n - l - 1;

	int r1 = n - r - 1;



//	cout<<l<<' '<<r<<' '<<r1<<' '<<l1<<endl;



	string res = solveAB(b, a, r1, l1, cnt);

	reverse(ALL(res));

	FOR (i, 0, SZ(res))

	{

		if (res[i] == 'A') res[i] = 'B';

		else res[i] = 'A';

	}

	return res;

}



string solve(int a, int b, int l, int r, int cnt)

{

/*	if (a == b)

	{

	//	cout<<a<<' '<<b<<' '<<l<<' '<<r<<endl;

		string res;

		FOR (i, l, r + 1)

		{

			if (i % 2 == 0) res += 'A';

			else res += 'B';

		}

		if (0) reverse(ALL(res));

		return res;

	}*/



	if (a >= b)

	{

		return solveAB(a, b, l, r, cnt);

	}

	return solveBA(a, b, l, r, cnt);

}



string RRR;



int pa =- 1, pb =- 1;



string brute(int a, int b, int l, int r)

{

	if (a == pa && b == pb)

	{

		return RRR.substr(l, r-l+1);

	}

	string s = string(a, 'A') + string(b, 'B');



	int mn = INF;

	string res;

	do

	{

		int cnt = 1;

		int cur = 1;

		FOR (i, 1, SZ(s))

		{

			if (s[i] == s[i-1]) cur++;

			else cur = 1;

			cnt = max(cnt, cur);

		}



		if (cnt < mn)

		{

			mn = cnt;

			res = s;

		}



		if (cnt == mn) res = min(res, s);

	} while(next_permutation(ALL(s)));



	cout<<res<<endl;

	RRR = res;

	pa = a;

	pb = b;



	return res.substr(l, r-l+1);

}



int main()

{

//	freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	//cout<<brute(17, 7, 22, 23)<<endl;

	//cout<<solve(17, 7, 22, 23)<<endl;

	///cout<<solve(8, 10, 0, 17)<<endl;

	//return 0;



	//ofstream ss("in.txt");



/*	FOR (a, 1, 20)

	{

		FOR (b, 1, 20)

		{

			FOR (l, 0, a+b)

			{

				FOR (r, l, a+b)

				{

					cout<<a<<' '<<b<<' '<<l<<' '<<r<<": "<<endl;

					//ss<<a<<' '<<b<<' '<<l<<' '<<r<<": "<<endl;

					string s = solve(a, b, l, r);

					string t = brute(a, b, l, r);

					cout<<t<<endl<<s<<endl;

					if (s != t)

					{

						cout<<"!! "<<endl;

						throw -1;

					}

				}

			}

		}

	}

	return 0;*/



	int n;

	scanf("%d", &n);

	FOR (i, 0, n)

	{

		int a, b, l, r;

		scanf("%d%d%d%d", &a, &b, &l, &r);

		l--;

		r--;



		string res = solve(a, b, l, r);

		printf("%s\n", res.c_str());

	}



/*	int a = 10;

	int b = 8;

	int len = 18;

	FOR (i, 0, len)

	{

		cout<<i<<endl;

		FOR (j, i, len)

		{

			cout<<string(i, ' ')<<solve(a, b, i, j)<<string(len-j-1, ' ')<<endl;

		}

	}*/

}
