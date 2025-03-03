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

#include <numeric>

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



int dx[]={1, -1, 0, 0};

int dy[]={0, 0, 1, -1};

int const MOD = 1000000007;

ll mod_pow(ll x, ll n) {return (!n)?1:(mod_pow((x*x)%MOD,n/2)*((n&1)?x:1))%MOD;}

int madd(int a, int b) {return (a + b) % MOD;}

int msub(int a, int b) {return (a - b + MOD) % MOD;}

int mmul(int a, int b) {return (a * b) % MOD;}

int minv(int a) {return mod_pow(a, MOD-2);}

int mdiv(int a, int b) {return mmul(a, minv(b));}



namespace std {

    bool operator<(const P& a, const P& b) {

        return a.X != b.X ? a.X < b.X : a.Y < b.Y;

    }

}



// step[i] := ?????? 0 ????????¨????????¨????????????????????? i ???????????????????????¨????????¢

// ans [i] := ?????? i ????????¨????????¨????????????????????? i ???????????????????????¨????????¢

// ?????? i ??????????????????????????§???????????? 1 ???????????????????????????????????\?????? 2 ?????????

// ???????????£???????????????????????? 2 * (n-1) - ans[i] ??§??????



int step[100010], ans[100010];

vector<int> G[100010];



void dfs(int idx, int par) {

    for(auto to : G[idx]) {

        if(to == par) continue;

        dfs(to, idx);

        step[idx] = max(step[idx], step[to] + 1);

    }

}



void dfs2(int idx, int d_par, int par) {

    vector<pii> rec;

    rec.push_back(pii(0, -1));

    for(auto to : G[idx]) {

        if(to == par) rec.push_back(pii(d_par + 1, to));

        else rec.push_back(pii(step[to] + 1, to));

    }

    sort(rec.rbegin(), rec.rend());

    ans[idx] = rec[0].first;

    for(auto to : G[idx]) {

        if(to == par) continue;

        dfs2(to, rec[ rec[0].second == to ].first, idx);

    }

}



signed main() {

    int n; cin >> n;

    rep(i,0,n-1) {

        int u, v; cin >> u >> v;

        u--; v--;

        G[u].push_back(v);

        G[v].push_back(u);

    }

    dfs(0, -1);

    dfs2(0, 0, -1);

    rep(i,0,n) cout << (n-1) * 2 - ans[i] << endl;

    return 0;

}