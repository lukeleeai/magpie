// Cmer's code modified by centipede_human



#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> VI;

typedef vector<vector<int>> VVI;

typedef vector<ll> VLL;

typedef vector<vector<ll>> VVLL;

typedef pair<ll, ll> Pair;

template <class T> T input() {T t; cin>>t; return t;}

#define FOR(i,a,b) for (ll i = a; i < b; i++)

#define REP(i,b) FOR(i,0,b)

#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)

#define RREP(i,a) RFOR(i,a,0)

#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)

#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)

#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)

#define ALL(x) (x).begin(), (x).end()

#define SORT(x) sort(ALL(x))

#define MIN_ELEMENT(x) min_element(ALL(x))

#define MAX_ELEMENT(x) max_element(ALL(x))

#define COUNT(x,num) count(ALL(x), num)

#define MEMSET(x,val) memset(x, val, sizeof(x))

#define CHMAX(a,b) a = max(a,b)

#define CHMIN(a,b) a = min(a,b)

#define FIND(x,key) x.find(key) != x.end()

#define IN_RANGE_V2(v,k,x,y) (0<=x+dx[k]&&x+dx[k]<v[y].size()&&0<=y+dy[k]&&y+dy[k]<v.size())

#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;

void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}

void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}

void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}

#define PRINT_ARRAY_H(a) REPALL(__i,a) {cout<<a[__i]<<(__i != a.size()-1 ? " " : "");} newline;

#define PRINT_ARRAY_V(a) REPALL(__i,a) {cout<<a[__i]<<endl;}

#define e1 first

#define e2 second

#define newline putchar('\n')

#define cspace ' '

#define sspace " "

const int INF = 1e7;

const ll MOD = 1e9 + 7;

const double pi = 3.141592653589793;

const VI dx = {1, 0, -1, 0};

const VI dy = {0, 1, 0, -1};

//const VI dx = {1, 1, 0, -1, -1, -1, 0, 1};

//const VI dy = {0, 1, 1, 1, 0, -1, -1, -1};



ll n, k;

VLL p, c;

VLL dp_score(5005);

VLL dp_cycle(5005);

VLL dp_max(5005);



void set_dp(ll idx)

{

    ll tscore = 0ll;

    ll tidx = idx;

    ll cnt = 0ll;

    REP(i,n) {

        cnt++;

        tscore += c[p[tidx]];

        CHMAX(dp_max[idx], tscore);

        if (p[tidx] == idx) {

            break;

        } else {

            tidx = p[tidx];

        }

    }

    dp_score[idx] = tscore;

    dp_cycle[idx] = cnt;

}



ll get_score(ll idx)

{

    ll tidx = p[idx];

    ll tans = c[tidx];

    ll tk = k-1;

    //cout<<idx<<": "<<endl;

    while (tk > 0) {

        if (tk < dp_cycle[tidx]) {

            ll tscore = tans;

            REP(i,tk) {

                tscore += c[p[tidx]];

                CHMAX(tans, tscore);

                tidx = p[tidx];

            }

            tk = 0;

        } else if (dp_score[idx] > 0) {

            ll tmp = tk / dp_cycle[tidx];

            tans += tmp * dp_score[tidx];

            tk -= tmp * dp_cycle[tidx];

        } else {

            tans += dp_max[tidx];

            tk = 0;

        }

        //cout<<tk<<sspace<<tans<<endl;

    }

    return tans;

}



void solve()

{

    ll ans = -(ll)(1e18) -1;

    cin>>n>>k;

    p.resize(n); c.resize(n);

    REP(i,n) {cin>>p[i]; p[i]--;}

    REP(i,n) {cin>>c[i];}

    REP(i,n) {

        set_dp(i);

        //cout<<i<<"->"<<dp_score[i]<<sspace<<dp_cycle[i]<<endl;

    }

    REP(i,n) {

        CHMAX(ans, get_score(i));

    }

    cout<<ans<<endl;

}



int main()

{

    cout<<fixed<<setprecision(20);

    int __t = 1;

    //cin>>__t;

    REP(i,__t) {

        solve();

    }

    return 0;

}
