#include<stdio.h>

#include<stdlib.h>

int main()

{

    int a,b,c,d,t;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    if(abs(c-a)<=d)

    {

        t=1;

    }

    else if(abs(a-b)<=d)

    {

        if(abs(b-c)<=d)

            t=1;

            else t=0;

    }

    else t=0;

    if(t==1)

        printf("Yes");

    else printf("No");

    return 0;

}
