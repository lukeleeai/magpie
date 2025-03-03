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



std::string v[100000];

int main() {

  int N, K; std::cin >> N >> K;

  int R, S, P; std::cin >> R >> S >> P;



  for (int i = 0; i < N; ++i) {

    char c; std::cin >> c;

    switch (c) {

      case 'r': v[i%K] += 'p'; break;

      case 's': v[i%K] += 'r'; break;

      case 'p': v[i%K] += 's'; break;

    }

  }



  LL score = 0;

  for (int i = 0; i < K; ++i) {

    for (int j = 1; j < v[i].size(); ++j) {

      if (v[i][j-1] == v[i][j]) v[i][j] = 'x';

    }

    for (char c : v[i]) {

      switch(c) {

        case 'r': score += R; break;

        case 's': score += S; break;

        case 'p': score += P; break;

      }

    }

//    std::cout << v[i] << std::endl;

  }

  std::cout << score << std::endl;

}
