#include <iostream>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <functional>

#include <queue>

#include <string>

#include <cstring>

#include <numeric>

#include <cstdlib>

#include <cmath>

#include <map>

using namespace std;



typedef long long ll;



#define INF 10e10

#define rep(i,n) for(int i=0; i<n; i++)

#define rep_r(i,n,m) for(int i=m; i<n; i++)

#define END cout << endl

#define MOD 1000000007

#define pb push_back

// 昇順sort

#define sorti(x) sort(x.begin(), x.end())

// 降順sort

#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())



template<typename T>

map<T, long long> factorize(T x) {

  map<T, long long> res;

  for (long long i = 2; i * i <= x; ++i) {

    while (x % i == 0) {

      x /= i;

      res[i] += 1;

    }

  }

  if (x != 1) res[x]++;

  return res;

}



// x以上の要素の数を数える

template<typename T>

long long o_count(T x, vector<T> v) {

  long long cnt = 0;

  for (auto itr : v) {

    if (itr >= x){

      cnt++;

    }

  }

  return cnt;

}



int main() {

  int n; cin >> n;

  vector<int> cnt(n+1, 0);

  for (int i = 1; i <= n; ++i) {

    for (auto itr : factorize(i)) {

      cnt[itr.first] += itr.second;

    }

  }



  // 75, 25, 15, 5, 3

  int a,b,c,d,e;

  a = o_count(74, cnt);

  b = o_count(24, cnt);

  c = o_count(14, cnt);

  d = o_count(4, cnt);

  e = o_count(2, cnt);



  int res = 0;

  // 75

  res += a;

  // 24 * 3

  res += b * (e - 1);

  res += c * (d - 1);

  res += (d * (d - 1) * (e - 2)) / 2;



  cout << res << endl;

}
