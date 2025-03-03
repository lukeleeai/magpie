#include"stdc++.h"



using namespace std;



using int64 = long long;

const int mod = 1e9 + 7;

const int inf = (1 << 30) - 1;

const int64 infll = (1LL << 61) - 1;



struct IoSetup {

  IoSetup() {

    cin.tie(nullptr);

    ios::sync_with_stdio(false);

    cout << fixed << setprecision(10);

    cerr << fixed << setprecision(10);

  }

} iosetup;



template< typename T >

ostream &operator<<(ostream &os, const vector< T > &v) {

  for(int i = 0; i < (int) v.size(); i++) {

    os << v[i] << (i + 1 != v.size() ? " " : "");

  }

  return os;

}



template< typename T >

istream &operator>>(istream &is, vector< T > &v) {

  for(T &in : v) is >> in;

  return is;

}



template< typename T1, typename T2 >

inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }



template< typename T1, typename T2 >

inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



template< typename T = int64 >

vector< T > make_v(size_t a) {

  return vector< T >(a);

}



template< typename T, typename... Ts >

auto make_v(size_t a, Ts... ts) {

  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));

}



template< typename T, typename V >

typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {

  t = v;

}



template< typename T, typename V >

typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {

  for(auto &e : t) fill_v(e, v);

}



#define int long long



vector< int > Luzhiled(vector< int > &X, vector< int > &Y, int D) {

  int N = (int) X.size();

  map< int, vector< pair< int, int > > > XX, YY;

  vector< int > ans(N);

  for(int i = 0; i < N; i++) {

    XX[X[i]].emplace_back(Y[i], i);

    YY[Y[i]].emplace_back(X[i], i);

  }

  for(auto &v : XX) sort(begin(v.second), end(v.second));

  for(auto &v : YY) sort(begin(v.second), end(v.second));

  for(int i = 0; i < N; i++) {

    for(auto x : {X[i] - D, X[i] + D}) {

      if(XX.count(x)) {

        auto &o = XX[x]; // これ参照じゃないとコピーされるのか　うくにきあちゃん....

        ans[i] += lower_bound(begin(o), end(o), make_pair(Y[i] + D, -1LL)) -

                  lower_bound(begin(o), end(o), make_pair(Y[i] - D, infll));

      }

    }

    for(auto y : {Y[i] - D, Y[i] + D}) {

      if(YY.count(y)) {

        auto &o = YY[y];

        ans[i] += lower_bound(begin(o), end(o), make_pair(X[i] + D, infll)) -

                  lower_bound(begin(o), end(o), make_pair(X[i] - D, -infll));

      }

    }

  }

  return ans;

}



signed main() {

  int N, A, B;

  cin >> N >> A >> B;

  --A, --B;

  vector< int > X(N), Y(N);



  map< int, map< int, int > > XX, YY;



  for(int i = 0; i < N; i++) {

    int a, b;

    cin >> a >> b;

    X[i] = a - b;

    Y[i] = a + b;

    XX[X[i]][Y[i]] = i;

    YY[Y[i]][X[i]] = i;

  }





  int D = max(abs(X[A] - X[B]), abs(Y[A] - Y[B]));



  vector< int > v(N);

  queue< int > que;

  v[A] = true;

  v[B] = true;

  que.emplace(A);

  que.emplace(B);



  while(que.size()) {

    auto p = que.front();

    que.pop();

    for(auto x : {X[p] - D, X[p] + D}) {

      if(XX.count(x)) {

        auto &o = XX[x];

        auto L = o.lower_bound(Y[p] - D);

        auto R = o.upper_bound(Y[p] + D);

        while(L != R) {

          if(!v[L->second]) {

            v[L->second] = true;

            que.emplace(L->second);

          }

          L = o.erase(L);

        }

      }

    }



    for(auto y : {Y[p] - D, Y[p] + D}) {

      if(YY.count(y)) {

        auto &o = YY[y];

        auto L = o.lower_bound(X[p] - D);

        auto R = o.upper_bound(X[p] + D);

        while(L != R) {

          if(!v[L->second]) {

            v[L->second] = true;

            que.emplace(L->second);

          }

          L = o.erase(L);

        }

      }

    }

  }

  auto tap = Luzhiled(X, Y, D);

  int64 ret = 0;

  for(int i = 0; i < N; i++) ret += 1LL * tap[i] * v[i];

  cout << ret / 2 << endl;

}




