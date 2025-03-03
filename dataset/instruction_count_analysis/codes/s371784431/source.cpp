#include<cstdio>

#include<algorithm>

#include<cmath>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 7;

int a[maxn];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){

        scanf("%d", &a[i]);

        a[i] -= i;

    }

    sort(a+1, a+1+n);

    ll sum = 0;

    for(int i = 1; i <= n; ++i){

        sum += abs(a[i] - a[(n+1)/2]);

    }

    printf("%lld\n", sum);

}
