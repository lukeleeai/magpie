#include <cstdio>

#include <algorithm>

using namespace std;





int main() {

  

  int n, k, ans = 1;

  scanf("%d %d", &n, &k);

  if (n == 1)

    printf("%d\n", k);

  else {

    ans *= k;

    for (int i = 2; i <= n; i++)

      ans *= (k-1);

    

    printf("%d\n", ans);

  }

  

  

  

  return 0;

  

}


