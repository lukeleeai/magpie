#include "stdc++.h"



using namespace std;



int main()

{

  int N, M;

  int dp1[200000], dp2[200000];

  vector< int > line[100001];

  iota(dp1, dp1 + 200000, 0);

  iota(dp2, dp2 + 200000, 0);



  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++) {

    int a, b;

    scanf("%d %d", &a, &b);

    line[a].push_back(b);

  }

  for(int i = 0; i < 100001; i++) {

    for(auto& j : line[i]) {

      dp2[j - 1] = dp2[j];

      dp1[j] = dp1[j - 1];

    }

  }

  for(int i = 0; i < N; i++) {

    if(i > 0) putchar(' ');

    printf("%d", dp2[i] - dp1[i] + 1);

  }

  puts("");

}