/*痛みを受け取れ，痛みを知れ*/

#include"stdc++.h"

#define f(i,a,b) for(register int i=a;i<=b;++i)

#define ff(i,a,b) for(register int i=a;i>=b;--i)

#define debug(x) cerr << #x << " : " << x << " " << endl

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<string, string> pss;

const ll mod = 1e9 + 7;

const int inf = 0x3f3f3f3f;

const double tiaohe = 0.57721566490153286060651209;

ll oula(ll x) { ll res = x;f(i, 2, x / i) { if (x % i == 0) { res = res / i * (i - 1);while (x % i == 0) x /= i; } }if (x > 1) res = res / x * (x - 1);return res; }

ll quickmod(ll a, ll n, ll m) { ll s = 1;while (n) { if (n & 1) { s = s * a % m; }a = (a*a) % m;n = n / 2; }return s; }

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void ex_gcd(ll a, ll b, ll &x, ll &y, ll &d) { if (!b) { d = a, x = 1, y = 0; } else { ex_gcd(b, a % b, y, x, d);y -= x * (a / b); } }

ll inv(ll t, ll p) { ll d, x, y;ex_gcd(t, p, x, y, d);return d == 1 ? (x % p + p) % p : -1; }

bool isPrime(ll x) { if (x == 2)return true;if (x % 2 == 0)return false;for (ll i = 2;i*i <= x;i++) if (x % i == 0)return false; return true; }

//double a = log(n) +tiaohe + 1.0 / (2 * n);

double eqa = (1 + sqrt(5.0)) / 2.0;

const int N = 3e5 + 5;

inline int in()

{

	char ch = getchar();

	int x = 0, f = 1;

	while (ch<'0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }

	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }

	return x * f;

}//快读

int r[N], c[N];

int main()

{

	//freopen("in.txt", "r", stdin);

	int h, w, m;

	while (cin >> h >> w >> m)

	{

		int x, y;

		map<pii, int> mp;

		f(i, 1, m)

		{

			x = in();

			y = in();

			r[x]++;

			c[y]++;

			mp[{x, y}]++;

		}

		int mx = 0;

		vector<int> v;

		f(i, 1, h)

		{

			if (r[i] > mx)

			{

				v.clear();

				mx = r[i];

				v.emplace_back(i);

			}

			else if(r[i]==mx)

			{

				v.emplace_back(i);

			}

		}

		int mx2 = 0;

		vector<int> v2;

		f(j, 1, w)

		{

			if (c[j] > mx2)

			{

				mx2 = c[j];

				v2.clear();

				v2.emplace_back(j);

			}

			else if (c[j] == mx2)

			{

				v2.emplace_back(j);

			}

		}

		int ans = 0,fg=1;

		for (auto i : v)

		{

			for (auto j : v2)

			{

				if (mp[{i, j}] == 0) { fg = 0;break; }

			}

		}

		cout <<mx+mx2-fg << endl;

	}

	return 0;

}