#include "stdc++.h"



using namespace std;



typedef long long LL;



int N, M;



void Solve()

{

  int tot = 1900 * M + 100 * (N - M);

  int p = 1 << M;

  int ans = tot * p;

  printf("%d\n", ans);

}



int main()

{

#ifdef linjian

freopen("in", "r", stdin);

#endif

  scanf("%d%d", &N, &M);

  Solve();

  return 0;

}