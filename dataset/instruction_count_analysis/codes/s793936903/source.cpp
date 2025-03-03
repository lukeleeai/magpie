#include<stdio.h>

int main()

{

    int x,y;

    while(~scanf("%d%d",&x,&y))

    {

        int ans;

        ans=x-y;

        if(ans>0)

            printf("%d\n",ans);

        else

            printf("0\n");

    }

}