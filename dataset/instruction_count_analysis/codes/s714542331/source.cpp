#include <stdio.h>

#include <stdlib.h>

long long min(long long a, long long b){

    if(a < b) return a;

    else return b;

}

long long max(long long a, long long b){

    if(a < b) return b;

    else return a;

}

long long INF = 1e18;

int main(){

  int N, K;

  scanf("%d %d", &N, &K);

  long long a[N];

  for(int i = 0; i < N; i++) scanf("%lld", &a[i]);

  long long ans = INF;

  for(int i = 0; i < N; i++){

      if(i + K - 1 >= N) break;

      long long b = a[i], c = a[i + K - 1];

      if(b < 0 && c >= 0) ans = min(ans, llabs(c) + llabs(b) + min(llabs(c), llabs(b)));

      else ans = min(ans, max(llabs(b), llabs(c)));

  }

  printf("%lld\n", ans);

}
