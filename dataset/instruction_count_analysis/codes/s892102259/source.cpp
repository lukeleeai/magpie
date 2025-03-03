#include <cstdio>

#include <string>

#include <vector> 

using namespace std;



char S[100000+1];

int sum[100000+1];

int main() {

  int N, Q;

  scanf("%d %d %s", &N, &Q, S);

  for(int i = 1; i < N; i++)

    sum[i+1] = sum[i] + (S[i-1] == 'A' && S[i] == 'C');

  while(Q--) {

    int l, r;

    scanf("%d %d", &l, &r);

    printf("%d\n", sum[r] - sum[l]);

  }

  return 0;

}