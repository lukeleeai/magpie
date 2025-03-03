#include "stdc++.h"

using namespace std;

using LL = long long;

using ULL = unsigned long long;

using VI = vector<int>;

using VL = vector<LL>;

using PII = pair<int, int>;

using PLL = pair<LL, LL>;



#define SZ(a) (int)a.size()

#define ALL(a) a.begin(), a.end()

#define MP make_pair

#define PB push_back

#define EB emplace_back

#define F first

#define S second

#define FOR(i, a, b) for (int i = (a); i<(b); ++i)

#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)

#define FILL(a, b) memset(a, b, sizeof(a))



void dout() { cerr << endl; }



template <typename Head, typename... Tail>

void dout(Head H, Tail... T) {

    cerr << H << ' ';

    dout(T...);

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int n, t;

    cin >> n >> t;

    VI a(n);

    FOR(i, 0, n)

        cin >> a[i];

    VI prof(n);

    int mn = a[0];

    FOR(i, 1, n)

    {

        prof[i] = a[i] - mn;

        mn = min(mn, a[i]);

    }

    int mx = *max_element(ALL(prof));

    cout << count(ALL(prof), mx);

    return 0;

}