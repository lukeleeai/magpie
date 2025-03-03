#include "stdc++.h"



using namespace std;



int n;

int a[123];



int main() {

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {

    scanf("%d", &a[i]);

  }

  int ans = 0;

  int i = 0;

  while (i < n) {

    int j = i;

    while (j + 1 < n && a[i] == a[j + 1]) {

      j++;

    }

    ans += (j - i + 1) / 2;

    i = j + 1;

  }

  printf("%d\n", ans);

  return 0;

}