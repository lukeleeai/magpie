#include <iostream>

#include <iomanip>

#include <cstdio>

#include <string>

#include <cstring>

#include <deque>

#include <list>

#include <queue>

#include <stack>

#include <vector>

#include <utility>

#include <algorithm>

#include <map>

#include <set>

#include <complex>

#include <cmath>

#include <limits>

#include <cfloat>

#include <climits>

#include <ctime>

#include <cassert>

using namespace std;



#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)

#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)

#define all(v) begin(v), end(v)

#define pb(a) push_back(a)

#define fr first

#define sc second

#define INF 2000000000

#define int long long int



#define X real()

#define Y imag()

#define EPS (1e-10)

#define EQ(a,b) (abs((a) - (b)) < EPS)

#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )

#define LE(n, m) ((n) < (m) + EPS)

#define LEQ(n, m) ((n) <= (m) + EPS)

#define GE(n, m) ((n) + EPS > (m))

#define GEQ(n, m) ((n) + EPS >= (m))



typedef vector<int> VI;

typedef vector<VI> MAT;

typedef pair<int, int> pii;

typedef long long ll;



typedef complex<double> P;

typedef pair<P, P> L;

typedef pair<P, double> C;



int dy[]={0, 0, 1, -1};

int dx[]={1, -1, 0, 0};

int const MOD = 1000000007;



namespace std {

    bool operator<(const P& a, const P& b) {

        return a.X != b.X ? a.X < b.X : a.Y < b.Y;

    }

}



int t[100010], a[100010], rec[100010];

signed main() {

    int n; cin >> n;

    rep(i,0,n) cin >> t[i];

    rep(i,0,n) cin >> a[i];

    memset(rec, -1, sizeof(rec));



    int ans = 1;

    bool T[100010], A[100010] = {};

    T[0] = true, A[n-1] = true;

    rep(i,0,n-1) {

        if(t[i] < t[i+1]) T[i+1] = true;

    }

    repr(i,n-1,1) {

        if(a[i] < a[i-1]) A[i-1] = true;

    }

    rep(i,0,n) {

        // printf("i = %lld, T[i] = %d, A[i] = %d\n", i, T[i], A[i]);

        if(T[i] && A[i]) {

            if(t[i] != a[i]) ans *= 0;

        }

        else if(T[i]) {

            if(t[i] > a[i]) ans *= 0;

        }

        else if(A[i]) {

            if(a[i] > t[i]) ans *= 0;

        }

        else ans = (ans * min(t[i], a[i])) % MOD;

    }

    cout << ans << endl;

    return 0;

}