#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <climits>

#include <iostream>

#include <vector>

#include <string>

#include <sstream>

#include <algorithm>

#include <utility>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <deque>

#include <functional>



using namespace std;



#define int long long



#define fst first

#define scd second

#define PB push_back

#define MP make_pair

#define all(a) a.begin(),a.end()

#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false);cin.tie(0)

#define rep(i,x) for(int i=0;i<(int)(x);++i)

#define rep1(i,x) for(int i=1;i<=(int)(x);++i)



typedef long long ll;

typedef long double ld;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int, int> pii;

typedef vector<pii> vpii;



template<typename T>T& max(T&a,T&b){if(a>=b)return a;return b;}

template<typename T>T& min(T&a,T&b){if(a<b)return a;return b;}

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}

template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>T get(){T a;cin>>a;return a;}

template<typename T>T rev(T a){reverse(all(a));return a;}

template<typename T>vector<T>&sort(vector<T>&a){sort(all(a));return a;}



const int inf = 3e18;

const ll linf = 3e18;

const double eps = 1e-9;



int N, M, K;

int A[20005];

int memo[20005];



inline int rec(int now)

{

    if (~memo[now]) return memo[now];



    int res = inf;

    int mi = inf, ma = -inf;

    

    for (int i = 0, to = min(N - now, M); i < to; ++i) {

        mi = min(mi, A[now + i]);

        ma = max(ma, A[now + i]);



        res = min(res, K + (ma - mi) * (i + 1) + rec(now + i + 1));

    }



    if (res == inf) res = 0;



    return memo[now] = res;

}



signed main()

{ // #define int long long ?????????????????§scanf???????????¨???????????????????????\?????????????????????

    omajinai;

    cin >> N >> M >> K;



    rep(i, N) {

        cin >> A[i];

    }



    memset(memo, -1, sizeof (memo));



    cout << rec(0) << endl;

}