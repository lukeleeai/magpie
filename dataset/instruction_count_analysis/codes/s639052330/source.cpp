#include <stdio.h>

#include <stdlib.h>



int main()

{

    int s[7]={1,3,5,7,8,10,12};

    int t[4]={4,6,9,11};

    int i,j,x,y,a,b;

    while(~scanf("%d %d",&x,&y))

    {

        a=0,b=0;

        for(i=0;i<7;i++)

        {

            if(x==s[i]||y==s[i])

            {

                a++;

            }

        }

        for(j=0;j<4;j++)

        {

            if(x==t[j]||y==t[j])

            {

                b++;

            }

        }

        if(a==2||b==2)

        {

            printf("Yes\n");

        }

        else if(x==y)

        {

            printf("Yes\n");

        }

        else

        {

            printf("No\n");

        }

    }

    return 0;

}
