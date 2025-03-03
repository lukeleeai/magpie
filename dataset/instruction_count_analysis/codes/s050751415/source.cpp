#include<stdio.h>

int main()

{

    int n,a,b;

    scanf("%d %d %d",&n,&a,&b);

    while(a<b && a,b>=0 && a,b<=n)

    {

        a++;

        if(a==b)

            {printf("Borys");

            break;

            }

        if(b-a ==1)

        {

            printf("Alice");

             break;

        }



        b--;



    }

    return 0;

}
