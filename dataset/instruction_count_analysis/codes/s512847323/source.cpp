#include <cstdio>

#include <cmath>

using namespace std;

typedef long long ll;

int N, A[100001];

int main() {

  scanf("%d", &N);

  ll sumA = 0LL;

  for(int i = 1; i <= N; ++i) {

    scanf("%d", &A[i]);

    sumA += A[i];

  }

  A[0] = A[N], A[N+1] = A[1];

  ll ans[100001] = {0LL};

  for(int i = 1; i <= N; ++i) {

    ans[1] += pow(-1, i%2+1)*A[i];

  }

  printf("%ld", ans[1]);

  for(int i = 2; i <= N; ++i) {

    ans[i] = 2*A[i-1]-ans[i-1];

    printf(" %ld", ans[i]);

  }

}