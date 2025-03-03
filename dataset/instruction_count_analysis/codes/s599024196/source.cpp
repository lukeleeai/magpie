#include <cstdio>



const int MAXN = 1e5 + 10;



int N;

long long K;

long long freq[MAXN];



int main() {

  scanf("%d %lld", &N, &K);



  for (int i = 1; i <= N; ++i) {

    int a, b;

    scanf("%d %d", &a, &b);

    freq[a] += b;

  }



  int i = 1;

  long long k = 0;



  while (k + freq[i] < K) {

    k += freq[i];

    i++;

  }



  printf("%d\n", i);

  return 0;

}