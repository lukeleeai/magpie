#include <iostream>

#include <vector>

#include <map>

#include <algorithm>



#define rep(i,n) for (int i = 0; i < (n); ++i)



int n, a, b, friends[100005], fri, ans;



/***************************************



           imos???version



***************************************/



int main() {

  std::cin.tie(0);

  std::ios::sync_with_stdio(false);



  std::cin >> n;

  rep(i,n) {

    std::cin >> a >> b;

    a--;

    friends[a]++;

    friends[b]--;

  }



  for (int i = 1; i <= n; ++i) friends[i] += friends[i-1];



  rep(i,n+1) {

      if (friends[i] >= i) {

          ans = std::max(ans, i);

      }

  }



  std::cout << ans << std::endl;



  return 0;

}