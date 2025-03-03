#include<stdio.h>

#include<stdlib.h>

#include<math.h>



int main()

{

    int a,b,c,r,s,t,d,x=0,u;

    scanf("%d%d%d%d", &a,&b,&c,&d);

    r=abs(a-b);

    s=abs(b-c);

    u=abs(a-c);

    if(r<=d&&s<=d)

        x=1;

    else if(u<=d)

        x=1;

    if(x==1)

        printf("Yes\n");

    else

        printf("No\n");



    return 0;

}
