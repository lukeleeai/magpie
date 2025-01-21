/*

    数据量很小,直接模拟

    对最大的数-n,其他数+1,直到最大数都小于n

    问操作次数.

    数据量大时,二分也应该可以.

*/

#include<cstdio>

using namespace std;

typedef long long LL;

LL a[55];

int main(){

    LL n, ans = 0;

    scanf("%lld", &n);

    for (int i = 0; i < n;i++){

        scanf("%lld", a + i);

    }

    while(true){

        LL ma = a[0], pos = 0;

        for (int i = 1; i < n;i++){

            if(a[i]>ma){

                ma = a[i];

                pos = i;

            }

        }

        if(ma<n){

            break;

        }

        LL tmp = ma / n;

        a[pos] %= n;

        for (int i = 0; i < n;i++){

            a[i] += tmp;

        }

        a[pos] -= tmp;

        ans += tmp;

    }

    printf("%lld", ans);

    return 0;

}