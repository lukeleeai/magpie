#include <cstdio>

using namespace std;

int N, Q, l, r, sum[100000]; char S[100000];

int main() {

  scanf("%d %d %s", &N, &Q, &S);

  for(int i = 1; i < N; ++i) {

    sum[i] = sum[i-1]+(S[i-1]=='A'&&S[i]=='C');

  }

  for(int i = 0; i < Q; ++i) {

    scanf("%d %d", &l, &r);

    printf("%d\n", sum[r-1]-sum[l-1]);

  }

}