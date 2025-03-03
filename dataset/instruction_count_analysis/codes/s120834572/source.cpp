#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <algorithm>



#define MAX_N (100)

#define MAX_M (1000)

#define INF (1 << 29)



using namespace std;



// copy ans

int main(int argc, char *argv[]) {

  // read inputs

  int N, M, as[MAX_M], bs[MAX_M], cs[MAX_M];

  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++) {

    scanf("%d %d %d", &as[i], &bs[i], &cs[i]);

    as[i]--;  // NOTE : rewrite input

    bs[i]--;  // NOTE : rewrite input

  }



  // initialize distance matrix

  int distances[MAX_N][MAX_N];

  for (int i = 0; i < N; i++) {

    for (int j = 0; j < N; j++) {

      distances[i][j] = (i == j ? 0 : INF);

    }

  }

  for (int i = 0; i < M; i++) {

    const int a = as[i], b = bs[i], c = cs[i];

    distances[a][b] = c;

    distances[b][a] = c;

  }

  // warshall floyd

  for (int k = 0; k < N; k++) {

    for (int i = 0; i < N; i++) {

      for (int j = 0; j < N; j++) {

        distances[i][j] =

            min(distances[i][j], distances[i][k] + distances[k][j]);

      }

    }

  }

  // for (int i = 0; i < N; i++) {

  //   for (int j = 0; j < N; j++) {

  //     printf("%d ", distances[i][j]);

  //   }

  //   printf("\n");

  // }

  // count paths on shortest path

  int ans = 0;

  for (int i = 0; i < M; i++) {

    const int a = as[i], b = bs[i], c = cs[i];

    // (a, b) is used in a shortest path if and only if 

    // (a, b) is the shortest path between a and b

    ans += (distances[a][b] != c);

  }

  printf("%d\n", ans);



  return 0;

}
