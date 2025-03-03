#include<cstdio>

using namespace std;



int p, a[3000], ans[3000];



int main() {

  scanf("%d", &p);

  for (int i = 0; i < p; i++) scanf("%d", &a[i]);

  ans[0] = a[0];

  for (int i = 0; i < p-1; i++) {

    for (int j = 0; j < p; j++) ans[p-1-i] += a[j], a[j] = (a[j] * j) % p;

    ans[p-1-i] = ans[p-1-i] % p * (p-1) % p;

  }

  for (int i = 0; i < p; i++) printf("%d%c", ans[i], (i == p-1) ? '\n' : ' ');

}
