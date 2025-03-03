//#pragma GCC optimize("Ofast")

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include "stdc++.h"



using namespace std;



#define PB push_back

#define MP make_pair

#define EB emplace_back

#define f first

#define s second

#define FOR(i,a,b) for (int i = a; i < (b); ++i)

#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)

#define FILL(a, b) memset(a, b, sizeof a)

#define ALL(a) a.begin(), a.end()

#define SZ(a) ((int)a.size())

#define bitc(n) __builtin_popcount(n)

#define MAGIC0 mt19937 rnd(time(0)); //rnd()



typedef long long LL;

typedef unsigned long long ULL;

typedef vector<int> VI;

typedef pair<int, int> PII;

typedef pair<LL, LL> PLL;



const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = 1LL * INF*INF;

const int MAX = 1e6 + 7;

const double PI = acos(-1.);

const double EPS = 1e-7;

const int MAXN = 100005;



mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



set<int> x[100005];

int cnt[100005];



int main()

{

	ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	VI a(n);

	FOR(i, 0, n)

	{

		cin >> a[i];

	}

	sort(ALL(a));

	

	if (n % 3 != 0)

	{

		if (a[0] == a[n - 1])

		{

			cout << "Yes\n";

		}

		else

		{

			cout << "No\n";

		}

	}

	else

	if (a[0] == a[n / 3 - 1] && a[n / 3] == a[2 * n / 3 - 1] && a[2 * n / 3] == a[n - 1] && ((a[0] ^ a[n / 3] ^ a[2*n/3]) == 0))

	{

		cout << "Yes\n";

	}

	else

	{

		cout << "No\n";

	}

	

	return 0;

}














