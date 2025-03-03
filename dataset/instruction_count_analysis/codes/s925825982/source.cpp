// ~maqsat~



// #pragma GCC target ("avx2")

// #pragma GCC optimize ("Ofast")

// #pragma GCC optimize ("unroll-loops")



#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/rope>



#define F first

#define S second

#define in insert

#define pb push_back

#define eb emplace_back

#define sz(x) int(x.size())

#define all(x) x.begin(), x.end()

#define count1 __builtin_popcountl

#define debug(x) cerr << (#x) << " = " << (x) << "\n"

#define ACCELERATE ios_base::sync_with_stdio(false),cin.tie(nullptr)

#define fre(f) if(fopen(f".in", "r")) freopen(f".in", "r", stdin),freopen(f".out", "w", stdout)

#define ever ;;



using namespace std;

using namespace __gnu_pbds;

using namespace __gnu_cxx;



using ll = long long;

using ull = unsigned long long;

// using big = __int128_t; // -10^38...10^38

using db = double;

using ld = long double;

typedef pair<int,int> ii;

typedef pair<ll,ll> pll;



template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> inline void cmin(T &a, T b) { a = min(a, b); }

template <class T> inline void cmax(T &a, T b) { a = max(a, b); }



const int oo = 0x3f3f3f3f;

const ll N = 1e5 + 123;

const ll MOD = 1e9 + 7;

const ll INF = 1e15 + 9;

const db EPS = 1e-9;

const db PI = acos(-1); // 3.14159265358979323846

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};

const int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};



main() {

#ifdef ziel

	freopen("input.in", "r", stdin);

#else

	fre("");

#endif

	ACCELERATE;



	int n;

	cin >> n;



	int a[N];



	int mn = n * 2, mx = -1;

	for (int i = 0; i < n; i++) {

		cin >> a[i];

		cmin(mn, a[i]);

		cmax(mx, a[i]);

	}



	if (mn == mx) {

		if (mn == n - 1) cout << "Yes";

		else if (2 * mx <= n) cout << "Yes";

		else cout << "No";

		return 0;

	}

	else if (mn + 1 == mx) {

		int x = 0, y = 0;

		for (int i = 0; i < n; i++) {

			if (a[i] == mn) x++;

			else y++;

		}



		if (mx > x && x + y / 2 >= mx) cout << "Yes";

		else cout << "No";

		return 0;

	}

	else {

		cout << "No";

		return 0;

	}

	

	return 0;

}

/*

 

*/
