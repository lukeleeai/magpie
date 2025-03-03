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

    

vector<pair<int, int> > vp;

 

struct Less {

    bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {

        return x.first > y.first;

    }

};

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)



ll GCD(ll a, ll b){

    if(b==0) return a;

    return GCD(b, a%b);

}

//グラフの隣接リスト

VI g[200010];

//頂点の入次数を管理

int h[100010];

ll N, K;

string s;

ll a[100010];

int main(void) {

    cin >> N >> K;

    REP(i, N) cin >> a[i];

    

    ll gcd=a[0];

    ll maxV=0;

    

    REP(i, N) maxV = max(maxV, a[i]);

    

    for(int i=1; i<N; ++i){

        gcd = GCD(gcd, a[i]);

    }

    if(K%gcd==0&&maxV>=K) cout << "POSSIBLE" << endl;

    else cout << "IMPOSSIBLE" << endl; 

	return 0;

}