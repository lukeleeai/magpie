#include <stdio.h>



int H[100000];



int main(void) {

  int N;

  scanf("%d", &N);

  for (int i = 0; i < N;++i) {

    scanf("%d", H + i);

  }



  int ans = 0;

  int cnt = 0;

  for (int i = 0; i < N - 1; ++i) {

    if (H[i] >= H[i + 1]) {

      cnt++;

      if (ans < cnt)

        ans = cnt;

    } else {

      cnt = 0;

    }

  }

  printf("%d\n",ans);

}
