// 基本テンプレート

 

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

#include <fstream>

#include <functional>

using namespace std;

 

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)

#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)

#define int long long int

 

template<typename T> void chmax(T &a, T b) {a = max(a, b);}

template<typename T> void chmin(T &a, T b) {a = min(a, b);}

template<typename T> void chadd(T &a, T b) {a = a + b;}

 

typedef pair<int, int> pii;

typedef long long ll;

 

int dx[] = {0, 0, 1, -1};

int dy[] = {1, -1, 0, 0};

const ll INF = 1001001001001001LL;

const ll MOD = 1000000007LL;

 

signed main() {

    int N; cin >> N;

    int S = 0, mi = INF, ans = 0;

    rep(i,0,N) {

        int x, s; cin >> x >> s;

        int prev = S, cur = S + s;

        prev -= x; cur -= x;

        mi = min(mi, prev);

        ans = max(ans, cur - mi);

        S += s;

    }

    cout << ans << endl;

    return 0;

}