#include <algorithm>

#include <cassert>

#include <cmath>

#include <climits>

#include <cstdlib>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <vector>

#define DEBUG 1

constexpr int kMod = 1000000007;

typedef long long LL;



int main() {

  int N, K; std::cin >> N >> K;

  int R, S, P; std::cin >> R >> S >> P;

  std::map<char, LL> score = {

    {'r', P},  {'s', R}, {'p', S}

  };



  std::vector<std::string> T(K, "");

  for (int i = 0; i < N; ++i) {

    char c; std::cin >> c;

    T[i%K] += c;

  }



  LL total_score = 0;

  for (std::string& s : T) {

    total_score += score[s[0]];

    for (int i = 1; i < s.size(); ++i) {

      if (s[i] == s[i-1]) s[i] = 'x';

      else                total_score += score[s[i]];

    }

  }



  std::cout << total_score << std::endl;

}
