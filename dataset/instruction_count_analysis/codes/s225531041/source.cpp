#include <iostream>

#include <algorithm>

#include <functional>

#include <map>

#include <ostream>

#include <queue>

#include <random>

#include <string>

#include <vector>

#include <cstdlib>

#include <cmath>

#include <cstring>



using std::cin;

using std::cout;

using std::cerr;

using std::endl;



using ll = long long;



inline void init() {

  cin.tie(0);

  std::ios::sync_with_stdio(false);

}



bool is_prime[300001];

std::vector<int> prime;



void eratosthenes(int n) {

  std::fill(is_prime, is_prime + 300000, true);



  is_prime[0] = is_prime[1] = false;



  for (int i = 2; i <= n; ++i) {

    if (is_prime[i]) {

      if (i <= 55555) prime.push_back(i);



      for (int j = 2; i * j <= n; ++j) {

        is_prime[i * j] = false;

      }

    }

  }



  return;

}



int main() {

  init();



  int N;



  cin >> N;



  eratosthenes(300000);



  std::vector<int> ans;



  for (int i = 0; i < prime.size(); ++i) {

    if (prime[i] % 5 == 1) {

      ans.push_back(prime[i]);

      if (ans.size() == N) {

        break;

      }

    }

  }



  for (int i = 0; i < N; ++i) {

    cout << ans[i] << " \n"[i == N - 1];

  }



  return 0;

}