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



typedef long long ll;

typedef vector<int> vint;

typedef vector<long long> vll;

typedef pair<int,int> pint;

typedef pair<long long, long long> pll;



#define MP make_pair

#define PB push_back

#define ALL(s) (s).begin(),(s).end()

#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 

{ return s << '<' << P.first << ", " << P.second << '>'; }

template<class T> ostream& operator << (ostream &s, vector<T> P) 

{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }

template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 

{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }





const int MAX = 200000;

const ll INF = 1LL<<61;



int n, k;

long long a[MAX];



int main() {

    while (cin >> n >> k) {

        if (n == 0) break;

        memset(a, 0, sizeof(a));

        for (int i = 0; i < n; ++i) cin >> a[i+1];

        for (int i = 0; i <= n; ++i) a[i+1] += a[i];

        

        long long res = -INF;

        for (int i = 0; i + k <= n; ++i) {

            chmax(res, a[i+k] - a[i]);

        }

        cout << res << endl;

    }

    return 0;

}
