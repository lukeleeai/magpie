#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



const int MaxN = 100 + 5, MaxK = 100000 + 5;



int N, K;

int A[MaxN];

bool dp[MaxK];



void init() {

  scanf("%d %d", &N, &K);

  for (int i = 1; i <= N; ++i)

    scanf("%d", &A[i]);

}



void solve() {

  for (int i = 1; i <= K; ++i) {

    for (int j = 1; j <= N; ++j)

      if (i - A[j] >= 0) if (dp[i - A[j]] == false) dp[i] = true;

  }



  if (dp[K] == true) puts("First");

  else puts("Second");

}



int main() {

  init();

  solve();

  return 0;

}