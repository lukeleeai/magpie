

#include <iostream>

#include <math.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <queue>

#include <stack>

#include <vector>

#include <algorithm>

#include <map>

#include <unordered_map>

#include <set>

#include <deque>

#include <bitset>



long long mod = 1e9+7;

class Mint {

public:

  long long x;

  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく

  Mint(long long a){

    x = a%mod;

    while(x<0){

      x += mod;

    }

  };

  Mint& operator += (const Mint &a){

    x+=a.x;

    x%=mod;

    return *this;

  }

  Mint& operator -= (const Mint &a){

    x += (mod - a.x);

    x%=mod;

    return *this;

  }

  Mint& operator *= (const Mint &a){

    x*=a.x;

    x%=mod;

    return *this;

  }



  // a^n mod を計算する

  // Useaeg: Mint z = y.pow(y, n);

  Mint pow(Mint a, long long n) const {

    Mint y(1);

    Mint b(a);

    while (n > 0) {

      if (n & 1) y *= b;

      b *= b;

      n >>= 1;

    }

    return y;

  }



  // a^{-1} mod を計算する

  Mint modinv(const Mint &a) const {

    return pow(a, mod-2);

  }



  Mint& operator /= (const Mint &a) {

    x *= modinv(a).x;

    x %= mod;

    return *this;

  }



  Mint operator + (Mint &a) const {

    Mint y(*this);

    y += a;

    return y;

  }



  Mint operator - (Mint &a) const {

    Mint y(*this);

    y -= a;

    return y;

  }



  Mint operator * (Mint &a) const {

    Mint y(*this);

    y *= a;

    return y;

  }



  Mint operator / (Mint &a) const {

    Mint y(*this);

    y/=a;

    return y.x;

  }



  // nCk @mod を計算する

  Mint nCk(Mint &n, const long long k) const {

    Mint y = Mint(1);

    for (Mint i(0); (i.x)<k; i.x++){

      y *= (n-i);

      y /= i;

    }

    return y;

  }



  // nPk @mod を計算する

  Mint nPk(Mint &n, long long k) const {

    Mint y(1);

    for (Mint i(0); (i.x)<k; i.x++){

      y *= (n-i);

    }

    return y;

  }

};



struct node {

  int v;

  int supply;

  int amari;

};



class MyComparison {

public:

  bool operator()(node n1, node n2) {

    return (n1.supply!=n2.supply)?(n1.supply>n2.supply):(n1.amari<n2.amari);

  }

};



int main() {

  int H, W, N;

  std::cin >> H >> W >> N;

  std::vector<int > a(N), b(N);

  std::vector<std::pair<int, int>> point;

  //printf("aho\n");

  for (int i=0; i<N; i++) {

    std::cin >> a[i] >> b[i];

    a[i]--;

    b[i]--;

    for (int j=std::max(1, a[i]-1); j<=std::min(H-2, a[i]+1); j++) {

      for (int k=std::max(1, b[i]-1); k<=std::min(W-2, b[i]+1); k++) {

        point.push_back(std::make_pair(j, k));

      }

    }

  }

  //printf("hoge\n");

  std::vector<long long > cnt(10, 0);

  std::sort(point.begin(), point.end());

  //printf("hello\n");

  if (point.size()==0) {

    printf("%lld\n", (long long)(H-2)*(W-2));

    for (int i=1; i<=9; i++) {

      printf("0\n");

    }

    return 0;

  }

  int prev1 = point[0].first;

  int prev2 = point[0].second;

  int counter = 0;

  //printf("gomi\n");

  for (auto entry : point) {

    //printf("(%d, %d)\n", entry.first, entry.second);

    if ((prev1 == entry.first) && (prev2 == entry.second)) {

      counter++;

    } else {

      //printf("counter=%d\n", counter);

      cnt[counter]++;

      prev1 = entry.first;

      prev2 = entry.second;

      counter=1;

    }

  }

  cnt[counter]++;

  //printf("kudo\n");



  long long nonzero_sum = 0;

  for (int i=1; i<=9; i++) {

    nonzero_sum += cnt[i];

  }

  cnt[0] = (long long)(H-2)*(W-2)-nonzero_sum;

  for (int i=0; i<=9; i++) {

    std::cout << cnt[i] << std::endl;

  }

  return 0;

}