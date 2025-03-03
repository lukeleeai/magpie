#include <cstdio>

#include <cstdlib>



using namespace std;



const int N = 111111;



int a[N];

long long pre[N];

long long suf[N];



int main() {

  int n;

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {

    scanf("%d", &a[i]);

  }

  for (int i = 1; i <= n; ++i) {

    pre[i] = pre[i - 1] + abs(a[i - 1] - a[i]);

  }

  for (int i = n; i > 0; --i) {

    suf[i] = suf[i + 1] + abs(a[i + 1] - a[i]);

  }

  for (int i = 1; i <= n; ++i) {

    printf("%lld\n", pre[i - 1] + abs(a[i - 1] - a[i + 1]) + suf[i + 1]);

  }

  return 0; 

}