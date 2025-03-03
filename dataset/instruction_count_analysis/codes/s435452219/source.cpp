#include <iostream>

#include <cmath>

#include <algorithm>



int c[100001];



int main() {

  long long int n;

  long long int count = 0;

  std::cin >> n;

  for (int i = 0; i < 100001; ++i)

    c[i] = 0;

  for (long long int i = 0; i < n; ++i) {

    int x = 0;

    std::cin >> x;

    if (x >= 100001) {

      count++;

      continue;

    }   

    c[x]++;

  }

  for (int i = 1; i < 100001; ++i) {

    count += (c[i] < i) ? c[i]: c[i] - i;

  }

  std::cout << count << std::endl;

  return 0;

}
