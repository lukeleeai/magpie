#include "stdc++.h"

using namespace std;

using ll = long long; using P = pair<int,int>;

using vl = vector<ll>; using vvl = vector<vl>;

#define mp make_pair

#define pb push_back

#define _overload3(_1,_2,_3,name,...) name

#define _rep(i,n) repi(i,0,n)

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)

#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define rrep(i,n) for (int i=(n-1);i >= 0;i--)

#define all(v) v.begin(),v.end()

#define sz(v) (int)((v).size())

#define MAX(v) *max_element(all(v))

#define MIN(v) *min_element(all(v))

#define Sort(v) sort(all(v))

#define Rev(v) reverse(all(v))

#define vec(type,name,...) vector<type> name(__VA_ARGS__)

#define VEC(type,name,size) vector<type> name(size);in(name)

#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))

#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T) {

    cout << H << " ";

    debug_out(T...);

}

#ifdef _DEBUG

#define debug(...) debug_out(__VA_ARGS__)

#else

#define debug(...) 

#endif

template <typename T>

std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {

    for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");

    return os;

}

inline void IN(void){return;}

template <typename First, typename... Rest>

void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}

template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}

template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}

const ll INF = 1LL << 60;

const ll mod = 1000000007;

const int dx[8] = {1,0,-1,0,1,1,-1,-1}; const int dy[8] = {0,1,0,-1,1,1,-1,-1};



int main(){

    cin.tie(0); ios::sync_with_stdio(false);

    string s,t;

    cin >> s >> t;

    // dp[i][j] = sのi文字目, tのj文字目までのLCSの長さ

    vector<vector<int>> dp(sz(s)+1, vector<int>(sz(t)+1));

    rep(i, 1, sz(s)+1) rep(j, 1, sz(t)+1) {

        if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;

        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    }

    int i = sz(s), j = sz(t);

    int len = dp[i][j];

    string ans = "";

    while(len > 0) {

        if(s[i-1] == t[j-1]) {

            ans = s[i-1] + ans;

            i--; j--; len--;

        } else if(dp[i][j] == dp[i-1][j]) {

            i--;

        } else {

            j--;

        }

    }

    cout << ans << endl;

}