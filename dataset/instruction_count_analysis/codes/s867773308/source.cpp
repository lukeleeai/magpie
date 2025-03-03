#include <iostream>

#include <iomanip>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <deque>

#include <set>

#include <map>

#include <utility>

#include <tuple>

#include <algorithm>

#include <cstdio>

#include <cmath>

using namespace std;



#define rep(i, n) for(int i = 0; i < (n); i++)

using ll = long long;



int main() {

  int N, M;

  cin >> N >> M;

  double p = 1/pow(2, M);

  int t = 1900*M+100*(N-M);

  double ans = 0, q = 1;

  for(int i = 1; ; i++) {

    if(t*i*q*p <= 0)

      break;

    ans += t*i*q*p;

    q *= 1-p;

  }

  cout << floor(ans+0.5) << endl;

  return 0;

}