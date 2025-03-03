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





int main() {

  int n; cin >> n;

  vector<ll> fac(111,0);

  for (int i = 1; i <= n; ++i) {

    for (auto pa : factorize(i)) {

      fac[pa.first] += pa.second;

    }

  }



  ll ans = 0;



  if (fac[2] >= 74) ans++;

  for (int i = 2; i < 111; ++i) {

    for (int j = 2; j < 111; ++j) {

      if (i != j and fac[i] >= 2 and fac[j] >= 24) ans++;

    }

  }



  for (int i = 2; i < 111; ++i) {

    for (int j = 2; j < 111; ++j) {

      if (i != j and fac[i] >= 4 and fac[j] >= 14) ans++;

    }

  }



  for (int i = 2; i < 111; ++i) {

    for (int j = 2; j < 111; ++j) {

      for (int k = 2; k < j; ++k) {

        // here

        if (i != j and i != k and fac[i] >= 2 and fac[j] >= 4 and fac[k] >= 4) ans++;

      }

    }

  }



  cout << ans << endl;

}



/*

#include"stdc++.h"

using namespace std;

using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}

template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}





template<typename T>

map<T, Int> factorize(T x){

  map<T, Int> res;

  for(Int i=2;i*i<=x;i++){

    while(x%i==0){

      x/=i;

      res[i]++;

    }

  }

  if(x!=1) res[x]++;

  return res;

}



//INSERT ABOVE HERE

signed main(){

  Int n;

  cin>>n;



  vector<Int> cnt(111,0);

  for(Int i=1;i<=n;i++){

    for(auto p:factorize(i))

      cnt[p.first]+=p.second;

  }



  Int ans=0;

  // 75 = 74 + 1

  if(cnt[2]>=74) ans++;



  // 75 = (2 + 1) * (24 + 1)

  for(Int i=2;i<111;i++)

    for(Int j=2;j<111;j++)

      if(i!=j&&cnt[i]>=2&&cnt[j]>=24) ans++;





  // 75 = (4 + 1) * (14 + 1)

  for(Int i=2;i<111;i++)

    for(Int j=2;j<111;j++)

      if(i!=j&&cnt[i]>=4&&cnt[j]>=14) ans++;



  // 75 = (2 + 1) * (4 + 1) * (4 + 1)

  for(Int i=2;i<111;i++)

    for(Int j=2;j<111;j++)

      for(Int k=2;k<j;k++)

        if(i!=j&&i!=k&&cnt[i]>=2&&cnt[j]>=4&&cnt[k]>=4) ans++;



  cout<<ans<<endl;

  return 0;

}

*/
