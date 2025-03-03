//#define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

/*using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

#define all(v) v.begin(), v.end()

#define allr(v) v.rbegin(), v.rend()*/





int main() {

  long long int n, ans = 0;

 

  scanf("%lld", &n);

 

  vector<long long int> a(3 * n);

 

  for (int i = 0; i < 3 * n; i++)

  {

    scanf("%lld", &a[i]);

}

    sort(a.begin(), a.end(), greater<int>());

 

  for (int i = 0; i < n; i++)

  {

    ans += a[2 * i + 1];

  }

 

  printf("%lld", ans);

}


