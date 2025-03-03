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

  int x = 1900*M+100*(N-M);

  double p = 1/pow(2, M);

  /*

  かかる時間の期待値をEとする

  まず、最低でも1回は提出しないと成功しないので

    E = x + ?

  1回目で成功した場合、その後にかかる時間は0なので

    E = x + p*0 + ?

  1回目で成功しなかった場合、2回目から再度スタートする

  何回連続で失敗しても、次の回で成功する確率はpなので

  2回目からスタートして終わるまでにかかる時間の期待値もEとなる

  よって

    E = x + p*0 + (1-p)*E

  これを変形すると

  　E = x/p

  となる

  */

  cout << x/p << endl;

  return 0;

}