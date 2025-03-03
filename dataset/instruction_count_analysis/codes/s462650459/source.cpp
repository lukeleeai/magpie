#include "stdc++.h"

using namespace std;

const int N = 8010;

int a[N], b[N];

char lx[N];



void fail() {

  puts("No");

  exit(0);

}



int f[N];

void gao(int a[], int tot, int flg) {

  int sum = 0;

  if(tot >= 0) {

    for(int i = 1; i <= a[0]; ++i) sum += a[i];

    sum -= tot;

  } else {

    for(int i = 1; i <= a[0]; ++i) {

      if(i == 1) {

        if(flg) sum += a[i];

        else sum -= a[i];

      } else {

        sum -= a[i];

      }

    }

    sum = tot - sum;

  }

  if(sum < 0 || (sum & 1)) fail();

  sum /= 2;

  memset(f, 0, sizeof f);

  f[0] = 1;

  for(int i = 1; i <= a[0]; ++i) {

    if(flg && i == 1) continue;

    for(int j = sum; j >= a[i]; --j) {

      if(f[j - a[i]]) f[j] = 1;

    }

  }

  if(!f[sum]) fail();

}



int main() {

  int x, y;

  scanf("%s%d%d", lx + 1, &x, &y);

  int len = strlen(lx + 1), res = 0;

  int now = 1;

  for(int i = 1; i <= len; ++i) {

    if(lx[i] == 'F') res++;

    else {

      if(now) a[++a[0]] = res;

      else b[++b[0]] = res;

      now ^= 1;

      res = 0;

    }

  }

  if(res) {

    if(now) a[++a[0]] = res;

    else b[++b[0]] = res;

  }

/*  for(int i = 1; i <= a[0]; ++i)

    printf("%d ", a[i]);

  puts("");

  for(int i = 1; i <= b[0]; ++i) 

    printf("%d ", b[i]);

  puts("");*/

  gao(a, x, 1), gao(b, y, 0);

  puts("Yes");

  return 0;

}