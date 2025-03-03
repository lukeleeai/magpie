#include "stdc++.h"

using namespace std;



//#pragma GCC optimize("Ofast,unroll-loops")

//#pragma GCC target("avx,avx2,fma")



typedef long long LL;

typedef pair<int, int> PII;

typedef vector<int> VI;

#define MP make_pair

#define PB push_back

#define X first

#define Y second



#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())

#define FILL(a, value) memset(a, value, sizeof(a))

#define debug(a) cerr << #a << " = " << a << endl;



template<typename T> void setmax(T& x, T y) {x = max(x, y);}

template<typename T> void setmin(T& x, T y) {x = min(x, y);}



const double PI = acos(-1.0);

const LL INF = 1e9 + 47;

const LL LINF = INF * INF;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



const int N = 1 << 18;

int n, m, l[N], r[N], c[N];

vector<pair<int, int>> g[N];

LL d[N];



int main()

{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);



	cin >> n >> m;

	FOR(i, 0, m){

		cin >> l[i] >> r[i] >> c[i];

		g[l[i]].PB({r[i], c[i]});

	}



	FOR(i, 1, n) g[i + 1].PB({i, 0});

	

	FOR(i, 2, n + 1) d[i] = LINF;

	set<pair<LL, int>> S;

	S.insert({0, 1});

	while(SZ(S)){

		int v = S.begin()->Y;

		S.erase(S.begin());

		for(auto to: g[v]){

			if (d[to.X] > d[v] + to.Y){

				S.erase({d[to.X], to.X});

				d[to.X] = d[v] + to.Y;

				S.insert({d[to.X], to.X});

			}

		}

	}

	

	if (d[n] == LINF) d[n] = -1;

	cout << d[n] << endl;



    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;

    return 0;

}
