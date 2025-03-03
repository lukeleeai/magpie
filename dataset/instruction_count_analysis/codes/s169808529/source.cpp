#include<cstdio>



int main() {

  int N, T; scanf("%d %d\n", &N, &T);

  int t[N];



  for (int i = 0; i < N; i++)

    scanf("%d", &t[i]);



  long ans = 0;

  for (int i = 1; i < N; i++) {

    if (t[i] - t[i-1] >= T)

      ans += T;

    else

      ans += t[i] - t[i-1];

  }

  ans += T;



  printf("%ld\n", ans);

}
