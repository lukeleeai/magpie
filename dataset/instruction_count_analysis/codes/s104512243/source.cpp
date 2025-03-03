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

#include <set>

#include <bitset>

#include <functional>

using namespace std;

const constexpr int INF = 1e9;

//typedef std::pair<std::string,double> P;





#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)



typedef long long ll;

typedef vector<int> VI;

const constexpr ll MOD = 1e9+7;

vector<pair<int, int> > vp;

 

struct Less {

    bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {

        return x.first > y.first;

    }

};



ll GCD(ll a, ll b){

    if(b==0) return a;

    return GCD(b, a%b);

}





//グラフの隣接リスト

VI g[200010];

//頂点の入次数を管理

int h[100010];

int s[100010];

int main(void) {

    int N; cin >> N;

    REP(i, N) {

        int a; cin >>a; a--;

        s[i] = a;

    }

    s[N]=0;

    int cnt=0;

    for(int i=0; i<N; ++i){

        if(s[i]==i){

            swap(s[i], s[i+1]);

            cnt++;

        }

    }

    cout << cnt << endl;

    

}