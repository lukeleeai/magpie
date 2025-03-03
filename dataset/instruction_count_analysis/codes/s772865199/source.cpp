#include "stdc++.h"



using namespace std;



typedef long long LL;



int N, M;

double t1 = 1900, t2 = 100;



void Solve()

{

  t1 *= M;

  double ans = 0;

  int a = (N - M) * t2;

  int p = 1 << M;

  double pp = 1;

  for (int i = 1; i <= 1000000; ++i) {

    ans += (a + t1) * i / p * pp;

    pp = pp * (p - 1) / p;

  }

  int ians = ans + 0.5;

  printf("%d\n", ians);

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