#include <iostream>

#include <algorithm>

#include <vector>

#include <cstring>



using std::cin;

using std::cout;

using std::cerr;

using std::endl;



std::vector<int> eratosthenes() {

  bool is_prime[55556];

  std::vector<int> ret;



  std::fill(is_prime, is_prime + 55555, true);



  is_prime[0] = is_prime[1] = false;



  for (int i = 2; i <= 55555; ++i) {

    if (is_prime[i]) {

      ret.push_back(i);

      for (int j = 2; i * j <= 55555; ++j) {

        is_prime[i * j] = false;

      }

    }

  }



  return ret;

}





int main() {

  int n;



  cin >> n;



  std::vector<int> prime = eratosthenes(), ans;



  for (int i = 0; i < int(prime.size()); ++i) {

    if (prime[i] % 5 == 1) {

      ans.push_back(prime[i]);

      if (int(ans.size()) == n) {

        break;

      }

    }

  }



  for (int i = 0; i < int(ans.size()); ++i) {

    cout << ans[i] << " \n"[i == n - 1];

  }



  return 0;

}
