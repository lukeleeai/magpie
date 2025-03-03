#include<stdio.h>

#include<algorithm>



int main()

{

    int n,x,y,t,xx = 0,yy = 0,tt = 0,flag = 1;

    scanf("%d",&n);

    while(n--)

    {

        scanf("%d%d%d",&t,&x,&y);

        if(abs(x-xx)+abs(y-yy)>(t-tt) || (abs(x-xx)+abs(y-yy))%2 != (t-tt)%2)

            flag = 0;

        xx = x;

        yy = y;

        tt = t;

    }

    if(flag)

        printf("Yes\n");

    else

        printf("No\n");



    return 0;

}