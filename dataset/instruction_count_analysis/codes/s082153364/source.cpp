#include<stdio.h>

#include<stdlib.h>

#include<math.h>

int main()

{

    int a,x,y;

    scanf("%d",&a);

    x=a%10;

    y=a/10;

    if(x == 9 || y == 9)

    {

        printf("Yes\n");

    }

    else

        printf("No\n");

    return 0;

}
