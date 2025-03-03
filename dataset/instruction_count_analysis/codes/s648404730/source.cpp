#include "stdc++.h"

using namespace std;

typedef long long ll;

using pll = pair<ll, ll>;

#define rep(i, n) for(ll i = 0; i < n; i++)

#define rrep(i, m, n) for(ll i = m; i > n; i--)

#define Rep(i, m, n) for(ll i = m; i < n; i++)

#define all(vec) vec.begin(), vec.end()

#define lmax(x, y) max<ll>(x, y)

#define lmin(x, y) min<ll>(x, y)

#define tmax(x, y, z) lmax((x), lmax((y), (z)))

#define tmin(x, y, z) lmin((x), lmin((y), (z)))

#define MINUS(a) memset(a, 0xff, sizeof(a))

#define ZERO(a) memset(a, 0, sizeof(a))

const ll INF = 1LL << 60;

const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1

#define ADD(a,b) a = (a + ll(b)) % MOD

#define MUL(a,b) a = (a * ll(b)) % MOD

ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}

ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}

template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}

template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}

template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}

// struct edge{ ll from, to, cost; };

// struct edge{ ll to, cost; };

// using Graph = vector<vector<ll>>;  // 重み無し

// using Graph = vector<edge>;  // 辺

// using Graph = vector<vector<edge>>;  // 重み付き

ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

//cout << fixed << setprecision(10);

// priority_queue<ll, vector<ll>, greater<ll>> pq;







const ll MAX_V = 400;  // 最大頂点数(制約に従う)

ll d[MAX_V][MAX_V];  // 全体をINF、d[i][i]を0に初期化(d[i][j]:=iからjへの最短距離)

// 初期化

// FILL(d, INF);

// rep(i, V) d[i][i] = 0;  // V: 実際の頂点数





// 0-basedに注意

void warshall_floyd(ll V){  // 実際の頂点数

    // 経由頂点, 始点, 終点

    rep(k, V) rep(i, V) rep(j, V) chmin(d[i][j], d[i][k] + d[k][j]);

}







int main(){

    ll h, w; cin >> h >> w;

    ll V = h*w;

    vector<string> maze(h);

    rep(i, h) cin >> maze[i];

    FILL(d, INF);

    rep(i, V) d[i][i] = 0;

    rep(hi, h){

        rep(wi, w){

            if(maze[hi][wi] == '#') continue;

            rep(i, 4){

                ll nh = hi + dy[i], nw = wi + dx[i];

                if(0 <= nh && nh < h && 0 <= nw && nw < w && maze[nh][nw] == '.') d[hi*w + wi][nh*w + nw] = d[nh*w + nw][hi*w + wi] = 1;

            }

        }

    }

    warshall_floyd(V);

    ll ans = -1;

    rep(hi, h){

        rep(wi, w){

            if(maze[hi][wi] == '#') continue;

            ll cnt = -1;

            rep(i, h){

                rep(j, w){

                    if((hi == i && wi == j) || maze[i][j] == '#') continue;

                    chmax(cnt, d[hi*w + wi][i*w + j]);

                }

            }

            chmax(ans, cnt);

        }

    }

    cout << ans << endl;

}
