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



unordered_map<int, int> mep(200007);



int main()

{

	ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	time_t st = clock();

	int n;

	cin >> n;

	VI a(n);

	FOR(i, 0, n)

	{

		cin >> a[i];

		mep[a[i]]++;

	}

	

	deque<int> res;

	int ind = rnd() % n;

	res.PB(a[ind]);

	mep[a[ind]]--;

	FOR(i, 0, n)

	{

		if (mep[a[i]] == 0 || !mep.count(a[i] ^ a[ind]) || mep[a[i] ^ a[ind]] == 0)

		{

			continue;

		}

		res.PB(a[i]);

		mep[a[i]]--;

		int it = 0;

		while(true)

		{

			if (((double)clock() - st) / CLOCKS_PER_SEC >= 1.9)

			{

				cout << "No\n";

				return 0;

			}

			++it;

			if (it % 2 == 0)

			{

				int sz = SZ(res);

				int el = res[sz-1] ^ res[sz-2];

				if (mep.count(el) && mep[el] > 0)

				{

					res.PB(el);

					mep[el]--;

				}

				else

				{

					break;

				}

			}

			else

			{

				int el = res[0] ^ res[1];

				if (mep.count(el) && mep[el] > 0)

				{

					res.push_front(el);

					mep[el]--;

				}

				else

				{

					break;

				}

			}

		}

		if (SZ(res) == n)

		{

			cout << "Yes\n";

			return 0;

		}

		while(SZ(res) > 1)

		{

			mep[res.back()]++;

			res.pop_back();

		}

	}

	

	cout << "No\n";

	

	return 0;

}














