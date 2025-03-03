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

    sort(a, a+N);

    vector<int> v;

    for(int i=N-1; i>=1; --i){

        if(v.size()==2) break;

        if(a[i]==a[i-1]) {

            v.push_back(a[i]);

            --i;

        }

    }

    if(v.size()==2) cout << (long long)v[0]*v[1] << endl;

    else cout << 0 << endl;

	return 0;

}
