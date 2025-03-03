#include "stdc++.h"

#define int long long

#define pii pair<int,int>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n) FOR(i,0,n)

#define ALL(c) (c).begin(),(c).end()

#define ZERO(a) memset(a,0,sizeof(a))

#define MINUS(a) memset(a,0xff,sizeof(a))

#define MINF(a) memset(a,0x3f,sizeof(a))

#define POW(n) (1LL<<(n))

#define IN(i,a,b) (a <= i && i <= b)

using namespace std;

template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }

template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }

template <typename T> inline void SORT(T& a) { sort(ALL(a)); }

template <typename T> inline void REV(T& a) { reverse(ALL(a)); }

template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }

template <typename T> inline T LB(vector<T>& v, T a) { return *lower_bound(ALL(v),a); }

template <typename T> inline int LBP(vector<T>& v, T a) { return lower_bound(ALL(v),a) - v.begin(); }

template <typename T> inline T UB(vector<T>& v, T a) { return *upper_bound(ALL(v),a); }

template <typename T> inline int UBP(vector<T>& v, T a) { return upper_bound(ALL(v),a) - v.begin(); }

template <typename T1, typename T2> ostream& operator<< (ostream& os, const pair<T1,T2>& p) { os << p.first << " " << p.second; return os; }

template <typename T1, typename T2> istream& operator>> (istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }

template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) { REP(i,v.size()) { if (i) os << " "; os << v[i]; } return os; }

template <typename T> istream& operator>> (istream& is, vector<T>& v) { for(T& in : v) is >> in; return is; }

template <typename T = int> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }

template <typename T, typename V> typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V> typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) { for(auto &e : t) fill_v(e,v); }

const int MOD = 1000000007;

const int INF = 0x3f3f3f3f3f3f3f3f;

const double EPS = 1e-10;



signed main() {

  cin.tie(nullptr);

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(10);



  auto c = make_v<int>(3,3);

  cin >> c;

  for (int i = 0; i <= 100; i++) {

    vector<int> b(3);

    for (int j = 0; j < 3; j++) {

      b[j] = c[0][j] - i;

    }

    if (c[1][0] - b[0] != c[1][1] - b[1] || c[1][1] - b[1] != c[1][2] - b[2]) continue;

    if (c[2][0] - b[0] != c[2][1] - b[1] || c[2][1] - b[1] != c[2][2] - b[2]) continue;

    cout << "Yes" << endl;

    return 0;

  }

  cout << "No" << endl;



  return 0;

}