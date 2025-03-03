#include<stdio.h>

int nixu (int x)

{

    int a=0;

    while(x>0)

    {

        a=a*10+x%10;

        x=x/10;

    }

    return a;

}

int main()

{

    int a,b,i;

    int sum=0;

    scanf("%d %d",&a,&b);

    for(i=a;i<=b;i++)

    {

        if(i==nixu(i))

            sum++;

    }



    printf("%d",sum);

    return 0;

}
