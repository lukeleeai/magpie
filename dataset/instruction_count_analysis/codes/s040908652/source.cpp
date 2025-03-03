#include <iostream>

#include <vector>

#include <map>

#include <algorithm>

 

#define rep(i,n) for (int i = 0; i < (n); ++i)

  

int n, a, b, friends[100005], fri, maxi;



int main() {

  std::cin.tie(0);

  std::ios::sync_with_stdio(false);



  std::cin >> n;

  rep(i,n) {

    std::cin >> a >> b;

    a--; b--;

    for (int i = a; i <= b; ++i) friends[i]++;

  }

  rep(i,n+1) {

    if (friends[i] >= i) {

        maxi = i;

    }

  }



  std::cout << maxi << std::endl;



  return 0;

}