#include <iostream>

#include <sstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cstring>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <numeric>

#include <utility>

#include <iomanip>

#include <algorithm>

#include <functional>

using namespace std;



#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)

{ return s << '<' << P.first << ", " << P.second << '>'; }

template<class T> ostream& operator << (ostream &s, vector<T> P)

{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }

template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)

{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }

template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)

{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }









long long N, Z, W;

long long a[10001];



long long dp[5100][3];



long long rec(int cur, bool sente) {

    if (dp[cur][sente] != -1) return dp[cur][sente];

    long long aite = -1;

    if (cur == 0) aite = W;

    else aite = a[cur-1];

    

    if (cur == N-1) return abs(a[N-1] - aite);

    

    long long res = -1;

    if (sente) {

        long long Max = abs(aite - a[N-1]);

        for (int j = cur; j < N-1; ++j) {

            long long tmp = rec(j+1, false);

            chmax(Max, tmp);

        }

        res = Max;

    }

    else {

        long long Min = abs(aite - a[N-1]);

        for (int j = cur; j < N-1; ++j) {

            long long tmp = rec(j+1, true);

            chmin(Min, tmp);

        }

        res = Min;

    }

    

    //cout << cur << ", " << sente << ": " << res << endl;

    

    return dp[cur][sente] = res;

}











int main() {

    while (cin >> N >> Z >> W) {

        for (int i = 0; i < N; ++i) cin >> a[i];

        memset(dp, -1, sizeof(dp));

        cout << rec(0, true) << endl;

    }

}
































