#include<stdio.h>

#include<stdlib.h>



int main()

{

    double a, b, c, dif, d1, d2, d3, count=0;

    scanf("%lf%lf%lf%lf", &a, &b, &c, &dif);

    

    d1 = abs(a-c);

    d2 = abs(a-b);

    d3 = abs(b-c);

    

    if(d1<=dif)

        count=1;

    if(d2<=dif && d3<=dif)

        count=1;

    

    if(count==0)

        printf("No\n");

    else

        printf("Yes\n");

    

    return 0;

}