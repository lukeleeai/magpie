#include <stdio.h>

#include <algorithm>



using namespace std;



int x[100005], n;

long long ans = 0, a, b;



int main() {

    scanf("%d %lld %lld", &n, &a, &b);

    for(int i=0; i<n; i++) {

        scanf("%d", &x[i]);

    }

    for(int i=1; i<n; i++) {

        long long s = x[i-1], e = x[i];

        ans += min((e-s) * a, b);

    }

    printf("%lld\n", ans);

//    system("pause");

    return 0; 

}
