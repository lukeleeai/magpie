bool DBG = false;

#include"stdc++.h"

//#include <boost/multiprecision/cpp_dec_float.hpp>

//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

using ll = long long;

using ld = long double;

//using i128 = __int128_t;

//using bint = boost::multiprecision::cpp_int

//using d1024 = boost::multiprecision::number<mp::cpp_dec_float<1024>>;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)

#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)

#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)

#define ALL(x) x.begin(),x.end()

#define fs first

#define sd second

#define couts(x) cout << (x) << (" ")

#define coutn(x) cout << (x) << ("\n")

#define endl "\n"

#define pb push_back

#define eb emplace_back

#define lb lower_bound

#define ub upper_bound

#define dcouts(x) if(DBG) couts(x)

#define dcoutn(x) if(DBG) coutn(x);

template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }

template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }

template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }

template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }

template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }



template<class T> using V = vector<T>;

template<class T> using V2 = V<V<T>>;

template<class T> using V3 = V<V2<T>>;



constexpr ll mod = 1000000007;





/*void solve(){

  int n, k; cin >> n >> k;

  auto f = [&](V<int> &v){

    int ret = 0;

    FOR(i,0,(int)v.size()) ret += abs(i-v[i]);

    return ret;

  };

  V<int> a(n), b(n*n+1,0);

  FOR(i,0,n) a[i] = i;

  do{

    b[f(a)]++;

  }while(next_permutation(ALL(a)));

  while(*(b.end()-1)==0) b.pop_back();

  coutn(b[k]);

}*/



void solve(){

  int n, k; cin >> n >> k;

  V2<ll> dp(n+5, V<ll>(n*n+5, 0));

  dp[0][0] = 1;

  FOR(i,1,n+1){

    V2<ll> dp_pre(n+5, V<ll>(k+5, 0));

    swap(dp, dp_pre);

    FOR(j,0,n+1){

      FOR(l,0,k+1){

        if(l-2*j>=0)(dp[j][l]+=(2*j+1)*dp_pre[j][l-2*j]%mod +(j+1)*(j+1)*dp_pre[j+1][l-2*j]%mod ) %= mod;

        if(l-2*j>=0 && j>0) (dp[j][l] += dp_pre[j-1][l-2*j])%= mod;

      }

    }

  }

  coutn(dp[0][k]);

  //coutn(dp);

}





int main(void){

  cin.tie(0);

  ios::sync_with_stdio(false);

  solve();

  return 0;

}