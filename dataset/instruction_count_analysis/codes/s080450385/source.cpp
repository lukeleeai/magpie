#include<cstdio>

using namespace std;

int n, a, b, p;

int ans[1001010];

int x, y, r;

int cal(int x, int y){

    return (x+y-1) / y;

}

int main(){

    scanf("%d%d%d", &n, &a, &b);

    if(a == 1 && b != n){

        printf("-1");

        return 0;

    }

    if(b == 1 && a != n){

        printf("-1");

        return 0;

    }

    if(a == 1){

        for(int i = n; i >= 1; i --)

            printf("%d ", i);

        return 0;

    }

    if(b == 1){

        for(int i = 1; i <= n; i ++)

            printf("%d ", i);

        return 0;

    }

    if(a+b > n+1){

        printf("-1");

        return 0;

    }

    if(cal(n-a, b-1) > a){

        printf("-1");

        return 0;

    }

    int cnt = n - a;

    x = (cnt-b+1) / (a-1);

    y = (cnt-b+1) % (a-1);

    int r1, r2 = n - a;

    for(int i = cnt+1; i <= n; i ++){

        ans[++p] = i;

    }

    for(int i = 1; i <= x; i ++){

        r1 = r2 - a + 1;

        for(int j = r1; j <= r2; j ++){

            ans[++p] = j;

        }

        r2 -= a;

    }

    r1 = r2 - y;

    for(int i = r1; i <= r2; i ++)

        ans[++p] = i;

    for(int i = r1 - 1; i >= 0; i --)

        ans[++p] = i;

 

    for(int i = 1; i <= n; i ++)

        printf("%d ", ans[i]);

    return 0;

}