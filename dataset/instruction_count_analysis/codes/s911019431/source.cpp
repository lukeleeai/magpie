#include <iostream>

#include <vector>

#include <algorithm>

#include <cstdio>



using namespace std;



using ll = long long;

struct Line { ll a, b; ll get(ll x) { return a * x + b; } };



static const int MAX = 2e5 + 9;

const ll INFL = 1e17;



struct LiChaoTree

{

	int N;

    Line a[MAX << 2];

    ll h[MAX];



    void init (ll _h[MAX], int _N)

    {

    	N = _N;

    	copy (_h, _h + N, h);

    	for (int i = 0; i < (N << 2); ++i) a[i] = {0, INFL};

    }



    void upd (Line ln)

    {

        int root = 1, lo = 0, hi = N;

        while (true) {

			int mid = (lo + hi) >> 1;

            if (ln.get(h[mid]) < a[root].get(h[mid])) swap (ln, a[root]);

//            cerr << '[' << h[lo] << ", " << h[hi-1] << "]: " << a[root].a << ' ' << a[root].b << endl;

            if (lo + 1 >= hi) return;

            if (ln.get(h[lo]) < a[root].get(h[lo])) root = root << 1, hi = mid;

            else root = root << 1 | 1, lo = mid;

        }

    }



    ll get (int x)

    {

        int root = 1, lo = 0, hi = N; ll ans = INFL;

        while (true) {

        	int mid = (lo + hi) >> 1;

            ans = min(ans, a[root].get(h[x]));

            if (lo + 1 >= hi) return ans;

            if (x < mid) root = root << 1, hi = mid;

            else root = root << 1 | 1, lo = mid;

        }

    }



} tree;



int N;

ll C, h[MAX], f;



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; ++i) cin >> h[i];

    tree.init(h, N);



    for (int i = 0; i < N; ++i) {

        f = (i == 0) ? 0ll : (tree.get(i) + h[i] * h[i] + C);

        if (i == N-1) return cout << f << endl, 0;

//        cout << f << ' ';

        tree.upd({-2 * h[i], f + h[i] * h[i]});

    }

}
