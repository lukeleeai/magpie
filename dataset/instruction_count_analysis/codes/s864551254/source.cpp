#include <cstdio>

using namespace std;

typedef long long ll;

int N, A[100001];

int main() {

  scanf("%d", &N);

  ll ans = 0LL;

  for(int i = 1; i <= N; ++i) {

    scanf("%d", &A[i]);

    ans += A[i];

  }

  for(int i = 1; i <= N; ++i) {

    if(i%2 == 0) ans -= 2*A[i];

  }

  printf("%ld", ans);

  for(int i = 2; i <= N; ++i) {

    ans = 2*A[i-1]-ans;

    printf(" %ld", ans);

  }

}