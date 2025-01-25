#define _CRT_SECURE_NO_WARNINGS

// #define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

typedef long long ll;

// #define int ll

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int,int> pii;

#define all(c) begin(c), end(c)

#define loop(i,a,b) for(ll i=a; i<ll(b); i++)

#define rep(i,b) loop(i,0,b)

#define loopi(i,a,b) for(ll a=a;i<=ll(b);i++)

#define repi(i,b) loopi(i,1,b)

#define pb push_back

#define eb emplace_back

#define mp make_pair

#define mt make_tuple

template<class T> ostream & operator << (ostream &os, vector<T> const &);

template<int n, class...T>

typename enable_if<(n>=sizeof...(T))>::type

_ot(ostream &, tuple<T...> const &){}

template<int n, class...T>

typename enable_if<(n< sizeof...(T))>::type

_ot(ostream &os, tuple<T...> const &t){

    os << (n==0?"":" ") << get<n>(t); _ot<n+1>(os, t);

}

template<class...T>

ostream & operator << (ostream &os, tuple<T...> const &t){

    _ot<0>(os, t); return os;

}

template<class T, class U>

ostream & operator<<(ostream &os, pair<T,U> const &p){

    return os << "(" << p.first << ", " << p.second << ") ";

}

template<class T>

ostream & operator<<(ostream &os, vector<T> const &v){

    rep(i,v.size()) os << v[i] << (i+1==(int)v.size()?"":" "); return os;

}

#ifdef DEBUG

#define dump(...) (cerr << #__VA_ARGS__ << " = " << mt(__VA_ARGS__) \

                   << " [" << __LINE__ << "]" << endl)

#else

#define dump(...)

#endif

void fastios(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    // #define endl "\n"

}

template<class T>

size_t uniq(vector<T> &v){

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    return v.size();

}

template<class T>

size_t uniq(T *l, size_t n){

    sort(l,l+n);

    return unique(l,n) - l;

}

#define mems(arr,val) memset(arr,val,sizeof(arr));

int const mod = 1000000007;

int const inf = numeric_limits<int>::max()/10;



int popcount(unsigned long long x){

    static int dp[66000];

    if(dp[65536] != 16) for(int i = 0; i < 65536; i++) dp[i] = (i&1) + dp[i>>1];

    int res = 0;

    while(x) res += dp[x&65535], x >>= 16;

    return res;

}



int solve(ll s, ll d){

    //if(s <= 0 && d >= 0) return __builtin_popcount(-s) + __builtin_popcount(d);

    if(s <= 0 && d >= 0) return popcount(-s) + popcount(d);

    else if(s >= 0 && d >= 0){

        int j = 0;

        int ans = 0;

        while(s < d){

            if((s>>j&1) && (d>>j&1)){

                s += 1LL<<j;

                d -= 1LL<<j;

                ans += 2;

            } else if((s>>j&1) ^ (d>>j&1)){

                s += 1LL<<j;

                ans ++;

            }

            j++;

        }

        return ans;

    } else return solve(-d,-s);

}



signed main(){

    fastios();

    int N;

    cin >> N;

    rep(i,N){

        ll s,d;

        cin >> s >> d;

        cout << solve(s,d) << endl;

    }

}