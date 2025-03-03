#include<stdio.h>

#include<algorithm>

#define maxn 200005

#define inf 0x3f3f3f3f

using namespace std;

typedef long int ll;

bool prime[60000];

int ans[60000], p;

int main()

{

    for (int i = 2; i < 60000; ++i){

        if (!prime[i]) for (int j = 2; j * i < 60000; ++j) prime[j * i] = 1;

    }

    int n;

    scanf("%d", &n);

    for (int i = 2; i <= 55555; ++i) if (!prime[i] && i % 5 == 1) ans[++p] = i;

    for (int i = 1; i < n; ++i) printf("%d ", ans[i]);

    printf("%d\n", ans[n]);

    return 0;

}
