#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <map>

#include <cmath>

#include <queue>

#include <numeric>

#include <climits>

#include <iterator>

#include <iomanip>

#include <stack>

#include <bitset>

#include <functional>

using namespace std;

const constexpr int INF = 1e9;

//typedef std::pair<std::string,double> P;



typedef long long ll;

typedef vector<int> VI;



#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)



//グラフの隣接リスト

VI g[200010];

//頂点の入次数を管理

int h[100010];

ll N;



int a[200010];

ll sum[200010];

signed main(void) {

    cin >> N;

    REP(i, N) cin >> a[i];

    FOR(i, 0, N) sum[i+1] = sum[i]+a[i];

    

    ll ans=10000000000;

    for(int i=1; i<N; ++i){

        ans = min(ans, abs(sum[N]-sum[i]-sum[i]));

    }

    cout << ans << endl;

	return 0;

}
