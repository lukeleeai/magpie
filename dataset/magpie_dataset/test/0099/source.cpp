#include <array>

#include <cstdlib>

#include <cmath>

#include <climits>

#include <cfloat>

#include <map>

#include <utility>

#include <set>

#include <iostream>

#include <memory>

#include <string>

#include <vector>

#include <algorithm>

#include <functional>

#include <sstream>

#include <deque>

#include <complex>

#include <stack>

#include <queue>

#include <cstdio>

#include <cctype>

#include <cstring>

#include <ctime>

#include <iterator>

#include <bitset>

#include <numeric>

#include <list>

#include <iomanip>

#include <tuple>

using namespace std;





typedef long long LL;

typedef pair<int,int> pii;

typedef pair<LL,LL> pll;



typedef vector<int> vint;

typedef vector<vector<int> > vvint;

typedef vector<long long> vll, vLL;

typedef vector<vector<long long> > vvll, vvLL;



#define VV(T) vector<vector< T > >



template <class T>

void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){

	v.assign(a, vector<T>(b, t));

}



template <class F, class T>

void convert(const F &f, T &t){

	stringstream ss;

	ss << f;

	ss >> t;

}



template <class T>

T clampMax(const T& a, const T& b) { return min(a, b); }



template <class T>

T clampMin(const T& a, const T& b) { return max(a, b); }





#define REP(i,n) for(int i=0;i<int(n);++i)

#define ALL(v) (v).begin(),(v).end()

#define RALL(v) (v).rbegin(),(v).rend()

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define PB push





#define MOD 1000000007LL

#define EPS 1e-10



const int MAX_N = 100010;

const int INF_COST = 2000000000;

int N, K;

int h[MAX_N];

int dp[MAX_N];



int main()

{

    cin >> N >> K;

    REP(i, N) cin >> h[i];

    REP(i, MAX_N) dp[i] = INF_COST;

    dp[N - 1] = 0;

    for (int i = N - 2; i >= 0; --i)

    {

        REP(j, K)

        {

            int pos = i + (j + 1);

            int cost = dp[pos] + abs(h[i] - h[pos]);

            dp[i] = min(dp[i], cost);

        }

    }

    cout << dp[0] << endl;

    return 0;

}