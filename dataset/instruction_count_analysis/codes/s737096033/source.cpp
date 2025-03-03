#include "stdc++.h"

using namespace std;

#include <stdlib.h>

int asc(const void *a, const void *b) {

   return *(int *)a - *(int *)b;

}

#define MIN(a,b) ((a)<(b)?(a):(b))

int main(void) {

   int N, K;

   int ans = 1000000010;

   int L[1000000];

   cin >> N;

   cin >> K;

   for (int i = 0; i < N; i++) {

      cin >> L[i];

   }

   qsort(L,N,sizeof (int), asc);

   for (int i = 0; i < N - K + 1; i++) {

      ans = MIN(ans, L[i+K-1] - L[i]);

   }

   cout << ans << endl;

  return 0;

}