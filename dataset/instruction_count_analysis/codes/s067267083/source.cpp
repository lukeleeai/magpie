#include <cstdio>



using namespace std;



int main()

{

  int k, s;

  int i;

  long long ans = 0;

  int target;



  scanf("%d %d", &k, &s);



  // exhaustion



  for (i=0; i<=k; i++) {

    target = s - i;

    if (target < 0) break;

    if (target > 2 * k) {

      continue;

    } else if (target >= k) {

      ans += (2 * k) - target + 1;

    } else {

      ans += target + 1;

    }

  }

  printf("%lld\n", ans);

  return 0;

}
