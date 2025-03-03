#include<stdio.h>

#include<stdlib.h>



int main()

{



    int a,  i, n;



    scanf("%d", &a);

    i=1;

    while((360*i)%a!=0)

    {

        i++;

    }

    n = (360*(i))/(a*1.0);

    printf("%d", n);



    return 0;

}
