#include<stdio.h>

int main()

{

    int x,y,c;

    scanf("%d%d",&x,&y);

    if(x%2 != y%2)

    {

    printf("IMPOSSIBLE\n");

    }

    else

    {

        c=(x+y)/2;

        printf("%d",c);

    }

    return 0;

}