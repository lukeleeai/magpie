#include<cstdio>

const int maxn=1e5+7;

#define in(x) scanf("%d",&x)

int n,l,a[maxn];

int main() {



    in(n);

    in(l);

    for(int i = 1; i <= n; i++)in(a[i]);

    int j = 1;

    for(int i = 1; i < n; i++)if(a[i] + a[i + 1] > a[j] + a[j + 1])j = i;

    if(a[j] + a[j + 1] < l)puts("Impossible");

    else {

        puts("Possible");

        for(int i = n - 1; i > j; i--)printf("%d\n", i);

        for(int i = 1; i <= j; i++)printf("%d\n", i);

    }

    return 0;

}