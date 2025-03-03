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





int main(){

    ll h, w; cin >> h >> w;

    vector<string> maze(h);

    rep(i, h) cin >> maze[i];

    ll ans = -1;

    // スタート地点を全探索

    rep(sh, h){

        rep(sw, w){

            if(maze[sh][sw] == '#') continue;

            // 未訪問 -1 に初期化

            vector<vector<ll>> seen(h, vector<ll>(w, -1));

            seen[sh][sw] = 0;

            queue<pll> q;

            q.push(pll(sh, sw));

            while(!q.empty()){

                pll now = q.front(); q.pop();

                rep(i, 4){

                    ll nh = now.first + dy[i], nw = now.second + dx[i];

                    // 訪問済みなら訪れない

                    if(0 <= nh && nh < h && 0 <= nw && nw < w && maze[nh][nw] == '.' && seen[nh][nw] == -1) seen[nh][nw] = seen[now.first][now.second] + 1, q.push(pll(nh, nw));

                }

            }

            ll cnt = -1;

            // 終点を全探索

            rep(hi, h) rep(wi, w) chmax(cnt, seen[hi][wi]);

            // 最大値の最大化

            chmax(ans, cnt);

        }

    }

    cout << ans << endl;

}
