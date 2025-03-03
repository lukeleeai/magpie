#include <cstdio>

using namespace std;



int main() {

  int N, K; scanf("%d %d", &N, &K);

  int A[100000]; for (int i = 0; i < N; i++) scanf("%d", &A[i]);

  printf("%d\n", (N + K - 3) / (K - 1));

  return 0;

}
