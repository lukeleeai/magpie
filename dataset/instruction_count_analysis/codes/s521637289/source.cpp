#include <cstdio>

#include <algorithm>



const int MaxN = 100000 + 5;



int N;

long long A[MaxN];



void init() {

  scanf("%d", &N);

  for (int i = 1; i <= N; ++i) {

    scanf("%lld", &A[i]);

  }

}



void solve() {

  std::sort(A + 1, A + 1 + N);



  if (N % 2 == 0) {

    long long ans = 0;

    for (int i = 1; i < N / 2; ++i) {

      ans -= 2 * A[i];

    }

    ans -= A[N / 2];

    ans += A[N / 2 + 1];

    for (int i = N / 2 + 2; i <= N; ++i) {

      ans += 2 * A[i];

    }



    printf("%lld\n", ans);

  } else {

    long long ans1 = 0, ans2 = 0;



    for (int i = 1; i <= N / 2 - 1; ++i) {

      ans1 -= 2 * A[i];

    }

    ans1 -= A[N / 2] + A[N / 2 + 1];

    for (int i = N / 2 + 2; i <= N; ++i) {

      ans1 += 2 * A[i];

    }



    for (int i = 1; i <= N / 2; ++i) {

      ans2 -= 2 * A[i];

    }

    ans2 += A[N / 2 + 1] + A[N / 2 + 2];

    for (int i = N / 2 + 3; i <= N; ++i) {

      ans2 += 2 * A[i];

    }



    printf("%lld\n", std::max(ans1, ans2));

  }

}



int main() {

  init();

  solve();

  return 0;

}