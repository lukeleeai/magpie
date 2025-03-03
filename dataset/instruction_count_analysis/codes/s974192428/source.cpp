#include<stdio.h>

int main()

{

    int n[5],i;

    for(i=1;i<=4;i++)

    scanf("%1d",&n[i]);

    if(n[1]==n[2]&&n[2]==n[3])

    {printf("Yes\n");

    return 0;}

    if(n[2]==n[3]&&n[3]==n[4])

    {printf("Yes\n");

    return 0;}

    printf("No\n");

    return 0;

}