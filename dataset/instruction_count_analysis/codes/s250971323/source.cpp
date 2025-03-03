#include<cstdio>

using namespace std;

int main() {

  int flag = 1;

  int flag2 = 1;

  int ans = 0;

  int c;

  int n;

  while ((c = getchar_unlocked()) >= '0') {

    n = c - '0';

    flag2 = flag;

    if (n < 4) {

      if (flag == -1) {

        ans += n + 1;

      } else {

        ans += n;

      }

      flag = 1;

    }

    else if (n > 5) {

      if (flag == 1) {

        ans += 10 - n;

      }

      else {

        ans += 9 - n;

      }

      flag = -1;

    } else if (n == 4) {

      if (flag == -1) {

        flag = 0;

        ans += 5;

      }

      else {

        flag = 1;

        ans += 4;

      }

    } else if (n == 5) {

      if (flag == 1) {

        flag = 0;

        ans += 5;

      } else {

        flag = -1;

        ans += 4;

      }

    }

  }

  if (n > 5 || (n == 5 && flag2 != 1)){

    ++ans;

  }

  printf("%d\n", ans);

  return 0;

}

 