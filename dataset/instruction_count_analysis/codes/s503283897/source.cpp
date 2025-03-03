#include<stdio.h>

#include<math.h>

int main()

{

    long long int a, b, i, p, q, count = 0;

    scanf("%lld%lld", &a, &b);

    for (i=0; i<a; i++){

        scanf("%lld%lld", &p, &q);

        if ((double)(sqrt(pow(p,2)+pow(q,2))) <= b) count ++;

    }

    printf("%lld\n", count);

    return 0;

}
