/**

 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏

 *    created : 2020-01-18 20:36:11

**/



#include <cstdio>

/*

#include <deque>

#include <map>

#include <queue>

#include <set>

#include <stack>

#include <string>

*/

#include <vector>

#include <algorithm>

/*

#include <cmath>

#include <complex>

#include <numeric>

#include <bitset>

#include <cassert>

#include <cctype>

*/

#include <iomanip>

//#include <random>

#include <utility>

//#include <chrono>





using namespace std;



using int64 = long long;



template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) { os << '{'; size_t n = vec.size(); for (size_t i = 0; i < n; ++i) { os << vec[i]; if (i != n - 1) os << ','; } os << '}'; return os; }

template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }

template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) { size_t n = vec.size(); for (size_t i = 0; i < n; ++i) is >> vec[i]; return is; }



#ifdef LOCAL

#define debug(_) cerr << #_ << ": " << (_) << '\n'

#define getchar_unlocked getchar

#else

#define debug(_) 1728

#endif



template<class T> inline void fastin(T &num) {

  T c;

  num = 0;

  c = getchar_unlocked();

  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;

}



int main() {

  //ios_base::sync_with_stdio(false);

  //cin.tie(nullptr);



  int n; fastin(n);

  vector<pair<int64, int64>> v;

  for (int i = 0; i < n; ++i) {

    int64 x, l; fastin(x); fastin(l);

    v.emplace_back(x - l, x + l);

  }



  sort(v.begin(), v.end(), [](const pair<int64, int64>& p, const pair<int64, int64>& q){

    return p.second < q.second;

  });



  //debug(v);



  int64 last = v[0].second;

  int ans = 0;



  for (int i = 1; i < n; ++i) {

    if (v[i].first < last) {

      ++ans; continue;

    }

    last = v[i].second;

  }



  //cout << n - ans << endl;

  printf("%d\n", n - ans);



  return 0;

}